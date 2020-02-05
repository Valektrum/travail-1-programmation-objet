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
}

void Jouer() 
{
	int nombreDeCarte = combienDeCarte();
	melanger();
}

void melanger()
{
	int nb1, nb2;
	Carte carteTemp, carte1;

	for (int i = 0; i < 1001; i++)
	{
		nb1 = rand() % 52;
		nb2 = rand() % 52;
		carteTemp = leJeu.lePaquet[nb1];
		leJeu.lePaquet[nb1] = carte1;
		leJeu.lePaquet[nb2] = carteTemp;
	}
}

int combienDeCarte()
{
	int nbCarte = 27;
	cout << "Combiens de carte voulez vous dans votre main?" << endl;
	while (nbCarte > 26)
	{
		cin >> nbCarte;
		if (nbCarte > 26) {
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
