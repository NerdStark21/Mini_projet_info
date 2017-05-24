#pragma once

#include "CImg.h"
#include "Section.h"

using namespace std;
using namespace cimg_library;


class Image
{
	// Toutes les images sont de format 250x340
	CImg<unsigned char> image_;
	// TRUE si présent et FALSE si absent
	bool present_;
	eleve* eleveAssocie_p_;
	int numeroImage_;
public:
	void modifierImage();
	Image(eleve& unEleve, int numeroImage);
	CImg<unsigned char> getImage() {return image_; }
	eleve* getEleve() { return eleveAssocie_p_; }
	void actualisationAbsence();
	bool getPresence(){ return present_ ; }
};