#pragma once

#include "Page.h"
#include <fstream>

using namespace cimg_library;
using namespace std;



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
	
	// Fonctions de gestion des absents
	void
		testMouse(bool& next, bool& previous, bool& end, bool& actualisation);
	int
		eleveSelectionne(int mouseX, int mouseY);

	
public:
	Seance(groupe leGroupe, CImgDisplay& disp);
	void actualiserPresence(int numeroEleve);
	vector<eleve> getAbsent();
	vector<Page>& getListPage() { return listPage_; }
	~Seance();
	// Fonctions de fin d'appel
	void
		afficherEndPage(),
		sauvegarde();
	// Fonctions de navigation entre les pages
	void
		afficherPageX(int numeroPage),
		afficherSuivante(),
		afficherPrecedente();
	int pageWait();
	void launcher();
};

// Auteur : Aurélien TURPIN et Raphaël BOULANGER
