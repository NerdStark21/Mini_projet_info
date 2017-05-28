#pragma once

#include "Image.h"

using namespace cimg_library;
using namespace std;

class Page
{
	vector<Image> listImgEtudiant_;		// vector des images des étudiants (classe image)
	CImg<unsigned char> image_;			// Image de la page
	vector<eleve> listEleve_;
	int
		nbrEleve_,				// Nombre d'éléve contenu dans cette page (max 10)
		nbrPage_,				// Nombre de page totale (utile pour savoir si cette page est la dernière ou pas et ainsi mettre ou ne pas mettre les boutons "NEXT", "PREVIOUS" et/ou "END"
		numeroPage_;			// Numéro de la page (pour la distinguer des autres)
	void constructionImage();	// Constuit l'image en positionnant les unes à coté des autres les vignettes correspondant aux étudiants
	void appendImgEtudiant(Image& unEtudiant) { listImgEtudiant_.push_back(unEtudiant); }
public:
	Page(int numeroPage, vector<eleve> listEleve, int nbrPage);	// Le constructeur rempli le vecteur listImgEtudiant et lance tout de suite la construction de l'image de la page
	void actualiserPage(int numeroImage);						// Actualise la page pour mettre à jour les icônes de présence et d'absence des eleves lorsque l'utilisateur clique sur leur vignette
	// Méthodes en ligne
	CImg<unsigned char> getImage() { return image_; }
	Image getImgEleve(int k) { return listImgEtudiant_[k]; }
	int getNbrEleve() { return listEleve_.size(); }
	vector<eleve>& getListEleve() { return listEleve_; }
	vector<Image>& getListImgEtudiant() { return listImgEtudiant_; }
};