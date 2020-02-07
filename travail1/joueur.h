#include <string>
#include "carte.h"
using namespace std;

#ifndef JoueurH
#define JoueurH

const int maxCartesAJouer = 26;
class Joueur
{
private:
	string nom;
	int nombreVictoires;
	int nombreDefaites;
	int nombreDeCarte;
	Carte* mainDuJoueur[26];
public:
	Joueur();

	void setNom(string);
	void AjouterCarteMain(Carte*);
	void ViderMain();
	void Afficher(int, int);
	int total();
	string getNom();
	int getVictoire();
	int getDefaite();
	void AGagne();
	void APerdu();
	void AfficherStats(int, int);
};
#endif