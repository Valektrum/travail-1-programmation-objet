#include "donnees.h"

Donnees::Donnees()
{
	CreerLes52Cartes(lePaquet);
	
}

void Donnees::CreerLes52Cartes(Carte aLePaquet[])
{
	string atout = "pique";
	int nbCarte = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i == 1)
		{
			atout = "coeur";
		}
		else if (i == 2)
		{
			atout = "trèfle";
		}
		else
		{
			atout = "carreau";
		}
		for (int j = 0; j < 13; j++)
		{
			Carte nouvelleCarte;
			nouvelleCarte.InitialiserCarte(j, atout);
			aLePaquet[nbCarte];
			nbCarte++;
		}
	}
}

