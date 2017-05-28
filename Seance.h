#pragma once

#include "Page.h"
#include <fstream>

using namespace cimg_library;
using namespace std;



class Seance
{
	// Vecteurs de stockage des pages composant la s�ance
	vector<Page> listPage_;

	// Variables d'affichages
	CImg<unsigned char> imageBlank_;	// Image blanche qui sert de fond � ins�rer entre chaque changement d'image pour �viter leur superposition
	CImgDisplay disp_;					// Classe pour le fenetre d'affichage
	// Autres
	int 
		pageActuelle_,					// Num�ro de la page actuelle, tr�s utile pour savoir � quelle page on est
		nbrPage_;						// Le nombre de page de la s�ance (souvent 2 ou 3, parce qu'il y a au max 10 �tudiants par page)
	
	// Fonctions de gestion des absents
	void
		testMouse(bool& next, bool& previous, bool& end, bool& actualisation);
		// Permet de savoir si l'utilisateur a cliqu� sur un bouton (et sur quel bouton) ou sur un eleve
	int
		eleveSelectionne(int mouseX, int mouseY);
		// SI l'utilisateur a cliqu� sur un �tudiant, cette fonction renvoie le num�ro de cet �tudiant

	
public:
	Seance(groupe leGroupe, CImgDisplay& disp);			// Constructeur qui d�finit le nombre de page minimum pour afficher tous les �tudiants du groupe � raison de 10 �tudiants max par page et initie le constructeur de ces pages
	void actualiserPresence(int numeroEleve);			// Actualise la pr�sence de l'�l�ve en executant la fonction d'actualisation de la pr�sence de la classe Page
	vector<eleve> getAbsent();							// Recup�re la liste des eleves absent en parcourant les eleves de toutes les pages et en c�rifiant leur �tat de pr�sence
	vector<Page>& getListPage() { return listPage_; }	// Recup�re une r�f�rence du vecteur de page contenu dans cette s�ance
	
	// Fonctions de fin d'appel
	void
		afficherEndPage(),								// Affiche la page de fin
		sauvegarde();									// Permet de sauvegarder les absents de la s�ance , les statistiques de la s�ance et les statistiques de toutes les s�ances
	
	// Fonctions de navigation entre les pages
	void
		afficherPageX(int numeroPage),					// Affiche la page num�ro X
		afficherSuivante(),								// Incr�mente la variable pageActuelle_ et lance la m�thode afficherPageX avec pageActuelle_ en param�tre
		afficherPrecedente();							// D�cremente la variable pageActuelle_ et lance la m�thode afficherPageX avec pageActuelle_ en param�tre
	int pageWait();										// D�finit si l'utilisateur a cliqu� sur "NEXT", "PREVIOUS", "END" ou s'il a actualis� l'�tat de pr�sence d'un �tudiant
	void launcher();									// Eberge la boucle infini qui permet � l'utilisateur de changer de page � volont�, initialement nous l'avions mise dans la fonction pageWait mais se posait alors le probl�me d'appel recursif de la fonction pageWait par elle-m�me � chaque fois que l'on voulait changer de page ce qui entrainait autant d'appel au destructeur que de changement de page => sous-optimisation
};