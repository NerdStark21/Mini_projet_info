#include <iostream>
#include "Seance.h"
#include "Memoire.h"

#define largueur_fenetre 1250
#define hauteur_fenetre 700
#define largueur_image 240
#define hauteur_image 340
#define taille_check 50

using namespace std;
using namespace cimg_library;

void Seance::launcher()
{
	imageBlank_.display(disp_);
	afficherPageX(0);
	// 1 = next, 2 = previous, 3 = actualisation, 4 = end
	int wait = 1;

	while (wait > 0 && wait < 4)
	{
		wait = pageWait();
		
		switch (wait)
		{
		case 1:
			imageBlank_.display(disp_);
			afficherSuivante();
			break;
		case 2:
			imageBlank_.display(disp_);
			afficherPrecedente();
			break;
		case 3:
			afficherPageX(pageActuelle_);
			break;
		default:
			cout << "coucou" << endl;
		}
	}
	if (wait == 4)
	{
		afficherEndPage();
		sauvegarde();
	}
	else
		cout << "Erreur au niveau du launcher de seance" << endl;
}

int Seance::pageWait()
{
	bool
		next = FALSE,
		previous = FALSE,
		end = FALSE,
		actualisation = FALSE;

	while (disp_.button() == 1)
		disp_.wait();
	while (disp_.button() != 1 || (!next && !previous && !end && !actualisation))
	{
		// Si l'on clique
		if (disp_.button() == 1)
			testMouse(next, previous, end, actualisation);
		else
			disp_.wait();
		//disp_.wait(50);
	}
	if (next)
		return 1;
	else if (previous)
		return 2;
	else if (actualisation)
		return 3;
	else if (end)
		return 4;
	else
		return -1;
}

void Seance::testMouse(bool& next, bool& previous, bool& end, bool& actualisation)
{
	int
		mouseX = disp_.mouse_x(),
		mouseY = disp_.mouse_y(),
		numeroeleve;
	if (mouseX > largueur_fenetre - 50 && mouseX < largueur_fenetre && mouseY > hauteur_fenetre - 30 && mouseY < hauteur_fenetre - 20)
	{
		next = TRUE;
		if (pageActuelle_ == nbrPage_ - 1)
		{
			next = FALSE;
			end = TRUE;
		}
	}
	else if (mouseX > 0 && mouseX < 50 && mouseY > hauteur_fenetre - 30 && mouseY < hauteur_fenetre - 20 && pageActuelle_ > 0)
		previous = TRUE;
	else
	{
		numeroeleve = eleveSelectionne(mouseX, mouseY);
		cout << "numero eleve = " << numeroeleve << endl;
		if (numeroeleve != -1)
		{
			actualiserPresence(numeroeleve);
			actualisation = TRUE;
		}
	}
}

int Seance::eleveSelectionne(int mouseX, int mouseY)
{
	int
		numeroeleve = -1;
	for (int ligne = 0; ligne < 2; ligne++)
		for (int colonne = 0; colonne < 5; colonne++)
			if (mouseX > 10 * (colonne + 1) + colonne * (largueur_image - 10) && mouseX < 10 * (colonne + 1) + (colonne + 1) * (largueur_image - 10)
				&& mouseY > (hauteur_image - 20) * ligne && mouseY < hauteur_image * ligne + hauteur_image + 20)
				numeroeleve = ligne * 5 + colonne;
	if (numeroeleve >= listPage_[pageActuelle_].getNbrEleve())
		numeroeleve = -1;
	
	return numeroeleve;
}

Seance::Seance(groupe leGroupe, CImgDisplay& disp)
{
	CImg<unsigned char> image(largueur_fenetre, hauteur_fenetre, 1, 3, 255);
	vector<eleve> liste;
	imageBlank_ = image;
	pageActuelle_ = -1;
	disp_ = disp;
	int 
		intermediaire = leGroupe.getNbrEleve() / 10,
		max = 0;

	if (intermediaire * 10 == leGroupe.getNbrEleve())
		nbrPage_ = intermediaire;
	else
		nbrPage_ = intermediaire + 1;

	// On subdivise le groupe selectionné en groupe de 10 élèves
	// car on ne veut en afficher que 10 à la fois
	// Ces 10 élèves sont envoyés dans le constructeur de la classe Page
	// pour que l'on puisse en récupérer une image totalement construite
	// et prête à être utilisée
	for (int k = 0; k < 10 * (leGroupe.getNbrEleve() / 10 + 1); k += 10)
	{
		// ON réinitialise la liste pour ne pas reprendre les mêmes
		liste.clear();
		// Si il reste des groupes de 10 elèves à former
		if (k + 10 == 10 * (leGroupe.getNbrEleve() / 10 + 1))
			max = leGroupe.getNbrEleve();
		// Sinon on fait un groupe avec les restants
		else
			max = k + 10;
		for (int j = k; j < max; j++)
			liste.push_back(leGroupe.getEleve(j));
		// On construit un objet page
		Page unePage(k / 10, liste, nbrPage_);
		// On récupère l'image et on la stocke dans la classe séance
		listPage_.push_back(unePage);
		cout << "Une image ajoutée" << endl;
	}
}

