#include "Section.h"
#include <iostream>

using namespace std;

section::section(int numero)
{
	// La liste des section sera construite au fur et à mesure
	numero_ = numero;
	nbrGroupe_ = 0;
}

void section::afficherToutLeMonde()
{
	cout << "Nombre de groupe : " << getNbrGroupe() << endl;
	for (int k = 0; k < getNbrGroupe(); k++)
	{
		groupe unGroupe = getGroupe(k);
		cout << "Groupe numéro " << k << endl;
		cout << "Nombre d'élèves : " << unGroupe.getNbrEleve() << endl;
		for (int h = 0; h < unGroupe.getNbrEleve(); h++)
		{
			eleve unEleve = unGroupe.getEleve(h);
			cout << unEleve.getNom() << " " << unEleve.getPrenom() << " ";
			cout << unEleve.getNumeroGroupe() << " " << unEleve.getPhoto();
			cout << endl;
		}
		cout << endl << endl;
	}
}

groupe section::getGroupe(int numeroGroupe)
{
	if (numeroGroupe >= 0 && numeroGroupe < nbrGroupe_)
		return listeGroupe_[numeroGroupe];
	else
	{
		cout << "Il y a un bug dans la matrice au niveau de la récupération des groupes" << endl;
		system("pause");
	}
}

int section::afficherGroupe()
{
	int numero;
	do
	{
		system("cls");
		cout << "Voici tous les groupes qui appartiennent à la section Fise1 :" << endl;
		cout << "0) Retour" << endl;
		for (int k = 0; k < getNbrGroupe(); k++)
		{
			groupe unGroupe = getGroupe(k);
			cout << k + 1 << ") Groupe " << unGroupe.getLettre() << endl;
		}
		cout << endl;
		cout << "De quel groupe voulez-vous faire l'appel ?" << endl;
		cout << ">>> ";
		cin >> numero;
	} while (numero < 0 || numero > getNbrGroupe());
	
	// Si return -1 => Retour
	return numero-1;
}
