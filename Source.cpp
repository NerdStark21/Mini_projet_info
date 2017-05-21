#include "Section.h"
#include "CImg.h"
#include "Page.h"
#include <iostream>
#include <fstream>
#include <string>
#include<locale>	// Pour faire afficher les accents

using namespace std;
using namespace cimg_library;

section initialisation()
{
	setlocale(LC_CTYPE, "fra");	// Pour faire afficher les accents

	ifstream flux("Fise1.txt");
	string varNom, varPrenom, varGroupe, varPhoto;
	char numeroGroupe;

	// On cr�e la Fise1 et son pointeur
	section Fise1(1);
	// On cr�e les 5 groupes
	groupe groupeA('A'), groupeB('B'), groupeC('C'), groupeD('D'), groupeE('E');

	if (flux.is_open())
	{
		while (!flux.eof())	// tant que l'on n'est pas � la fin du fichier
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

		return Fise1; // On retourne la Fise1 pour pouvoir l'utiliser dans le main (sinon elle est d�truite lorsqu'on sort de la fonction d'initialisation
	}
	else
		cout << "Il y a une erreur dans la matrice au niveau de l'ouverture de Fise1.txt pour l'initialisation" << endl;
}

groupe afficherMenu(section Fise)
{
	int numero;
	do
	{
		system("cls");	// Pour effacer tout ce qui �tait �crit dans la console de commande
		cout << "Voici toutes les sections disponibles :" << endl;
		cout << "1) Fise1" << endl;
		cout << "2) Fise2 (� venir)" << endl;
		cout << "3) Fise3 (� venir)" << endl;
		cout << endl;
		cout << "Veuillez entrer le numero de la section que vous voulez selectionner :" << endl;
		cout << ">>> ";
		cin >> numero;
	} while (numero != 1);
	return Fise.afficherGroupe();
}

int main()
{
	cout << "###   Initialisation termin�e   ###" << endl;
	//section Fise1 = initialisation();
	//Fise1.afficherToutLeMonde();	// Pour v�rifier que tout le mode est bien dedans

	// Retourne directement le groupe selectionn� par l'utilisateur
	//groupe selectionUt = afficherMenu(Fise1);
	//cout << "Nous avons bien recup�r� le groupe que vous avez s�lectionn� =)" << endl;

	test(afficherMenu(initialisation()));

	return 0;
}