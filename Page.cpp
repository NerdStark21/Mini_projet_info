#include <iostream>
#include "Page.h"
#include "Seance.h"

#define largueur_fenetre 1250
#define hauteur_fenetre 700
#define largueur_image 240
#define hauteur_image 340
#define taille_check 50

using namespace std;
using namespace cimg_library;

Page::Page(int numeroPage, vector<eleve> listEleve, int nbrPage)
{
	nbrPage_ = nbrPage;
	// On initialise l'image comme étant une image blanche (RVB)
	CImg<unsigned char> image(1260, 700, 1, 3, 255);
	image_ = image;
	// le nombre d'élèves de la séance correspond au nombre d'élèves du groupe
	nbrEleve_ = listEleve.size();
	numeroPage_ = numeroPage;
	listEleve_ = listEleve;
	for (int k = 0; k < nbrEleve_; k++)
	{
		Image imgEtudiant(listEleve_[k], k);
		appendImgEtudiant(imgEtudiant);
	}
	// On initie tout de suite le construction de l'image du groupe donné
	Page::constructionImage();
}

void Page::actualiserPage(int numeroImage)
{
	listImgEtudiant_[numeroImage].actualisationAbsence();
	listImgEtudiant_[numeroImage].modifierImage();
	//CImgDisplay disp;
	//listImgEtudiant_[numeroImage].getImage().display(disp);
	//disp.wait(3000);
	if (numeroImage < 5)
		// On positionne d'abord l'image
		image_.draw_image(largueur_image * numeroImage, listImgEtudiant_[numeroImage].getImage());
	else
		image_.draw_image(largueur_image * (numeroImage - 5), hauteur_image, listImgEtudiant_[numeroImage].getImage());
}

void Page::constructionImage()
{
	for (int k = 0; k < nbrEleve_; k++)
	{
		// On affiche que 5 images par ligne
		if (k < 5)
			// On positionne d'abord l'image
			image_.draw_image(largueur_image * k, 0, listImgEtudiant_[k].getImage());
		else
			image_.draw_image(largueur_image * (k - 5), hauteur_image, listImgEtudiant_[k].getImage());
	}
	cout << "Page n= " << numeroPage_ << endl;
	cout << "Il y a " << nbrPage_ << " pages." << endl;
	if (numeroPage_ < nbrPage_ - 1)
	{
		// Bouton NEXT si on est pas à la dernière page
		image_.draw_text(largueur_fenetre - 50, hauteur_fenetre - 30, "NEXT >>>", "texte");
		unsigned char grid_color[3] = { 0, 0, 0 };
		image_.draw_rectangle(largueur_fenetre - 70, hauteur_fenetre - 30, largueur_fenetre, hauteur_fenetre - 15, grid_color, 0.2);
	}
	if (numeroPage_ == nbrPage_ - 1)
	{
		// Bouton END si on est à la dernière page
		image_.draw_text(1200, 670, "END >>>", "texte");
		unsigned char grid_color[3] = { 0, 0, 0 };
		image_.draw_rectangle(largueur_fenetre - 70, hauteur_fenetre - 30, largueur_fenetre, hauteur_fenetre - 15, grid_color, 0.2);
	}
	if (numeroPage_ > 0)
	{
		// Bouton PREVIOUS si on est pas à la première page
		image_.draw_text(0, hauteur_fenetre - 30, "<<< PREVIOUS", "texte");
		unsigned char grid_color[3] = { 0, 0, 0 };
		image_.draw_rectangle(0, hauteur_fenetre - 30, 80, hauteur_fenetre - 20, grid_color, 0.2);
	}
}
