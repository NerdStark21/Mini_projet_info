#include "Groupe.h"
#include <iostream>

using namespace std;

groupe::groupe(char lettre)
{
	// On va rajouter les eleves au fur et � mesure
	lettre_ = lettre;
	nbrEleve_ = 0;
}

eleve groupe::getEleve(int numeroEleve)
{
	if (numeroEleve >= 0 && numeroEleve < nbrEleve_)
		return listeEleve_[numeroEleve];
	else
	{
		cout << "Il y a un bug dans la matrice dans la r�sup�ration d'�l�ves" << endl;
		system("pause");
	}
}

