#pragma once

#include <string>

class eleve
{
	std::string nom_;
	std::string prenom_;
	char lettreGroupe_;		// Un seul caractere
	std::string photo_;					// Le nom de la photo associée
public:
	eleve(std::string nom, std::string prenom, char lettreGroupe, std::string photo);
	std:: string getNom() { return nom_; }
	std::string getPrenom() { return prenom_; }
	char getNumeroGroupe() { return lettreGroupe_; }
	std::string getPhoto() { return photo_; }
	void getPhoto(std::string& photo) { photo = photo_; }
};