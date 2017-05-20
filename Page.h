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
	CImg<unsigned char> image_;
	vector<eleve> listEleve_;
	int
		nbrEleve_,
		nbrPage_,
		numeroPage_;
	void constructionImage();
public:
	Page(int numeroPage, vector<eleve>& listEleve, int nbrPage);
	CImg<unsigned char> getImage() { return image_; }
	vector<eleve>& getListEleve() { return listEleve_; }
};