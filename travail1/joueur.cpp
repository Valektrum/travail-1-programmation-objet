#include "joueur.h"

Joueur::Joueur()
{
	nom = "";
	nombreDefaites = 0;
	nombreVictoires = 0;
	*mainDuJoueur = {};
}

void Joueur::setNom(string aNom)
{
	nom = aNom;
}