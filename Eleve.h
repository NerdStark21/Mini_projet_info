#pragma once

#include <string>

using namespace std;

class eleve
{
	string nom_;
	string prenom_;
	char lettreGroupe_;		// Un seul caractere
	string photo_;		// Le nom de la photo associ�e
public:
	eleve(string nom="", string prenom="", char lettreGroupe='A', string photo="");
	string getNom() { return nom_; }
	string getPrenom() { return prenom_; }
	void setNom(string Nom) { nom_ = Nom; }
	void setPrenom(string Prenom) { prenom_=Prenom; }
	char getNumeroGroupe() { return lettreGroupe_; }
	void getPhoto(string& photo) { photo = photo_; }
	string getPhoto() { return photo_; }
};