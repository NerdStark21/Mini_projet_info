#pragma once

#include "Section.h"
#include <vector>

using namespace std;

class telecom
{
	int nbrSections_;  // Nombre de sections dans l'école.
	vector<section> listeSections_;	// Vecteur des différentes sections.
	void appendSection(section& uneSection) { listeSections_.push_back(uneSection); nbrSections_++; } // Pour rajouter une section dans le vecteur correspondant.
	int getNbrsections() { return nbrSections_; } // Retourne le nombre de sections.
public :
	telecom(int nbrSections); // Constructeur qui prend en paramètre le nombre de sections : construit aussi tous les objets Groupe et Section en allent chercher les informations dans Fise1.txt.
	section& getSection(int numeroSection); // Retourne la section correspondant au numéro indiqué en paramètre.
	void afficherToutLeMonde(); // Affiche toutes les sections : méthode utilisée uniquement pour faire des tests pendant la conception.
	vector<section> getListeSection() { return listeSections_; } // Retourne le vecteur contenant les sections.
	int afficherSections(); // Affiche le premier menu (avec les sections) dans une fenêtre console et renvoie le choix de section de l'utilisateur.
	groupe choixGroupe(); // Affiche le second menu (avec les groupes de la section choisie) et renvoie l'objet Groupe correspondant au choix de l'utilisateur.
};
