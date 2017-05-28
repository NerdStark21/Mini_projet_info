#pragma once

#include "CImg.h"
#include "Section.h"

using namespace std;
using namespace cimg_library;


class Image
{
	// Toutes les images sont au format 250x340
	CImg<unsigned char> image_;		// Vignette de l'�tudiant
	bool present_;					// TRUE si pr�sent et FALSE si absent
	eleve eleveAssocie_;			// Pour acc�der rapidement � l'�l�ve � laquelle est associ�e la vignette
	int numeroImage_;				// Le num�ro de l'image pour pouvoir la retrouver facilement (utile lors de l'actualisation de pr�sence)
public:
	void modifierImage();			//  Actualise l'ic�ne de pr�sence (croix rouge ou V vert) en fonction du nouvel �tat de pr�sence de l'�tudiant
	Image(eleve& unEleve, int numeroImage);		// Construit la vignette de l'�tudiant en positionant la photo, le nom, le pr�nom et l'ic�ne de pr�sence (pr�sent par d�faut)
	void actualisationAbsence();	// Actualise la valeur de present_ et lance modifierImage
	// M�thodes en ligne
	bool getPresence() { return present_; }
	eleve getEleve() { return eleveAssocie_; }
	CImg<unsigned char> getImage() { return image_; }
};