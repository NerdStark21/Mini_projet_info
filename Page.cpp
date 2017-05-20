#include <iostream>
#include "Page.h"
#include "Seance.h"

using namespace std;
using namespace cimg_library;

void test(groupe& leGroupe)
{
	CImgDisplay disp;

	Seance seance1(leGroupe, disp);
}

void affichageTest(groupe& leGroupe)
{
	// Les images font 240 de large pour 320 de haut
	// Mon écran fait 1366 de large pour 768 de haut

	CImgDisplay disp;

	Seance(leGroupe, disp);

	//disp.move((CImgDisplay::screen_width() - disp.width()) / 2 - 250,
	//	(CImgDisplay::screen_height() - disp.height()) / 2 - 250);
	//disp.move(0, 0);
	vector<eleve> listEleve;

	CImg<unsigned char> image(1260, 700, 1, 3, 255);
	CImg<unsigned char> imageBlank(1300, 700, 1, 3, 255);
	CImg<unsigned char> imgEtudiant;

	int max = 0;
	cout << "hmax = " << 10 * (leGroupe.getNbrEleve() / 10 + 1) << endl;
	cout << "nbr d'eleve = " << leGroupe.getNbrEleve() << endl;
	int h;
	for (h = 0; h < 10 * (leGroupe.getNbrEleve() / 10 + 1); h += 10)
	{
		cout << "h = " << h << endl;
		listEleve.clear();
		if (h + 10 < leGroupe.getNbrEleve())
			max = h + 10;
		else
			max = leGroupe.getNbrEleve();

		int compt = 0;
		for (int j = h; j < max; j++)
		{
			listEleve.push_back(leGroupe.getEleve(j));
			cout << listEleve[compt].getPrenom() << endl;
			compt++;
		}

		image = imageBlank;

		for (unsigned int k = 0; k < listEleve.size(); k++)
		{
			string photo;
			// On extrait un élève pour pouvoir utiliser les fonctions de la classe élève
			eleve etudiant = listEleve[k];
			// On récupère le nom du fichier de la photo de l'étudiant
			etudiant.getPhoto(photo);
			// On converti le string en char* car un nom de fichier ne peut pas être un string ici et on charge la photo voulue
			imgEtudiant.load(photo.c_str());
			// On affiche que 5 images par ligne
			if (k < 5)
			{
				// On positionne d'abord l'image
				image.draw_image(240 * k + 10 * k, 0, imgEtudiant);
				// On créé la chaine de caractère Nom + Prénom
				string nomPrenom = etudiant.getNom() + " " + etudiant.getPrenom();
				// On positionne ensuite cette chaine sous l'image correspondante
				image.draw_text(240 * k + 10 * k, 320, nomPrenom.c_str(), "texte");
			}
			else
			{
				image.draw_image(240 * (k - 5) + 10 * (k - 5), 320 + 20, imgEtudiant);
				string nomPrenom = etudiant.getNom() + "   " + etudiant.getPrenom();
				image.draw_text(240 * (k - 5) + 10 * (k - 5), 320 * 2 + 20, nomPrenom.c_str(), "texte");
			}
		}
		
		image.draw_text(1200, 670, "NEXT >>>", "texte");
		image.display(disp);
		disp.move(10, 40);
		disp.set_fullscreen(disp.is_fullscreen());
		bool condition = FALSE;
		disp.wait(1000);
		while (disp.button() != 0x1 || !condition)
		{
			// Si l'on clique sur l'image en bas à gauche
			int mouseX = disp.mouse_x();
			int mouseY = disp.mouse_y();
			if (mouseX > 1200 && mouseX < 1250 && mouseY>670 && mouseY < 680)
			{
				condition = TRUE;
			}
			else
				disp.wait();
		}
		disp.wait(1000);
	}
}

