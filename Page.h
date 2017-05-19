#pragma once

#include "Section.h"
#include"CImg.h"

using namespace cimg_library;
using namespace std;

void affichageTest(groupe& leGroupe);
void affichageQuiMarche(groupe& leGroupe);
void test(groupe& leGroupe);

class Page
{
	int numeroPage_;
	CImg<unsigned char> image_;
	std::vector<eleve> listEleve_;
	void constructionImage();
	int nbrEleve_;
	int nbrPage_;
public:
	Page(int numeroPage, vector<eleve>& listEleve, int nbrPage);
	CImg<unsigned char> getImage() { return image_; }
};