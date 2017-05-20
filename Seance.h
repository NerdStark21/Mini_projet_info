#pragma once

#include "Section.h"
#include "Page.h"
#include <fstream>

using namespace cimg_library;
using namespace std;

class Seance
{
	// Vecteurs de stockage
	vector<Page> listPage_;
	vector<eleve> listAbsent_;
	// Variables d'affichages
	CImg<unsigned char> imageBlank_;
	CImgDisplay disp_;
	// Autres
	int 
		pageActuelle_,
		nbrPresent_,
		nbrPage_;
	// Fonctions de navigation entre les pages
	void 
		pageWait(),
		afficherPageX(int numeroPage),
		afficherSuivante(),
		afficherPrecedente();
	// Fonctions de gestion des absents
	void
		testMouse(bool& next, bool& previous);
	int
		eleveSelectionne();
	void appendAbsent(int numeroEleve) { listAbsent_.push_back(listPage_[pageActuelle_].getListEleve()[numeroEleve]); }
	// Fonctions de fin d'appel
	void
		afficherEndPage(),
		sauvegarde();
public:
	Seance(groupe leGroupe, CImgDisplay& disp);
	~Seance();
};