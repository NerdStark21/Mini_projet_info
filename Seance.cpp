#include <iostream>
#include "Seance.h"

using namespace std;
using namespace cimg_library;

void Seance::pageWait()
{
	bool next = FALSE;
	bool previous = FALSE;
	disp_.wait(1000);
	while (disp_.button() != 0x1 || (!next && !previous))
	{
		// Si l'on clique sur l'image en bas à gauche
		int mouseX = disp_.mouse_x();
		int mouseY = disp_.mouse_y();
		if (mouseX > 1200 && mouseX < 1250 && mouseY>670 && mouseY < 680)
		{
			next = TRUE;
		}
		if (mouseX > 0 && mouseX < 50 && mouseY>670 && mouseY < 680 && pageActuelle_ > 0)
		{
			previous = TRUE;
		}
		else
			disp_.wait();
	}
	if (previous)
	{
		disp_.wait(500);
		afficherPrecedente();
	}
	if (next)
	{
		disp_.wait(500);
		imageBlank_.display(disp_);
		afficherSuivante();
	}
}

Seance::Seance(groupe leGroupe, CImgDisplay& disp)
{
	CImg<unsigned char> image(1250, 700, 1, 3, 255);
	imageBlank_ = image;
	pageActuelle_ = -1;
	disp_ = disp;
	int intermediaire = leGroupe.getNbrEleve() / 10;
	if (intermediaire * 10 == leGroupe.getNbrEleve())
		nbrPage_ = intermediaire;
	else
		nbrPage_ = intermediaire + 1;

	int max = 0;
	vector<eleve> liste;

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
		appendImage(unePage.getImage());
		cout << "Une image ajoutée" << endl;
	}
}

void Seance::afficherPageX(int numeroPage)
{
	cout << "Il y a " << nbrPage_ << " pages en tout." << endl;
	cout << "Vous avez demandé à afficher la page n= " << numeroPage << endl;
	if (numeroPage >= 0 && numeroPage < nbrPage_)
	{
		imageBlank_.display(disp_);
		listImage_[numeroPage].display(disp_);
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
