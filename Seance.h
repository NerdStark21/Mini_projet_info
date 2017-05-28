#pragma once

#include "Page.h"
#include <fstream>

using namespace cimg_library;
using namespace std;



class Seance
{
	// Vecteurs de stockage des pages composant la séance
	vector<Page> listPage_;

	// Variables d'affichages
	CImg<unsigned char> imageBlank_;	// Image blanche qui sert de fond à insérer entre chaque changement d'image pour éviter leur superposition
	CImgDisplay disp_;					// Classe pour le fenetre d'affichage
	// Autres
	int 
		pageActuelle_,					// Numéro de la page actuelle, trés utile pour savoir à quelle page on est
		nbrPage_;						// Le nombre de page de la séance (souvent 2 ou 3, parce qu'il y a au max 10 étudiants par page)
	
	// Fonctions de gestion des absents
	void
		testMouse(bool& next, bool& previous, bool& end, bool& actualisation);
		// Permet de savoir si l'utilisateur a cliqué sur un bouton (et sur quel bouton) ou sur un eleve
	int
		eleveSelectionne(int mouseX, int mouseY);
		// SI l'utilisateur a cliqué sur un étudiant, cette fonction renvoie le numéro de cet étudiant

	
public:
	Seance(groupe leGroupe, CImgDisplay& disp);			// Constructeur qui définit le nombre de page minimum pour afficher tous les étudiants du groupe à raison de 10 étudiants max par page et initie le constructeur de ces pages
	void actualiserPresence(int numeroEleve);			// Actualise la présence de l'élève en executant la fonction d'actualisation de la présence de la classe Page
	vector<eleve> getAbsent();							// Recupère la liste des eleves absent en parcourant les eleves de toutes les pages et en cérifiant leur état de présence
	vector<Page>& getListPage() { return listPage_; }	// Recupère une référence du vecteur de page contenu dans cette séance
	
	// Fonctions de fin d'appel
	void
		afficherEndPage(),								// Affiche la page de fin
		sauvegarde();									// Permet de sauvegarder les absents de la séance , les statistiques de la séance et les statistiques de toutes les séances
	
	// Fonctions de navigation entre les pages
	void
		afficherPageX(int numeroPage),					// Affiche la page numéro X
		afficherSuivante(),								// Incrémente la variable pageActuelle_ et lance la méthode afficherPageX avec pageActuelle_ en paramètre
		afficherPrecedente();							// Décremente la variable pageActuelle_ et lance la méthode afficherPageX avec pageActuelle_ en paramètre
	int pageWait();										// Définit si l'utilisateur a cliqué sur "NEXT", "PREVIOUS", "END" ou s'il a actualisé l'état de présence d'un étudiant
	void launcher();									// Eberge la boucle infini qui permet à l'utilisateur de changer de page à volonté, initialement nous l'avions mise dans la fonction pageWait mais se posait alors le problème d'appel recursif de la fonction pageWait par elle-même à chaque fois que l'on voulait changer de page ce qui entrainait autant d'appel au destructeur que de changement de page => sous-optimisation
};