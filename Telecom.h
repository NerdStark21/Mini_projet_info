#pragma once

#include "Section.h"
#include <vector>


class telecom
{
	int nbrSections_;								     // Nombre de sections dans l'école
	std::vector<section> listeSections_;				// Vecteur des différentes sections
public :
	telecom(int nbrsections);
	int getNbrsections() { return nbrSections_; }
	void append(section uneSection) { listeSections_.push_back(uneSection); nbrSections_++; }
	section getSection(int numeroSection);
	void afficherToutLeMonde();
	section afficherSections();
};