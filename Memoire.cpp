#include <iostream>
#include "Memoire.h"
#include <fstream>
#include <string>
#include<locale>

using namespace std;

Memoire::Memoire(int numeroSeance)
{
	numeroSeance_ = numeroSeance;
}


int Memoire::calculNumeroSeance() 
{
	int i = 1;
	string nomSeance = "Fiche d'absence ";
	ifstream flux((nomSeance + "1.txt").c_str());
	while (!flux.fail())
	{
		i=i+1;
		string nombreChaine = to_string(i);
		flux=ifstream((nomSeance + nombreChaine + ".txt").c_str());
	}
	numeroSeance_ = i;
	return (i);
}


float Memoire::calculTauxAbsenteisme(float nbrAbsents, float totalEleves)
{
	tauxAbsenteisme_ = ((nbrAbsents / totalEleves) * 100);
	return tauxAbsenteisme_;
}


float Memoire::calculVariationAbsenteisme()
{
	string nombreChaine;
	string ligne;
	float tauxAbsentsPrecedent;
	nombreChaine = to_string(numeroSeance_-1);
	ifstream flux("Fiche d'absence " + nombreChaine + ".txt");

	for (int i = 1; i < 8; i++)
	{
		getline(flux, ligne);
	}
	getline(flux, ligne,':');
	flux >> tauxAbsentsPrecedent;

	variationAbsenteisme_ = ((tauxAbsenteisme_ - tauxAbsentsPrecedent) / tauxAbsentsPrecedent) * 100;
	return variationAbsenteisme_;
}


float Memoire::calculMoyenneAbsents(int nbrAbsents)
{
	string nombreChaine;
	string ligne;
	float moyenneAbsentsPrecedent;
	nombreChaine = to_string(numeroSeance_ - 1);
	ifstream flux("Fiche d'absence " + nombreChaine + ".txt");

	for (int i = 1; i < 10; i++)
	{
		getline(flux, ligne);
	}
	getline(flux, ligne, ':');
	flux >> moyenneAbsentsPrecedent;
	cout << moyenneAbsentsPrecedent << endl;
	cout << numeroSeance_ << endl;
	moyenneAbsents_ = (((moyenneAbsentsPrecedent*(numeroSeance_ - 1)) + nbrAbsents) / numeroSeance_);
	cout << moyenneAbsents_ << endl;
	return moyenneAbsents_;
}


float Memoire::calculMoyenneTaux()
{
	string nombreChaine;
	string ligne;
	float moyenneTauxPrecedent;
	nombreChaine = to_string(numeroSeance_ - 1);
	ifstream flux("Fiche d'absence " + nombreChaine + ".txt");

	for (int i = 1; i < 11; i++)
	{
		getline(flux, ligne);
	}
	getline(flux, ligne, ':');
	flux >> moyenneTauxPrecedent;

	moyenneTaux_=(((moyenneTauxPrecedent*(numeroSeance_ - 1)) + tauxAbsenteisme_) / numeroSeance_);
	return moyenneTaux_;
}