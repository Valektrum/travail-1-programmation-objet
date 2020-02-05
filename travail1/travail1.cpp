#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

Donnees leJeu;

void InitialiserJoueurs();
void Jouer();
void melanger();
int combienDeCarte();
void distribuer(int aNombreDeCarte);
void afficher();
void AfficherGagnantTour();
void AfficherGagnantJeu();

int main() 
{
	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;		
	}
	ClrScr();
	AfficherGagnantJeu();
}

void Jouer() 
{
	int nombreDeCarte = combienDeCarte();
	melanger();
	distribuer(nombreDeCarte);
	afficher();

	getchar();
	ClrScr();

	AfficherGagnantTour();

	
	leJeu.joueur1.ViderMain();
	leJeu.joueur2.ViderMain();

}

void AfficherGagnantTour()
{
	string gagnant;
	if (leJeu.joueur1.total() > leJeu.joueur2.total())
	{
		gagnant = leJeu.joueur1.getNom();
		leJeu.joueur1.JoueurAGagne();
		leJeu.joueur2.JoueurAPerdu();
	}
	else
	{
		gagnant = leJeu.joueur2.getNom();
		leJeu.joueur2.JoueurAGagne();
		leJeu.joueur1.JoueurAPerdu();
	}
	cout << gagnant << " a gagne le tour";

}

void AfficherGagnantJeu()
{
	string gagnant;
	int x = 0;
	int y = 0;
	if (leJeu.joueur1.getVictoire() > leJeu.joueur2.getVictoire())
	{
		gagnant = leJeu.joueur1.getNom();
	}
	else if(leJeu.joueur1.getVictoire() < leJeu.joueur2.getVictoire())
	{
		gagnant = leJeu.joueur2.getNom();
	}
	else
	{
		gagnant = "Personne";
	}
	Gotoxy(x, y);
	cout << gagnant << " a gagne le jeu!";
	y++;
	Gotoxy(x, y);
	cout << "----------------------";
	y++;
	leJeu.joueur1.AfficherStats(x, y);
	leJeu.joueur2.AfficherStats(x + 25, y);
	cin.clear();
	cin.ignore(1000, '\n');
	getchar();

}

void afficher()
{
	ClrScr();

	int x = 0;
	int y = 0;

	leJeu.joueur1.Afficher(x, y);
	leJeu.joueur2.Afficher(x + 25, y);
}

void distribuer(int aNombreDeCarte)
{
	for (int i = 0; i < aNombreDeCarte; i ++)
	{
		leJeu.joueur1.AjouterCarteMain(&leJeu.lePaquet[i]);
	}
	for (int i = 0; i < aNombreDeCarte; i ++)
	{
		leJeu.joueur2.AjouterCarteMain(&leJeu.lePaquet[aNombreDeCarte + i]);
	}
}

void melanger()
{
	int nb1, nb2;
	Carte carteTemp;

	for (int i = 0; i < 1001; i++)
	{
		nb1 = rand() % 52;
		nb2 = rand() % 52;
		carteTemp = leJeu.lePaquet[nb1];
		leJeu.lePaquet[nb1] = leJeu.lePaquet[nb2];
		leJeu.lePaquet[nb2] = carteTemp;
	}
}

int combienDeCarte()
{
	int nbCarte = 27;
	cout << "Combiens de carte voulez-vous dans votre main?" << endl;
	while (nbCarte > 26 || nbCarte <=0)
	{
		cin >> nbCarte;
		cin.clear();
		cin.ignore(1000, '\n');
		if (nbCarte >26 || nbCarte <= 0) {
			cout << "Veuillez choisir un nombre plus petit ou egal à 26" << endl;
		}
	}
	return nbCarte;
}

void InitialiserJoueurs()
{
	
	string nom;
	cout << "Veuillez entrer le nom du joueur #1" << endl;
	cin >> nom;
	leJeu.joueur1.setNom(nom);

	nom = "";

	cout << "Veuillez entrer le nom du joueur #2" << endl;
	cin >> nom;
	leJeu.joueur2.setNom(nom);

}