void Seance::actualiserPresence(int numeroEleve)
{
	listPage_[pageActuelle_].actualiserPage(numeroEleve);
}

vector<eleve> Seance::getAbsent()
{
	vector<eleve> listAbsent;
	vector<Page> lesPage = getListPage();
	vector<Page>::iterator itPage;
	vector<Image> lesImages;
	vector<Image>::iterator itImage;
	eleve unEleve;

	for (itPage = lesPage.begin(); itPage != lesPage.end(); itPage++)
	{
		lesImages = (*itPage).getListImgEtudiant();
		for (itImage = lesImages.begin(); itImage != lesImages.end(); itImage++)
		{
			if (!(*itImage).getPresence())
			{
				unEleve = (*itImage).getEleve();
				listAbsent.push_back(unEleve);
			}
		}
	}
	return listAbsent;
}

Seance::~Seance()
{
	cout << "Destruction initiée !" << endl;
	//sauvegarde();
	//disp_.close();
	cout << "Destruction terminée" << endl;
}

void Seance::afficherPageX(int numeroPage)
{
	if (numeroPage >= 0 && numeroPage < nbrPage_)
	{
		listPage_[numeroPage].getImage().display(disp_);
		pageActuelle_ = numeroPage;
		disp_.set_fullscreen(disp_.is_fullscreen());
		disp_.move(10, 40);
	}
	else
	{
		cout << "Il y a un bug dans la matrice au niveau de l'affichage des pages !" << endl;
		system("pause");
	}
}

void Seance::afficherSuivante()
{
	if (pageActuelle_ == nbrPage_ - 1)
	{
		cout << ("Il n'y a pas de page suivante !") << endl;
		pageWait();
	}
	else
	{
		pageActuelle_++;
		afficherPageX(pageActuelle_);
	}
}

void Seance::afficherPrecedente()
{
	if (pageActuelle_ == 0)
	{
		cout << ("Il n'y a pas de page précédente !") << endl;
		pageWait();
	}
	else
	{
		pageActuelle_--;
		afficherPageX(pageActuelle_);
	}
}

void Seance::afficherEndPage()
{
	imageBlank_.draw_text(400, 200, "La saisie des absents est terminée.", "texte",WHITENESS,1,30);
	imageBlank_.draw_text(200, 300, "		Vous pouvez retrouver la fiche d'absence sous le nom Fiche d'absence.txt.", "texte", WHITENESS, 1, 20);
	imageBlank_.display(disp_);
	disp_.wait();
}

void Seance::sauvegarde()
{
	vector<eleve> absent = getAbsent();
	Memoire laMemoire(absent.size());
	int numero=laMemoire.calculNumeroSeance(); // On calcule le numéro de la séance en cours.
	string numeroChaine = to_string(numero); // Conversion int en string.

	string nomSeance = "Fiche d'absence ";
	cout << "Sauvegarde de la fiche d'absence en cours..." << endl;
	ofstream flux((nomSeance + numeroChaine + ".txt").c_str());
	
	float compteurEleves = 0;
	for (int k = 0; k < listPage_.size(); k++)
	{
		compteurEleves = compteurEleves + ((listPage_[k].getListImgEtudiant().size()));
	}
	laMemoire.calculTauxAbsenteisme(absent.size(), compteurEleves);


	if (numero == 1)
	{
		laMemoire.setVariationAbsenteisme(0);
		laMemoire.setMoyenneAbsents(absent.size());
		laMemoire.setMoyenneTaux(laMemoire.calculTauxAbsenteisme(absent.size(), compteurEleves));
	}
	else
	{
		laMemoire.calculVariationAbsenteisme();
		laMemoire.calculMoyenneAbsents(absent.size());
		laMemoire.calculMoyenneTaux();
	}


	flux << "===============================" << endl;
	flux << "  Fiche d'absence : séance " <<numero<<"."<< endl;
	flux << "===============================" << endl << endl;
	flux << "Quelques statistiques :" << endl << endl;
	flux << "Durant cette séance, le nombre d'étudiants absents est de :" << absent.size() << endl;
	flux << "Durant cette séance, le taux d'absentéisme est de :" << laMemoire.getTauxAbsenteisme() <<"%"<< endl;
	flux << "La variation du taux d'absentéisme par rapport à la séance précdente est de :" << laMemoire.getVariationAbsenteisme() << "%" << endl;
	flux << "Le nombre d'absents moyen est, en tenant compte de cette séance, de :" << laMemoire.getMoyenneAbsents() << endl;
	flux << "La moyenne du taux d'absentéisme en tenant compte de cette séance est de :" << laMemoire.getMoyenneTaux() << "%" << endl << endl;
	flux << "Les élèves absents durant cette séance sont :" << endl << endl;


	//flux << "    Nom :    " << "    Prenom :    " << endl << endl;
	for (unsigned int i = 0; i< absent.size(); i++)
	{
		flux << (absent[i]).getNom() << "        " << absent[i].getPrenom() << endl << endl;
	}
	
	
	system(("notepad "  + nomSeance + numeroChaine + ".txt").c_str());
	cout << "Sauvegarde terminée." << endl;
}