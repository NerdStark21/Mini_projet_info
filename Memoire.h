#pragma once
#include "Telecom.h"
#include <fstream>


class Memoire
{
	int numeroSeance_; // Numéro de la séance actuelle.
	//vector<ifstream> seancesPrecedentes_; // Vecteur de flux de lecture allant vers les fichiers .txt des séances précédentes.

	float tauxAbsenteisme_; // Taux d'absentéisme à la séance actuelle. (en %)
	float variationAbsenteisme_;  // Variation de l'Absentéisme par rapport à la séance précédente. (en %)
	float moyenneAbsents_; // Moyenne du nombre d'absents de toutes les séances effectuées. (en nombre d'élèves)
	float moyenneTaux_; // Moyenne des taux d'absentéisme de toutes les séances effectuées. (en %)
	
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