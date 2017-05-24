#include "Image.h"
#include <iostream>

#define largueur_image 250
#define hauteur_image 340
#define taille_check 50

using namespace std;
using namespace cimg_library;

void Image::modifierImage()
{
	CImg<unsigned char> imgCheck;
	if (present_)
		imgCheck.load("tn_check_vert.ppm");
	else
		imgCheck.load("tn_check_rouge.ppm");
	image_.draw_image(largueur_image - 5 - taille_check, 0, imgCheck);
	//CImgDisplay disp;
	//image_.display(disp);
	//disp.wait(5000);
}

Image::Image(eleve& unEleve, int numeroImage)
{
	numeroImage_ = numeroImage;
	eleveAssocie_p_ = &unEleve;
	// Par défaut l'étudiant est noté comme présent
	present_ = TRUE;
	// On initialise une image blanche
	CImg<unsigned char> 
		imgEtudiant,
		imgBlank(largueur_image, hauteur_image, 1, 3, 255);
	image_ = imgBlank;
	string photo;
	// On récupère le nom du fichier de la photo de l'étudiant
	unEleve.getPhoto(photo);
	// On converti le string en char* car un nom de fichier ne peut pas être un string ici et on charge la photo voulue
	imgEtudiant.load(photo.c_str());
	// On positionne l'image de l'étudiant
	image_.draw_image(5, 0, imgEtudiant);
	// On positionne maintenant le cadre de check
	imgEtudiant.load("tn_check_vert.ppm");
	image_.draw_image(largueur_image - 5 - taille_check, 0, imgEtudiant);
	// On créé la chaine de caractère Nom + Prénom
	string nomPrenom = unEleve.getNom() + " " + unEleve.getPrenom();
	// On positionne ensuite cette chaine sous l'image
	image_.draw_text(5, hauteur_image - 20, nomPrenom.c_str(), "texte");
	cout << "Une image construite" << endl;
}

void Image::actualisationAbsence()
{
	if (present_)
		present_ = FALSE;
	else
		present_ = TRUE;
	modifierImage();
}
