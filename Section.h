#pragma once

#include "Groupe.h"

class section
{
	int numero_;
	int nbrGroupe_;
	std::vector<groupe> listeGroupe_;			// Nombre de groupe fixe ?
public:
	section(int numero);
	int getNumero() { return numero_; }
	void append(groupe& unGroupe) { listeGroupe_.push_back(unGroupe); nbrGroupe_++; }
	void afficherToutLeMonde();
	int getNbrGroupe() { return nbrGroupe_; }
	// l'on suppose que l'utilisateur va demander un numéro de groupe existant
	groupe getGroupe(int numeroGroupe);
	int afficherGroupe();
};