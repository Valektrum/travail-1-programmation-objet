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
			atout = "trefle";
		}
		else if(i==3)
		{
			atout = "carreau";
		}
		for (int j = 1; j < 14; j++)
		{
			aLePaquet[nbCarte].InitialiserCarte(j, atout);
			nbCarte++;
		}
	}
}

