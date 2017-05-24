#pragma once

#include "Page.h"
#include <fstream>

using namespace cimg_library;
using namespace std;

void test(groupe& leGroupe);

class Seance
{
	// Vecteurs de stockage
	vector<Page> listPage_;
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
		testMouse(bool& next, bool& previous, bool& end, bool& actualisation);
	int
		eleveSelectionne(int mouseX, int mouseY);
	// Fonctions de fin d'appel

public:
	Seance(groupe leGroupe, CImgDisplay& disp);
	void actualiserPresence(int numeroEleve);
	vector<eleve> getAbsent();
	vector<Page>& getListPage() { return listPage_; }
	~Seance();
	void
		afficherEndPage(),
		sauvegarde();
};