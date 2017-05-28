#pragma once

#include "CImg.h"
#include "Section.h"

using namespace std;
using namespace cimg_library;


class Image
{
	// Toutes les images sont au format 250x340
	CImg<unsigned char> image_;		// Vignette de l'étudiant
	bool present_;					// TRUE si présent et FALSE si absent
	eleve eleveAssocie_;			// Pour accéder rapidement à l'élève à laquelle est associée la vignette
	int numeroImage_;				// Le numéro de l'image pour pouvoir la retrouver facilement (utile lors de l'actualisation de présence)
public:
	void modifierImage();			//  Actualise l'icône de présence (croix rouge ou V vert) en fonction du nouvel état de présence de l'étudiant
	Image(eleve& unEleve, int numeroImage);		// Construit la vignette de l'étudiant en positionant la photo, le nom, le prénom et l'icône de présence (présent par défaut)
	void actualisationAbsence();	// Actualise la valeur de present_ et lance modifierImage
	// Méthodes en ligne
	bool getPresence() { return present_; }
	eleve getEleve() { return eleveAssocie_; }
	CImg<unsigned char> getImage() { return image_; }
};

// Auteur : Aurélien TURPIN
