#pragma once

#include "Section.h"
#include "Page.h"

using namespace cimg_library;
using namespace std;

class Seance
{
	vector<CImg<unsigned char>> listImage_;
	int nbrAbsent_;
	CImg<unsigned char> imageBlank_;
	int pageActuelle_;
	int nbrPresent_;
	int nbrPage_;
	CImgDisplay disp_;
	void pageWait();
	void appendImage(CImg<unsigned char> uneImage) { listImage_.push_back(uneImage); }
public:
	Seance(groupe leGroupe, CImgDisplay& disp);
	void afficherPageX(int numeroPage);
	void afficherSuivante();
	void afficherPrecedente();
};