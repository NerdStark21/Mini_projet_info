#pragma once

#include <string>

using namespace std;

class eleve
{
	string nom_;
	string prenom_;
	char lettreGroupe_;			// Un seul caractere
	string photo_;				// L'adresse de la photo assici�e
public:
	eleve(string nom="", string prenom="", char lettreGroupe='A', string photo=""); // Constructeur basique pour d�finir les variables de la classe
	// M�thodes en ligne
	string getNom() { return nom_; }
	string getPrenom() { return prenom_; }
	char getNumeroGroupe() { return lettreGroupe_; }
	void getPhoto(string& photo) { photo = photo_; }
	string getPhoto() { return photo_; }
};