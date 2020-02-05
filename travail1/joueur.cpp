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

void Joueur::Afficher(int inX, int inY)
{
	Gotoxy(inX, inY);
	cout <<  nom;
	inY++;
	Gotoxy(inX, inY);
	cout << "---------------";
	for (int i = 0; i < nombreDeCarte; i++)
	{
		inY++;

		mainDuJoueur[i]->Afficher(inX, inY);
	}
	inY++;
	Gotoxy(inX, inY);
    cout << "---------------";
	inY++;
	Gotoxy(inX, inY);
	cout << "total :" << total();

}

void Joueur::AfficherStats(int inX, int inY)
{
	
	inY++;
	Gotoxy(inX, inY);
	cout << "Nom :" << nom;
	inY++;
	Gotoxy(inX, inY);
	cout << "Nombre de victoire :" << nombreVictoires;
	inY++;
	Gotoxy(inX, inY);
	cout << "Nombre de defaite :" << nombreDefaites;

}

int Joueur::total()
{
	int total = 0;
	for (int i = 0; i < nombreDeCarte; i++)
	{
		total += mainDuJoueur[i]->GetValeur();
	}
	return total;
}

string Joueur::getNom()
{
	return nom;
}

int Joueur::getVictoire()
{
	return nombreVictoires;
}

int Joueur::getDefaite()
{
	return nombreDefaites;
}

void Joueur::JoueurAGagne()
{
	nombreVictoires++;
}
void Joueur::JoueurAPerdu()
{
	nombreDefaites++;
}

void Joueur::ViderMain()
{
	for (int i = 0; i < maxCartesAJouer ; i++)
	{
		mainDuJoueur[i] = nullptr;
	}
	nombreDeCarte = 0;
}