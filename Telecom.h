#pragma once

#include "Section.h"
#include <vector>


class telecom
{
	int nbrSections_;								     // Nombre de sections dans l'�cole
	std::vector<section> listeSections_;				// Vecteur des diff�rentes sections
public :
	telecom(int nbrsections);
	int getNbrsections() { return nbrSections_; }
	void append(section uneSection) { listeSections_.push_back(uneSection); nbrSections_++; }
	section getSection(int numeroSection);
	void afficherToutLeMonde();
	section afficherSections();
};