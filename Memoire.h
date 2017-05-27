#pragma once
#include "Telecom.h"
#include <fstream>


class Memoire
{
	int numeroSeance_; // Num�ro de la s�ance actuelle.
	//vector<ifstream> seancesPrecedentes_; // Vecteur de flux de lecture allant vers les fichiers .txt des s�ances pr�c�dentes.

	float tauxAbsenteisme_; // Taux d'absent�isme � la s�ance actuelle. (en %)
	float variationAbsenteisme_;  // Variation de l'Absent�isme par rapport � la s�ance pr�c�dente. (en %)
	float moyenneAbsents_; // Moyenne du nombre d'absents de toutes les s�ances effectu�es. (en nombre d'�l�ves)
	float moyenneTaux_; // Moyenne des taux d'absent�isme de toutes les s�ances effectu�es. (en %)
	
    public :
		Memoire(int numeroSeance);

		int getNumeroSeance() { return numeroSeance_; }
		//vector<ifstream> getSeancesPrecedentes() {return seancesPrecedentes_;}

		float getTauxAbsenteisme() { return tauxAbsenteisme_ ; }
		float getVariationAbsenteisme() { return variationAbsenteisme_; }
		float getMoyenneAbsents() { return moyenneAbsents_ ; }
		float getMoyenneTaux() { return moyenneTaux_ ; }



		void setTauxAbsenteisme(float tauxAbsenteisme) {tauxAbsenteisme_= tauxAbsenteisme;}
		void setVariationAbsenteisme(float variationAbsenteisme) {variationAbsenteisme_= variationAbsenteisme; }
		void setMoyenneAbsents(float moyenneAbsents) {moyenneAbsents_= moyenneAbsents; }
		void setMoyenneTaux(float moyenneTaux) {moyenneTaux_=moyenneTaux; }


		int calculNumeroSeance();
		float calculTauxAbsenteisme(float nbrAbsents, float totalEleves);
		float calculVariationAbsenteisme();
		float calculMoyenneAbsents(int nbrAbsents);
		float calculMoyenneTaux();

};