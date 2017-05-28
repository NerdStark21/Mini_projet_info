#pragma once

#include <string>

using namespace std;

class eleve
{
	string nom_;
	string prenom_;
	char lettreGroupe_;		// Un seul caractere
	string photo_;		// Le nom de la photo associée
public:
	eleve(string nom, string prenom, char lettreGroupe, string photo);
	string getNom() { return nom_; }
	string getPrenom() { return prenom_; }
	char getNumeroGroupe() { return lettreGroupe_; }
	void getPhoto(string& photo) { photo = photo_; }
	string getPhoto() { return photo_; }
};

// Auteur : Aurélien TURPIN
