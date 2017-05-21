#include "Image.h"
#include <iostream>

using namespace std;
using namespace cimg_library;

void Image::modifierImage()
{
	CImg<unsigned char> imgCheck;
	if (present_)
		imgCheck.load("tn_check_vert.ppm");
	else
		imgCheck.load("tn_check_rouge.ppm");
	image_.draw_image(225, 0, imgCheck);
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
		imgBlank(250, 340, 1, 3, 255);
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
	image_.draw_image(225, 0, imgEtudiant);
	// On créé la chaine de caractère Nom + Prénom
	string nomPrenom = unEleve.getNom() + " " + unEleve.getPrenom();
	// On positionne ensuite cette chaine sous l'image
	image_.draw_text(5, 320, nomPrenom.c_str(), "texte");
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
