#pragma once

#include "Groupe.h"

using namespace std;

class section
{
	int numero_;						// Numero de la section (pour les distinguer et les appeler)
	int nbrGroupe_;						// Nombre de groupe présent dans cette section
	vector<groupe> listeGroupe_;		// vecteur des groupes composant la section
public:
	section(int numero);				// Le constructeur ne définie que numero_ et nbrGroupe_ = 0, la liste des sections sera construite au fur et à mesure
	void append(groupe& unGroupe) { listeGroupe_.push_back(unGroupe); nbrGroupe_++; }
	void afficherToutLeMonde();			// Permet d'afficher toute la promo (uniquement pour le déboggague)
	groupe getGroupe(int numeroGroupe);
	int afficherGroupe();				// Affiche le menu de choix de groupe une fois que l'on a selectionné la section, retourne ne numéro du groupe selectionné
	// Méthodes en ligne
	int getNbrGroupe() { return nbrGroupe_; }
	int getNumero() { return numero_; }
};