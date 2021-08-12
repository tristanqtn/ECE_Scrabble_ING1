#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>

///Menu
void affichageRegle();
void PseudosJoueurs(int *joueurs);
void nbrJoueurs(int *nombreJoueurs);
void menu(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue);



///FONCTIONS DE JEUX
int lettreChange(char main[7], char *carac);
void remplirMain(char pioche [2][27], char chevalet[7]);
void changerMain(char pioche [2][27], char chevalet[7]);
void changementCoord(char *coordonnee, int* coordonneeXbis);
void coordonnee(char* coordonneeX, int* coordonneeY, char* sens, int* coordonneeXbis);
void saisieMot(char chevalet[7], char pioche [2][27], char tableauinvisible[15][15][2], int *compteurTour, int *pointstotaux, int langue, int nbJoueurs);
void actionJ (char pioche [2][27], char mainJoueur[7], char tableauinvisible[15][15][2], int *compteurTour, int *pointstotaux, int langue, int nbJoueurs);
void gestionLettre(char joueur[20], char mainJoueur[7], char pioche[2][27], char tableauinvisible[15][15][2], int *partie, int *compteurTour, int *pointstotaux, int langue, int nbJoueurs);


///VERIFICATION
void joker(char mot[15]);
void choixlangue(int *langue);
void verifDico(char mot [15], int *autor);
void verifDicoAnglais(char mot [15], int *autor);
void verifDicoEspagnol(char mot [15], int *autor);
void verifDicoAllemand(char mot [15], int *autor);
void contestation (int nbJoueurs, int *autorisation);
void verifMot(char mot[15], char chevalet[7], int *autor, char pioche [2][27], int changement[7], int *compteurTour);



///FONCTIONS D'AFFICHAGE
void affichageMain(char chevalet[7]);
void affichagePioche(char tab[2][27]);
void affichagePlateau(char tableau[15][15][2]);
void Color(int couleurDuTexte,int couleurDeFond);
void multiplicateurPlateau(char tablo[15][15][2]);
void remplitableauinvisible(char tablo[15][15][2]);
void placerMotV(char mot[15], int coordX, int coordY, char tablo[15][15][2]);
void placerMotH(char mot[15], int coordX, int coordY, char tablo[15][15][2]);
void classement_finjoueurs(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue);
void classement_encoursjoueurs(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue);



///Score
void scoreV(char mot_saisie[15], int *pointstotaux, char tablo[15][15][2], int X, int Y);
void scoreH(char mot_saisie[15], int *pointstotaux, char tablo[15][15][2], int X, int Y);
void multiplicateurH(char tablo[15][15][2] ,int *ML, int *multiplicateur,int X, int Y, int longueur);
void multiplicateurV(char tablo[15][15][2] ,int *ML, int *multiplicateur, int X, int Y, int longueur);
void pointH(char mot[100],int *ptScore,char repertoireL[27],int repertoireC[27],char tablo[15][15][2],int X,int Y,int *multi);
void pointV(char mot[100],int *ptScore,char repertoireL[27],int repertoireC[27],char tablo[15][15][2],int X,int Y,int *multi);



///Sauvegarde
void sauvegardeunjoueur();
void sauvegardedeuxjoueurs();
void sauvegardetroisjoueurs();
void sauvegardequatrejoueurs();
void sauvegardepioche(char pioche[2][27]);
void sauvegardetableau(char tableauinvisible[15][15][2]);
void sauvegardepartie(int *Joueurs, char tableauinvisible[15][15][2], int *langue);



///Récupération
void ancientableau(char pioche[2][27], int *Joueurs, char tableauinvisible[15][15][2], int *langue);
void anciennepioche(char pioche[2][27], int *Joueurs, char tableauinvisible[15][15][2], int *langue);
void anciennepartie(int *Joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue);
void anciennbjoueurs(int *Joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue);
void anciennepartiesolo(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue);
void anciennepartiedeux(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue);
void anciennepartietrois(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue);
void anciennepartiequatre(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue);



///Structures
typedef struct JOUEUR JOUEUR;
struct JOUEUR
{
char pseudo[20];
char mainjoueur[7];
int pointsjoueur;
int tourjoueur;
};

JOUEUR joueurun;
JOUEUR joueurdeux;
JOUEUR joueurtrois;
JOUEUR joueurquatre;

void modesolo(char pioche[2][27], char tableauinvisible[15][15][2], int langue);
void modedeuxjoueurs(char pioche[2][27], char tableauinvisible[15][15][2], int langue);
void modetroisjoueurs(char pioche[2][27], char tableauinvisible[15][15][2], int langue);
void modequatrejoueurs(char pioche[2][27], char tableauinvisible[15][15][2], int langue);

#endif // HEADER_H_INCLUDED

/*/////SOURCES////////////////////////////////////////////////////////////////////////////////////////////////////////

table ANSI - Moodle ECE - Projet info
sous programme couleurs- Moodle ECE - Projet info
cours d’informatiques - Moodle ECE - Informatique

https://pedago-ece.campusonline.me/my/

Dictionnaires :
https://www.freelang.com/dictionnaire/dic-francais.php
http://www.3zsoftware.com/fr/listes.php
https://hugo.maugey.fr/conversion/transformation-textes

Autres sources :
https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
