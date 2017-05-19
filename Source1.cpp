#include "CImg.h"
#include <iostream>
#include <fstream>
#include <string>
#include<locale>// Pour faire afficher les accents
#include "Telecom.h"

using namespace std;
using namespace cimg_library;

/*
section initialisation()
{
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

		return Fise1; // On retourne la Fise1 pour pouvoir l'utiliser dans le main (sinon elle est détruite lorsqu'on sort de la fonction d'initialisation
	}
	else
		cout << "Il y a une erreur dans la matrice au niveau de l'ouverture de Fise1.txt pour l'initialisation" << endl;
}
*/

groupe afficherMenu(section Fise)
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
	return Fise.afficherGroupe();
}

void affichage(section Fise1)
{
	// Usefull colors
	unsigned char
		grid_color[3] = { 0,0,255 },
		play1_color[3] = { 204,0,0 },
		play2_color[3] = { 0,102,0 };

	// Declare an image to draw the grid
	CImg<unsigned char> grid(500, 500, 1, 3, 255); // longueur, largueur
	// Declare an image
	CImg<unsigned char> image1, image2;
	// Load an image file into it
	image1.load("img-001.ppm");
	image2.load("img-002.ppm");
	grid.draw_image(image1);
	//grid.draw_image(image2, 50);

	// Declare a display to draw the scene
	CImgDisplay disp(grid, "Tic-tac-toe", 0, false, false);

	// Center the window on the screen
	disp.move((CImgDisplay::screen_width() - disp.width()) / 2,
		(CImgDisplay::screen_height() - disp.height()) / 2);

	// Declare an image to display the scene
	CImg<unsigned char> scene = grid;

	// Usefull variables
	int player = 1;
	int table[3][3] = { 0,0,0,0,0,0,0,0,0 };

	// Main loop, exit if the display window is closed or if ESC or Q key is hit
	while (!disp.is_closed() && !disp.is_keyESC() && !disp.is_keyQ()) {

		// Display the scene
		scene.display(disp);

		disp.wait();

		// Handle window resize
		if (disp.is_resized()) disp.resize();
	}
}

int main()
{
	cout << "###   Initialisation terminée   ###" << endl;
	//section Fise1 = initialisation();
	//Fise1.afficherToutLeMonde();	// Pour vérifier que tout le mode est bien dedans

	telecom tse(3);
	section Fise1 = tse.afficherSections();
	// Retourne directement le groupe selectionné par l'utilisateur
	//groupe selectionUt = afficherMenu(Fise1);
	//cout << "Nous avons bien recupéré le groupe que vous avez sélectionné =)" << endl;

	//affichage(initialisation());

	return 0;
}