#pragma once

#include "Eleve.h"
#include <vector>

using namespace std;

class groupe
{
	char lettre_;			//Uniquement une lettre
	vector<eleve> listeEleve_;
	int nbrEleve_;
public:
	groupe(char lettre);
	char getLettre() { return lettre_; }
	void appendEleve(eleve& unEleve) { listeEleve_.push_back(unEleve); nbrEleve_++; }
	int getNbrEleve() { return nbrEleve_; }
	eleve getEleve(int numeroEleve);
};

// Auteur : Aurélien TURPIN
