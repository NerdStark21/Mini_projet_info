#pragma once

#include "Section.h"
#include <vector>


class telecom
{
	int nbrSections_;								     // Nombre de sections dans l'�cole
	std::vector<section> listeSections_;
	void append(section uneSection) { listeSections_.push_back(uneSection); nbrSections_++; }				// Vecteur des diff�rentes sections
public :
	telecom(int nbrsections);
	int getNbrsections() { return nbrSections_; }
	std::vector<section> getListeSections(){ return listeSections_ ; }
	section getSection(int numeroSection);
	void afficherToutLeMonde();
	section afficherSections();
};