void affichageQuiMarche(groupe& leGroupe)
{
	CImgDisplay disp;
	disp.move((CImgDisplay::screen_width() - disp.width()) / 2,
		(CImgDisplay::screen_height() - disp.height()) / 2);

	vector<eleve> listEleve;

	CImg<unsigned char> image(1260, 700, 1, 3, 255);
	CImg<unsigned char> imgEtudiant;

	for (int k = 0; k < 10; k++)
		listEleve.push_back(leGroupe.getEleve(k));

	for (int k = 0; k < 10; k++)
	{
		string photo;
		// On extrait un élève pour pouvoir utiliser les fonctions de la classe élève
		eleve etudiant = listEleve[k];
		// On récupère le nom du fichier de la photo de l'étudiant
		etudiant.getPhoto(photo);
		// On converti le string en char* car un nom de fichier ne peut pas être un string ici et on charge la photo voulue
		imgEtudiant.load(photo.c_str());
		// On affiche que 5 images par ligne
		if (k < 5)
		{
			// On positionne d'abord l'image
			image.draw_image(240 * k + 10 * k, 0, imgEtudiant);
			// On créé la chaine de caractère Nom + Prénom
			string nomPrenom = etudiant.getNom() + " " + etudiant.getPrenom();
			// On positionne ensuite cette chaine sous l'image correspondante
			image.draw_text(240 * k + 10 * k, 320, nomPrenom.c_str(), "texte");
		}
		else
		{
			image.draw_image(240 * (k - 5) + 10 * (k - 5), 320 + 20, imgEtudiant);
			string nomPrenom = etudiant.getNom() + "   " + etudiant.getPrenom();
			image.draw_text(240 * (k - 5) + 10 * (k - 5), 320 * 2 + 20, nomPrenom.c_str(), "texte");
		}
	}

		image.display(disp);

		while (!disp.is_closed() && !disp.is_keyS())
			disp.wait();

		listEleve.clear();
		for (int k = 10; k < 20; k++)
			listEleve.push_back(leGroupe.getEleve(k));

		CImg<unsigned char> imageBlank(1260, 700, 1, 3, 255);
		image = imageBlank;
		//image.display(disp);

		for (int k = 0; k < 10; k++)
		{
			string photo;
			// On extrait un élève pour pouvoir utiliser les fonctions de la classe élève
			eleve etudiant = listEleve[k];
			// On récupère le nom du fichier de la photo de l'étudiant
			etudiant.getPhoto(photo);
			// On converti le string en char* car un nom de fichier ne peut pas être un string ici et on charge la photo voulue
			imgEtudiant.load(photo.c_str());
			// On affiche que 5 images par ligne
			if (k < 5)
			{
				// On positionne d'abord l'image
				image.draw_image(240 * k + 10 * k, 0, imgEtudiant);
				// On créé la chaine de caractère Nom + Prénom
				string nomPrenom = etudiant.getNom() + " " + etudiant.getPrenom();
				// On positionne ensuite cette chaine sous l'image correspondante
				image.draw_text(240 * k + 10 * k, 320, nomPrenom.c_str(), "texte");
			}
			else
			{
				image.draw_image(240 * (k - 5) + 10 * (k - 5), 320 + 20, imgEtudiant);
				string nomPrenom = etudiant.getNom() + "   " + etudiant.getPrenom();
				image.draw_text(240 * (k - 5) + 10 * (k - 5), 320 * 2 + 20, nomPrenom.c_str(), "texte");
			}
		}

		image.display(disp);

		while (!disp.is_closed())
			disp.wait();
}

Page::Page(int numeroPage, vector<eleve>& listEleve, int nbrPage)
{
	nbrPage_ = nbrPage;
	// On initialise l'image comme étant une image blanche (RVB)
	CImg<unsigned char> image(1260, 700, 1, 3, 255);
	image_ = image;
	// le nombre d'élèves de la séance correspond au nombre d'élèves du groupe
	nbrEleve_ = listEleve.size();
	numeroPage_ = numeroPage;
	listEleve_ = listEleve;
	// On initie tout de suite le construction de l'image du groupe donné
	Page::constructionImage();
}

void Page::constructionImage()
{
	CImg<unsigned char> imgEtudiant;

	for (unsigned int k = 0; k < listEleve_.size(); k++)
	{
		string photo;
		// On extrait un élève pour pouvoir utiliser les fonctions de la classe élève
		eleve etudiant = listEleve_[k];
		// On récupère le nom du fichier de la photo de l'étudiant
		etudiant.getPhoto(photo);
		// On converti le string en char* car un nom de fichier ne peut pas être un string ici et on charge la photo voulue
		imgEtudiant.load(photo.c_str());
		// On affiche que 5 images par ligne
		if (k < 5)
		{
			// On positionne d'abord l'image
			image_.draw_image(240 * k + 10 * (k + 1), 0, imgEtudiant);
			// On créé la chaine de caractère Nom + Prénom
			string nomPrenom = etudiant.getNom() + " " + etudiant.getPrenom();
			// On positionne ensuite cette chaine sous l'image correspondante
			image_.draw_text(240 * k + 10 * (k + 1), 320, nomPrenom.c_str(), "texte");
		}
		else
		{
			image_.draw_image(240 * (k - 5) + 10 * (k - 4), 320 + 20, imgEtudiant);
			string nomPrenom = etudiant.getNom() + "   " + etudiant.getPrenom();
			image_.draw_text(240 * (k - 5) + 10 * (k - 4), 320 * 2 + 20, nomPrenom.c_str(), "texte");
		}
	}
	cout << "Page n= " << numeroPage_ << endl;
	cout << "Il y a " << nbrPage_ << " pages." << endl;
	if (numeroPage_ < nbrPage_)
	{
		// Bouton NEXT si on est pas à la dernière page
		image_.draw_text(1200, 670, "NEXT >>>", "texte");
		unsigned char grid_color[3] = { 0, 0, 0 };
		image_.draw_rectangle(1180, 670, 1260, 685, grid_color, 0.2);
	}
	if (numeroPage_ == nbrPage_ - 1)
	{
		// Bouton END si on est à la dernière page
		image_.draw_text(1200, 670, "END >>>", "texte");
		unsigned char grid_color[3] = { 0, 0, 0 };
		image_.draw_rectangle(1180, 670, 1260, 685, grid_color, 0.2);
	}
	if (numeroPage_ > 0)
	{
		// Bouton PREVIOUS si on est pas à la première page
		image_.draw_text(0, 670, "<<< PREVIOUS", "texte");
		unsigned char grid_color[3] = { 0, 0, 0 };
		image_.draw_rectangle(0, 670, 50, 680, grid_color, 0.2);
	}
}
