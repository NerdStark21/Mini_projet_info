#pragma once

#include "Image.h"

using namespace cimg_library;
using namespace std;

void affichageTest(groupe& leGroupe);
void affichageQuiMarche(groupe& leGroupe);
void test(groupe& leGroupe);

class Page
{
	vector<Image> listImgEtudiant_;
	CImg<unsigned char> image_;
	vector<eleve> listEleve_;
	int
		nbrEleve_,
		nbrPage_,
		numeroPage_;
	void constructionImage();
	void appendImgEtudiant(Image& unEtudiant) { listImgEtudiant_.push_back(unEtudiant); }
public:
	Page(int numeroPage, vector<eleve>& listEleve, int nbrPage);
	CImg<unsigned char> getImage() { return image_; }
	Image getImgEleve(int k) { return listImgEtudiant_[k]; }
	int getNbrEleve() { return listEleve_.size(); }
	vector<eleve>& getListEleve() { return listEleve_; }
	vector<Image> getListImgEtudiant() { return listImgEtudiant_; }
	void actualiserPage(int numeroImage);
};