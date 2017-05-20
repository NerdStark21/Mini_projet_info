#include <iostream>
#include "Seance.h"

using namespace std;
using namespace cimg_library;

void Seance::pageWait()
{
	bool
		next = FALSE,
		previous = FALSE,
		end = FALSE;
	disp_.wait(1000);
	while (disp_.button() != 0x1 || (!next && !previous))
	{
		// Si l'on clique sur l'image en bas à gauche
		testMouse(next, previous);
	}
	if (previous)
	{
		disp_.wait(500);
		imageBlank_.display(disp_);
		afficherPrecedente();
	}
	if (next)
	{
		disp_.wait(500);
		imageBlank_.display(disp_);
		afficherSuivante();
	}
	if (end)
		afficherEndPage();
}

void Seance::testMouse(bool& next, bool& previous)
{
	int
		mouseX = disp_.mouse_x(),
		mouseY = disp_.mouse_y(),
		numeroeleve;
	if (mouseX > 1200 && mouseX < 1250 && mouseY>670 && mouseY < 680)
	{
		next = TRUE;
		if (pageActuelle_ == nbrPage_ - 1)
			next = FALSE;
	}
	if (mouseX > 0 && mouseX < 50 && mouseY>670 && mouseY < 680 && pageActuelle_ > 0)
		previous = TRUE;
	else
	{
		numeroeleve = eleveSelectionne();
		if (numeroeleve != -1)
		{
			appendAbsent(numeroeleve);
		}
		disp_.wait();
	}
}

int Seance::eleveSelectionne()
{
	int
		mouseX = disp_.mouse_x(),
		mouseY = disp_.mouse_y(),
		numeroeleve = -1;
	for (int ligne = 0; ligne < 2; ligne++)
	{
		for (int colonne = 0; colonne < 5; colonne++)
		{
			if (mouseX > 10 * (colonne + 1) + colonne * 240 && mouseX < 10 * (colonne + 1) + (colonne + 1) * 240
				&& mouseY > 260 * ligne && mouseY < 260 * ligne + 240)
			{
				numeroeleve = ligne * 5 + colonne;
			}
		}
	}
	return numeroeleve;
}

Seance::Seance(groupe leGroupe, CImgDisplay& disp)
{
	CImg<unsigned char> image(1250, 700, 1, 3, 255);
	vector<eleve> liste;
	imageBlank_ = image;
	pageActuelle_ = -1;
	disp_ = disp;
	int 
		intermediaire = leGroupe.getNbrEleve() / 10,
		max = 0;

	if (intermediaire * 10 == leGroupe.getNbrEleve())
		nbrPage_ = intermediaire;
	else
		nbrPage_ = intermediaire + 1;

	// On subdivise le groupe selectionné en groupe de 10 élèves
	// car on ne veut en afficher que 10 à la fois
	// Ces 10 élèves sont envoyés dans le constructeur de la classe Page
	// pour que l'on puisse en récupérer une image totalement construite
	// et prête à être utilisée
	for (int k = 0; k < 10 * (leGroupe.getNbrEleve() / 10 + 1); k += 10)
	{
		// ON réinitialise la liste pour ne pas reprendre les mêmes
		liste.clear();
		// Si il reste des groupes de 10 elèves à former
		if (k + 10 == 10 * (leGroupe.getNbrEleve() / 10 + 1))
			max = leGroupe.getNbrEleve();
		// Sinon on fait un groupe avec les restants
		else
			max = k + 10;
		for (int j = k; j < max; j++)
			liste.push_back(leGroupe.getEleve(j));
		// On construit un objet page
		Page unePage(k / 10, liste, nbrPage_);
		// On récupère l'image et on la stocke dans la classe séance
		listPage_.push_back(unePage);
		cout << "Une image ajoutée" << endl;
	}

	afficherPageX(0);
}

Seance::~Seance()
{
	cout << "Destruction initiée !" << endl;
	cout << "Sauvegarde en cours" << endl;
	sauvegarde();
	cout << "Sauvegarde effectuée" << endl;
	disp_.close();
	cout << "Destruction terminée" << endl;
}

void Seance::afficherPageX(int numeroPage)
{
	cout << "Il y a " << nbrPage_ << " pages en tout." << endl;
	cout << "Vous avez demandé à afficher la page n= " << numeroPage << endl;
	if (numeroPage >= 0 && numeroPage < nbrPage_)
	{
		imageBlank_.display(disp_);
		listPage_[numeroPage].getImage().display(disp_);
		pageActuelle_ = numeroPage;
		disp_.set_fullscreen(disp_.is_fullscreen());
		disp_.move(10, 40);
		pageWait();
	}
	else
	{
		cout << "Il y a un bug dans la matrice au niveau de l'affichage des pages !" << endl;
		system("pause");
	}
}

void Seance::afficherSuivante()
{
	if (pageActuelle_ == nbrPage_ - 1)
	{
		cout << ("Il n'y a pas de page suivante !") << endl;
		pageWait();
	}
	else
	{
		pageActuelle_++;
		afficherPageX(pageActuelle_);
	}
}

void Seance::afficherPrecedente()
{
	if (pageActuelle_ == 0)
	{
		cout << ("Il n'y a pas de page précédente !") << endl;
		pageWait();
	}
	else
	{
		pageActuelle_--;
		afficherPageX(pageActuelle_);
	}
}

void Seance::afficherEndPage()
{
	imageBlank_.display(disp_);
	imageBlank_.draw_text(500, 500, "END", "texte");
	disp_.wait(5000);
}

void Seance::sauvegarde()
{
	string nomSeance = "Seance1";
	ofstream flux(nomSeance+".txt");
	flux << "Recapitulatif de la seance 1" << endl;
	flux << "Il y a eu " << listAbsent_.size() << " absents." << endl;
}
