#include "joueur.h"

Joueur::Joueur()
{
	nom = "";
	nombreDefaites = 0;
	nombreVictoires = 0;
	nombreDeCarte = 0;
	*mainDuJoueur = {};
}

void Joueur::setNom(string aNom)
{
	nom = aNom;
}

void Joueur::AjouterCarteMain(Carte* aCarte)
{
	mainDuJoueur[nombreDeCarte] = aCarte;
	nombreDeCarte++;
}




void Joueur::ViderMain()
{
	for (int i = 0; i < maxCartesAJouer ; i++)
	{
		mainDuJoueur[i] = nullptr;
	}
}