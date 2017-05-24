#pragma once

#include "Section.h"
#include <vector>

using namespace std;

class telecom
{
	int nbrSections_;							// Nombre de sections dans l'�cole
	vector<section> listeSections_;				// Vecteur des diff�rentes sections
	void appendSection(section& uneSection) { listeSections_.push_back(uneSection); nbrSections_++; }

	int getNbrsections() { return nbrSections_; }

public :
	telecom(int nbrSections);
	section& getSection(int numeroSection);
	void afficherToutLeMonde();
	vector<section> getListeSection() { return listeSections_; }
	section& afficherSections();
};