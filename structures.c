#include "header.h"

///Lancement des diff�rents modes de jeu

//Lancement de la partie en solo
void modesolo(char pioche[2][27], char tableauinvisible[15][15][2], int langue)
{
    int partie=0; //cr�ation d'une variable partie qui permet l'arr�t de la partie lorsqu'elle est finie
    int choix; //cr�ation d'une variable permettant le choix de continuer ou d'arr�ter la partie � la fin de chaque tour
    int joueurs=1; //bahh il y a un joueur
    int compteurTour = 0;

    do
    {
        system("cls");
        affichagePlateau(tableauinvisible); //on appelle la fonction d'affichage du plateau
        gestionLettre(joueurun.pseudo, joueurun.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurun.pointsjoueur, langue, joueurs); //on rentre dans la partie actionJoueur c'est l�-bas que toutes les actions se d�rouleront
        //Si le joueur n'a plus de lettres dans sa main on met un terme � la partie
        if((joueurun.mainjoueur[0]==100) && (joueurun.mainjoueur[1]==100) && (joueurun.mainjoueur[2]==100) && (joueurun.mainjoueur[3]==100) && (joueurun.mainjoueur[4]==100) && (joueurun.mainjoueur[5]==100) && (joueurun.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        Sleep(1500);
        system("cls"); //on nettoie l'�cran
        affichagePlateau(tableauinvisible); //on appelle la fonction d'affichage du plateau
        joueurun.tourjoueur++; //on ajoute un au nombre de tour du joueur
        sauvegardeunjoueur(); //appel du programme de sauvegarde des donn�es du joueur
        sauvegardepioche(pioche); //appel du programme de sauvegarde de la pioche
        sauvegardetableau(tableauinvisible); //appel du programme de sauvegarde du tableau
        do //menu blind� pour choisir de continuer la partie ou de sauvegarder et quitter
        {
            printf("Voici votre score : %d\n", joueurun.pointsjoueur);
            printf("Pour passer au tour suivant : taper 1\n");
            printf("Pour sauvegarder et retourner au menu : taper 2\n");
            scanf("%d", &choix);
        }
        while(choix!=2 && choix!=1);
        system("cls"); //nettoyage de l'�cran
        if(choix==2)
        { //on recr�e une nouvelle pioche dans le cas o� le joueur choisirait de lancer une nouvelle partie (l'ancienne est toujours sauvegard�e dans un fichier s'il relance l'ancienne)
            char pioche2 [2][27] =
            {
                {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?'},
                {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2}
            };
            menu(&joueurs, tableauinvisible, pioche2, &langue); //retour au menu
        }
        affichagePlateau(tableauinvisible);
    }
    while(partie==0);
    classement_finjoueurs(&joueurs, tableauinvisible, pioche, &langue); //appel de la fonction d'affichage du classement quand la partie est finie

}

//Lancement de la partie avec deux joueurs
void modedeuxjoueurs(char pioche[2][27], char tableauinvisible[15][15][2], int langue)
{
    int partie =0;//cr�ation d'une variable partie qui permet l'arr�t de la partie lorsqu'elle est finie
    int choix;     //cr�ation d'une variable permettant le choix de continuer ou d'arr�ter la partie � la fin de chaque tour
    int joueurs=2; //bahh il y a un joueur
    int compteurTour = 0;

    do
    {
        system("cls");
        affichagePlateau(tableauinvisible); //on appelle la fonction d'affichage du plateau
        gestionLettre(joueurun.pseudo, joueurun.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurun.pointsjoueur, langue, joueurs); //on rentre dans la partie actionJoueur c'est l�-bas que toutes les actions se d�rouleront
         //Si le joueur n'a plus de lettres dans sa main on met un terme � la partie
         if((joueurun.mainjoueur[0]==100) && (joueurun.mainjoueur[1]==100) && (joueurun.mainjoueur[2]==100) && (joueurun.mainjoueur[3]==100) && (joueurun.mainjoueur[4]==100) && (joueurun.mainjoueur[5]==100) && (joueurun.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        system("cls"); //on nettoie l'�cran
        affichagePlateau(tableauinvisible); //on appelle la fonction d'affichage du plateau
        joueurun.tourjoueur++; //on ajoute un au nombre de tour du joueur
        sauvegardedeuxjoueurs(); //appel du programme de sauvegarde des donn�es du joueur
        sauvegardepioche(pioche); //appel du programme de sauvegarde de la pioche
        sauvegardetableau(tableauinvisible);  //appel du programme de sauvegarde du tableau
        ///Le tour de chaque joueur est semblable et se d�roule donc exactement de la m�me mani�re
        gestionLettre(joueurdeux.pseudo, joueurdeux.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurdeux.pointsjoueur, langue, joueurs);
        if((joueurdeux.mainjoueur[0]==100) && (joueurdeux.mainjoueur[1]==100) && (joueurdeux.mainjoueur[2]==100) && (joueurdeux.mainjoueur[3]==100) && (joueurdeux.mainjoueur[4]==100) && (joueurdeux.mainjoueur[5]==100) && (joueurdeux.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        system("cls");
        affichagePlateau(tableauinvisible);
        joueurdeux.tourjoueur++;
        sauvegardedeuxjoueurs();
        sauvegardepioche(pioche);
        sauvegardetableau(tableauinvisible);
        do  //menu blind� pour choisir de continuer la partie ou de sauvegarder et quitter
        {
            printf("Voici le score de %s : %d\n", joueurun.pseudo, joueurun.pointsjoueur);
            printf("Voici le score de %s : %d\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("Pour passer au tour suivant : taper 1\n");
            printf("Pour sauvegarder et retourner au menu : taper 2\n");
            scanf("%d", &choix);
        }
        while(choix!=2 && choix!=1);
        system("cls");
        if(choix==2)
        {
            char pioche2 [2][27] =
            {
                {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?'},
                {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2}
            };
            menu(&joueurs, tableauinvisible, pioche2, &langue);
        }
        affichagePlateau(tableauinvisible);
    }
    while(partie==0);
    classement_finjoueurs(&joueurs, tableauinvisible, pioche, &langue);
}

//Lancement de la partie avec trois joueurs
void modetroisjoueurs(char pioche[2][27], char tableauinvisible[15][15][2], int langue)
{
    int partie=0;  //cr�ation d'une variable partie qui permet l'arr�t de la partie lorsqu'elle est finie
    int choix;     //cr�ation d'une variable permettant le choix de continuer ou d'arr�ter la partie � la fin de chaque tour
    int joueurs=3; //bahh il y a un joueur
    int compteurTour = 0;

    do
    {
        system("cls");
        affichagePlateau(tableauinvisible); //on appelle la fonction d'affichage du plateau
        gestionLettre(joueurun.pseudo, joueurun.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurun.pointsjoueur, langue, joueurs);  //on rentre dans la partie actionJoueur c'est l�-bas que toutes les actions se d�rouleront
         //Si le joueur n'a plus de lettres dans sa main on met un terme � la partie
        if((joueurun.mainjoueur[0]==100) && (joueurun.mainjoueur[1]==100) && (joueurun.mainjoueur[2]==100) && (joueurun.mainjoueur[3]==100) && (joueurun.mainjoueur[4]==100) && (joueurun.mainjoueur[5]==100) && (joueurun.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        system("cls"); //on nettoie l'�cran
        affichagePlateau(tableauinvisible); //on appelle la fonction d'affichage du plateau
        joueurun.tourjoueur++; //on ajoute un au nombre de tour du joueur
        sauvegardetroisjoueurs(); //appel du programme de sauvegarde des donn�es du joueur
        sauvegardepioche(pioche); //appel du programme de sauvegarde de la pioche
        sauvegardetableau(tableauinvisible);  //appel du programme de sauvegarde du tableau
        ///Le tour de chaque joueur est semblable et se d�roule donc exactement de la m�me mani�re
        gestionLettre(joueurdeux.pseudo, joueurdeux.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurdeux.pointsjoueur, langue, joueurs);
        if((joueurdeux.mainjoueur[0]==100) && (joueurdeux.mainjoueur[1]==100) && (joueurdeux.mainjoueur[2]==100) && (joueurdeux.mainjoueur[3]==100) && (joueurdeux.mainjoueur[4]==100) && (joueurdeux.mainjoueur[5]==100) && (joueurdeux.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        system("cls");
        affichagePlateau(tableauinvisible);
        joueurdeux.tourjoueur++;
        sauvegardetroisjoueurs();
        sauvegardepioche(pioche);
        sauvegardetableau(tableauinvisible);
        ///Le tour de chaque joueur est semblable et se d�roule donc exactement de la m�me mani�re
        gestionLettre(joueurtrois.pseudo, joueurtrois.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurtrois.pointsjoueur, langue, joueurs);
        if((joueurtrois.mainjoueur[0]==100) && (joueurtrois.mainjoueur[1]==100) && (joueurtrois.mainjoueur[2]==100) && (joueurtrois.mainjoueur[3]==100) && (joueurtrois.mainjoueur[4]==100) && (joueurtrois.mainjoueur[5]==100) && (joueurtrois.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        system("cls");
        affichagePlateau(tableauinvisible);
        joueurtrois.tourjoueur++;
        sauvegardetroisjoueurs();
        sauvegardepioche(pioche);
        sauvegardetableau(tableauinvisible);
        do
        {
            printf("Voici le score de %s : %d\n", joueurun.pseudo, joueurun.pointsjoueur);
            printf("Voici le score de %s : %d\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("Voici le score de %s : %d\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            printf("Pour passer au tour suivant : taper 1\n");
            printf("Pour sauvegarder et retourner au menu : taper 2\n");
            scanf("%d", &choix);
        }
        while(choix!=2 && choix!=1);
        system("cls");
        if(choix==2)
        {
            char pioche2 [2][27] =
            {
                {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?'},
                {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2}
            };
            menu(&joueurs, tableauinvisible, pioche2, &langue);
        }
        affichagePlateau(tableauinvisible);
    }
    while(partie==0);
    classement_finjoueurs(&joueurs, tableauinvisible, pioche, &langue);
}

//Lancement de la partie avec quatre joueurs
void modequatrejoueurs(char pioche[2][27], char tableauinvisible[15][15][2], int langue)
{
    int partie=0;  //cr�ation d'une variable partie qui permet l'arr�t de la partie lorsqu'elle est finie
    int choix;     //cr�ation d'une variable permettant le choix de continuer ou d'arr�ter la partie � la fin de chaque tour
    int joueurs=4; //bahh il y a un joueur
    int compteurTour = 0;

    do
    {
        system("cls");
        affichagePlateau(tableauinvisible); //on appelle la fonction d'affichage du plateau
        gestionLettre(joueurun.pseudo, joueurun.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurun.pointsjoueur, langue, joueurs);  //on rentre dans la partie actionJoueur c'est l�-bas que toutes les actions se d�rouleront
        //Si le joueur n'a plus de lettres dans sa main on met un terme � la partie
        if((joueurun.mainjoueur[0]==100) && (joueurun.mainjoueur[1]==100) && (joueurun.mainjoueur[2]==100) && (joueurun.mainjoueur[3]==100) && (joueurun.mainjoueur[4]==100) && (joueurun.mainjoueur[5]==100) && (joueurun.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        system("cls"); //on nettoie l'�cran
        affichagePlateau(tableauinvisible); //on appelle la fonction d'affichage du plateau
        joueurun.tourjoueur++; //on ajoute un au nombre de tour du joueur
        sauvegardequatrejoueurs(); //appel du programme de sauvegarde des donn�es du joueur
        sauvegardepioche(pioche); //appel du programme de sauvegarde de la pioche
        sauvegardetableau(tableauinvisible);  //appel du programme de sauvegarde du tableau
        ///Le tour de chaque joueur est semblable et se d�roule donc exactement de la m�me mani�re
        gestionLettre(joueurdeux.pseudo, joueurdeux.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurdeux.pointsjoueur, langue, joueurs);
         if((joueurdeux.mainjoueur[0]==100) && (joueurdeux.mainjoueur[1]==100) && (joueurdeux.mainjoueur[2]==100) && (joueurdeux.mainjoueur[3]==100) && (joueurdeux.mainjoueur[4]==100) && (joueurdeux.mainjoueur[5]==100) && (joueurdeux.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        system("cls");
        affichagePlateau(tableauinvisible);
        joueurdeux.tourjoueur++;
        sauvegardequatrejoueurs();
        sauvegardepioche(pioche);
        sauvegardetableau(tableauinvisible);
        gestionLettre(joueurtrois.pseudo, joueurtrois.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurtrois.pointsjoueur, langue, joueurs); //il faudra rajouter &points
        if((joueurtrois.mainjoueur[0]==100) && (joueurtrois.mainjoueur[1]==100) && (joueurtrois.mainjoueur[2]==100) && (joueurtrois.mainjoueur[3]==100) && (joueurtrois.mainjoueur[4]==100) && (joueurtrois.mainjoueur[5]==100) && (joueurtrois.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        system("cls");
        affichagePlateau(tableauinvisible);
        joueurtrois.tourjoueur++;
        sauvegardequatrejoueurs();
        sauvegardepioche(pioche);
        sauvegardetableau(tableauinvisible);
        gestionLettre(joueurquatre.pseudo, joueurquatre.mainjoueur, pioche, tableauinvisible, &partie, &compteurTour, &joueurquatre.pointsjoueur, langue, joueurs); //il faudra rajouter &points
        if((joueurquatre.mainjoueur[0]==100) && (joueurquatre.mainjoueur[1]==100) && (joueurquatre.mainjoueur[2]==100) && (joueurquatre.mainjoueur[3]==100) && (joueurquatre.mainjoueur[4]==100) && (joueurquatre.mainjoueur[5]==100) && (joueurquatre.mainjoueur[6]==100) ){
            partie=1;} //fin de la partie
        system("cls");
        affichagePlateau(tableauinvisible);
        joueurquatre.tourjoueur++;
        sauvegardequatrejoueurs();
        sauvegardepioche(pioche);
        sauvegardetableau(tableauinvisible);
        do
        {
            printf("Voici le score de %s : %d\n", joueurun.pseudo, joueurun.pointsjoueur);
            printf("Voici le score de %s : %d\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("Voici le score de %s : %d\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            printf("Voici le score de %s : %d\n", joueurquatre.pseudo, joueurquatre.pointsjoueur);
            printf("Pour passer au tour suivant : taper 1\n");
            printf("Pour sauvegarder et retourner au menu : taper 2\n");
            scanf("%d", &choix);
        }
        while(choix!=2 && choix!=1);
        system("cls");
        if(choix==2)
        {
            char pioche2 [2][27] =
            {
                {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?'},
                {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2}
            };
            menu(&joueurs, tableauinvisible, pioche2, &langue);
        }
        affichagePlateau(tableauinvisible);
    }
    while(partie==0);
    classement_finjoueurs(&joueurs, tableauinvisible, pioche, &langue);
}
