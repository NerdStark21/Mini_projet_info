#include <iostream>
#include <fstream>
#include "Seance.h"

using namespace std;
using namespace cimg_library;

void test(groupe& leGroupe)
{
	CImgDisplay disp;

	Seance seance1(leGroupe, disp);

	seance1.afficherEndPage();
	seance1.sauvegarde();
}

void Seance::pageWait()
{
	bool
		next = FALSE,
		previous = FALSE,
		end = FALSE,
		actualisation = FALSE;

	while (disp_.button() == 1)
		disp_.wait();
	while (disp_.button() != 1 || (!next && !previous && !end && !actualisation))
	{
		// Si l'on clique
		if (disp_.button() == 1)
		{
			testMouse(next, previous, end, actualisation);
		}
		else
			disp_.wait();
		//disp_.wait(50);
	}
	if (previous)
	{
		//disp_.wait(500);
		imageBlank_.display(disp_);
		afficherPrecedente();
	}
	else if (next)
	{
		//disp_.wait(500);
		imageBlank_.display(disp_);
		afficherSuivante();
	}
	else if (end)
	{
		//afficherEndPage();
		//sauvegarde();
    }
	else if (actualisation)
	{
		afficherPageX(pageActuelle_);
	}
}

void Seance::testMouse(bool& next, bool& previous, bool& end, bool& actualisation)
{
	int
		mouseX = disp_.mouse_x(),
		mouseY = disp_.mouse_y(),
		numeroeleve;
	if (mouseX > 1200 && mouseX < 1250 && mouseY>670 && mouseY < 680)
	{
		next = TRUE;
		if (pageActuelle_ == nbrPage_ - 1)
		{
			next = FALSE;
			end = TRUE;
		}
	}
	else if (mouseX > 0 && mouseX < 50 && mouseY>670 && mouseY < 680 && pageActuelle_ > 0)
		previous = TRUE;
	else
	{
		numeroeleve = eleveSelectionne(mouseX, mouseY);
		cout << "numero eleve = " << numeroeleve << endl;
		if (numeroeleve != -1)
		{
			actualiserPresence(numeroeleve);
			actualisation = TRUE;
		}
	}
}

int Seance::eleveSelectionne(int mouseX, int mouseY)
{
	int
		numeroeleve = -1;
	for (int ligne = 0; ligne < 2; ligne++)
	{
		for (int colonne = 0; colonne < 5; colonne++)
		{
			if (mouseX > 10 * (colonne + 1) + colonne * 240 && mouseX < 10 * (colonne + 1) + (colonne + 1) * 240
				&& mouseY > 320 * ligne && mouseY < 340 * ligne + 360)
			{
				numeroeleve = ligne * 5 + colonne;
			}
		}
	}
	if (numeroeleve >= listPage_[pageActuelle_].getNbrEleve())
	{
		numeroeleve = -1;
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

void Seance::actualiserPresence(int numeroEleve)
{
	listPage_[pageActuelle_].actualiserPage(numeroEleve);
}

vector<eleve> Seance::getAbsent()
{
	vector<eleve> listAbsent;
	vector<Page> lesPage = getListPage();
	vector<Page>::iterator itPage;
	vector<Image> lesImages;
	vector<Image>::iterator itImage;
	eleve* unEleve;
	cout << "Définition des objets de getAbsent" << endl;

	for (itPage = lesPage.begin(); itPage != lesPage.end(); itPage++)
	{
		lesImages = (*itPage).getListImgEtudiant();
		cout << "Définition de lesImages" << endl;
		for (itImage = lesImages.begin(); itImage != lesImages.end(); itImage++)
		{
			if (!(*itImage).getPresence())
			{
				unEleve = (*itImage).getEleve();
				cout << "nom eleve : " << (*unEleve).getNom() << endl;
				listAbsent.push_back(*unEleve);
				cout << "pushback ok" << endl;
			}
		}
	}
	return listAbsent;
}

Seance::~Seance()
{
	cout << "Destruction initiée !" << endl;
	//afficherEndPage();
	//sauvegarde();
	disp_.close();
}

void Seance::afficherPageX(int numeroPage)
{
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
	imageBlank_.draw_text(500, 200, "La saisie des absents est terminée.", "texte");
	imageBlank_.display(disp_);
	disp_.wait();
}

void Seance::sauvegarde()
{
	string nomSeance = "Seance1";
	cout << "############################# SAUVEGARDE" << endl;
	ofstream flux(nomSeance+".txt");
	vector<eleve> absent = getAbsent();
	flux << "Recapitulatif de la seance 1" << endl << endl;
	cout << absent.size() << endl;
	flux << "Il y a eu " << absent.size() << " absents." << endl << endl;
	flux << "    Nom :    " << "    Prenom :    " << endl << endl;
	for (int i=0; i< absent.size();i++)
	{
		flux << (absent[i]).getNom() <<"        "<< absent[i].getPrenom() << endl << endl;
	}
}
