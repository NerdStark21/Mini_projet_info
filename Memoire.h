#pragma once
#include "Telecom.h"
#include <fstream>


class Memoire
{
	int numeroSeance_; // Numéro de la séance actuelle.

	float tauxAbsenteisme_;			// Taux d'absentéisme à la séance actuelle. (en %)
	float variationAbsenteisme_;	// Variation de l'Absentéisme par rapport à la séance précédente. (en %)
	float moyenneAbsents_;			// Moyenne du nombre d'absents de toutes les séances effectuées. (en nombre d'élèves)
	float moyenneTaux_;				// Moyenne des taux d'absentéisme de toutes les séances effectuées. (en %)
	
    public :
		Memoire(int numeroSeance); // Constructeur avec le numéro de la séance actuelle en paramètre.

		int getNumeroSeance() { return numeroSeance_; } // Récupère le numéro de la séance actuelle.

		float getTauxAbsenteisme() { return tauxAbsenteisme_ ; }			// Récupère le taux d'absentéisme de la séance actuelle.
		float getVariationAbsenteisme() { return variationAbsenteisme_; }	// Récupère la variation du taux d'absentéisme par rapport à la séance précédente.
		float getMoyenneAbsents() { return moyenneAbsents_ ; }				// Récupère la moyenne des absents sur toutes les séances.
		float getMoyenneTaux() { return moyenneTaux_ ; }					// Récupère le taux d'absentéisme moyen sur toutes les séances.

		// Les 4 méthodes suivantes permettent d'insérer une valeur dans le champ correspondant (utile pour traiter la première séance les champs qui dépendent des séances précédentes sont alors mis à zéro).

		void setTauxAbsenteisme(float tauxAbsenteisme) {tauxAbsenteisme_= tauxAbsenteisme;} 
		void setVariationAbsenteisme(float variationAbsenteisme) {variationAbsenteisme_= variationAbsenteisme; }
		void setMoyenneAbsents(float moyenneAbsents) {moyenneAbsents_= moyenneAbsents; }
		void setMoyenneTaux(float moyenneTaux) {moyenneTaux_=moyenneTaux; }

		// Ces 4 méthodes calculent les valeurs des champs correspondants en renvoyant le résultat ET en mettant la valeur dans le champ correspondant de l'objet Memoire.
	
		int calculNumeroSeance();											// Calcul le numéro de la séance actuelle en regardant quels fiches d'absence ont déjà été créées.
		float calculTauxAbsenteisme(float nbrAbsents, float totalEleves);	// Calcul le taux d'absentéisme (nbre d'Eleves / nbre total d'élèves du groupe).
		float calculVariationAbsenteisme();									// Calcule la variation du taux d'absentéisme en allant chercher le nbre d'élèves absents à la séance précédente dans la fiche d'absence précédente.
		float calculMoyenneAbsents(int nbrAbsents);							// Calcule la moyenne du nombre d'absents en allant chercher la moyenne du nombre d'absents dans la fiche d'absence précédente.
		float calculMoyenneTaux();											// Calcule la moyenne du taux d'absentéisme en allant chercher la moyenne du taux d'absentéisme dans la fiche d'absence précédente.
};

// Auteur : Raphaël Boulanger
