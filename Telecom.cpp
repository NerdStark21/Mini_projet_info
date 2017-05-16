#include <iostream>
#include "Telecom.h"
#include <fstream>
#include <string>
#include<locale>

using namespace std;


telecom::telecom(int nbrsections)
{
	nbrSections_ = nbrsections;

	setlocale(LC_CTYPE, "fra");	// Pour faire afficher les accents

	ifstream flux("Fise1.txt");
	string varNom, varPrenom, varGroupe, varPhoto;
	char numeroGroupe;

	// On crée la Fise1 et son pointeur
	section Fise1(1);
	//section* Fise1_p;
	//Fise1_p = &Fise1;
	// On crée les 5 groupes
	groupe groupeA('A'), groupeB('B'), groupeC('C'), groupeD('D'), groupeE('E');

	if (flux.is_open())
	{
		while (!flux.eof())	// tant que l'on n'est pas à la fin du fichier
		{
			getline(flux, varNom, ';');
			getline(flux, varPrenom, ';');
			getline(flux, varGroupe, ';');
			getline(flux, varPhoto);
			numeroGroupe = (char)varGroupe[0];
			eleve unEleve(varNom, varPrenom, numeroGroupe, varPhoto);
			switch (numeroGroupe)
			{
			case 'A':
				groupeA.appendEleve(unEleve);
				break;
			case 'B':
				groupeB.appendEleve(unEleve);
				break;
			case 'C':
				groupeC.appendEleve(unEleve);
				break;
			case 'D':
				groupeD.appendEleve(unEleve);
				break;
			case'E':
				groupeE.appendEleve(unEleve);
				break;
			default:
				cout << "Il y a un bug dans la matrice un niveau de l'attribution des eleves aux groupes dans le fonction d'initialisation" << endl;
			}
		}

		// On ajoute les 5 groupes dans la Fise1
		Fise1.append(groupeA);
		Fise1.append(groupeB);
		Fise1.append(groupeC);
		Fise1.append(groupeD);
		Fise1.append(groupeE);

		listeSections_.push_back(Fise1); // On retourne la Fise1 pour pouvoir l'utiliser dans le main (sinon elle est détruite lorsqu'on sort de la fonction d'initialisation
	}
	else
		cout << "Il y a une erreur dans la matrice au niveau de l'ouverture de Fise1.txt pour l'initialisation" << endl;
}


section telecom::getSection(int numeroSection)
{
	if (numeroSection >= 0 && numeroSection < nbrSections_)
		return listeSections_[numeroSection];
	else
	{
		cout << "Il y a un bug dans la matrice au niveau de la récupération des groupes" << endl;
		system("pause");
	}
}




void telecom::afficherToutLeMonde()
{
	int n = getNbrsections();

	for (int i = 0;i < n;i++)
	{
		cout << "Section : Fise" << i << " : " << endl;
		getSection(n).section::afficherToutLeMonde();
		cout << endl;
	}
}



section telecom::afficherSections()
{
	int numero;
	do
	{
		system("cls");	// Pour effacer tout ce qui était écrit dans la console de commande
		cout << "Voici toutes les sections disponibles :" << endl;
		cout << "1) Fise1" << endl;
		cout << "2) Fise2 (à venir)" << endl;
		cout << "3) Fise3 (à venir)" << endl;
		cout << endl;
		cout << "Veuillez entrer le numero de la section que vous voulez selectionner :" << endl;
		cout << ">>> ";
		cin >> numero;
	} while (numero != 1);
	listeSections_[1].afficherGroupe();
}