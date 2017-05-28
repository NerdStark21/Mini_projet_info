#pragma once

#include <string>

using namespace std;

class eleve
{
	string nom_;
	string prenom_;
	char lettreGroupe_;		// Un seul caractere
	string photo_;		// L'adresse de la photo associée
public:
	eleve(string nom="", string prenom="", char lettreGroupe='A', string photo=""); // Constructeur basique pour définir les variables de la classe
	// Méthodes en ligne
	string getNom() { return nom_; }
	string getPrenom() { return prenom_; }
	void setNom(string Nom) { nom_ = Nom; }
	void setPrenom(string Prenom) { prenom_=Prenom; }
	char getNumeroGroupe() { return lettreGroupe_; }
	void getPhoto(string& photo) { photo = photo_; }
	string getPhoto() { return photo_; }
};

// Auteur : Aurélien TURPIN
