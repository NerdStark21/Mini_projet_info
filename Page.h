#pragma once

#include "Image.h"

using namespace cimg_library;
using namespace std;

class Page
{
	vector<Image> listImgEtudiant_;		// vector des images des �tudiants (classe image)
	CImg<unsigned char> image_;			// Image de la page
	vector<eleve> listEleve_;
	int
		nbrEleve_,				// Nombre d'�l�ve contenu dans cette page (max 10)
		nbrPage_,				// Nombre de page totale (utile pour savoir si cette page est la derni�re ou pas et ainsi mettre ou ne pas mettre les boutons "NEXT", "PREVIOUS" et/ou "END"
		numeroPage_;			// Num�ro de la page (pour la distinguer des autres)
	void constructionImage();	// Constuit l'image en positionnant les unes � cot� des autres les vignettes correspondant aux �tudiants
	void appendImgEtudiant(Image& unEtudiant) { listImgEtudiant_.push_back(unEtudiant); }
public:
	Page(int numeroPage, vector<eleve> listEleve, int nbrPage);	// Le constructeur rempli le vecteur listImgEtudiant et lance tout de suite la construction de l'image de la page
	void actualiserPage(int numeroImage);						// Actualise la page pour mettre � jour les ic�nes de pr�sence et d'absence des eleves lorsque l'utilisateur clique sur leur vignette
	// M�thodes en ligne
	CImg<unsigned char> getImage() { return image_; }
	Image getImgEleve(int k) { return listImgEtudiant_[k]; }
	int getNbrEleve() { return listEleve_.size(); }
	vector<eleve>& getListEleve() { return listEleve_; }
	vector<Image>& getListImgEtudiant() { return listImgEtudiant_; }
};