#include "header.h"

//Procédure d'affichage des regles du jeux
void affichageRegle()
{
    system("cls");
    printf("---------------REGLES---------------\n\n");

    printf("Le but du jeux est de marque le plus de points possible.\n\nPour cela, essayez de placer des mots dans la grilles avec les lettres de votre mains et celles de la grille.");
    printf("\n\nIl existe des multiplicateurs qui vous permettent de marquer encore plus de points :\n");
    printf("\t - ");
    {
        Color(15,3);    //On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("&");
    }
    Color(15,0);       //retour aux couleurs normales de la console
    printf("ce caractere represente une case \"lettre compte double\", les points de la lettre sont donc doubles\n");
    printf("\t - ");
    {
        Color(15,1);    //On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("%%");
    }
    Color(15,0);       //retour aux couleurs normales de la console
    printf("ce caractere represente une case \"lettre compte triple\", les points de la lettre sont donc triples\n");
    printf("\t - ");
    {
        Color(15,12);   //On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("@");
    }
    Color(15,0);       //retour aux couleurs normales de la console
    printf("ce caractere represente une case \"mot compte double\", les points du mot sont donc doubles\n");
    printf("\t - ");
    {
        Color(15,4);    //On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("§");
    }
    Color(15,0);       //retour aux couleurs normales de la console
    printf("ce caractere represente une case \"mot compte triple\", les points du mot sont donc triples\n");
    printf("\nLorsque c'est a vous de jouer, vous pouvez :\n");
    printf("\t - placer un mot dans la grille\n");
    printf("\t - changer toutes vos lettres et passer votre tour\n");
    printf("\t - passer votre tour\n");
    printf("\nLes scores se comptent a chaque fois qu'un joueur place un mot.\n");
    printf("La partie s'acheve quand le sac est vide et qu'un joueur place ses dernieres lettres sur la grille.\nIl ajoute a son score la valeur des lettres restant a ses adversaires, qui dans le meme temps, doivent deduire de leur score la valeur des lettres qui leur restent.\n");
}

//Prpose le menu au joueurs et lance la partie selon les modes de jeux choisis
void menu(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue)         ///menu d'entree de jeu
{
    int choix;
    int retour;
    do //permet de gérer l'affichage du menu et blinde la sélection
    {
        system("cls");
        printf("---------------MENU---------------\n");
        printf("\n");
        printf("\n");
        printf("1 - Lancer une nouvelle partie\n");
        printf("\n");
        printf("2 - Lancer une partie quittee precedement\n");
        printf("\n");
        printf("3 - Afficher l'aide\n");
        printf("\n");
        printf("4 - Afficher les scores des joueurs\n");
        printf("\n");
        printf("5 - Quitter le jeu\n");
        printf("\n");
        printf("        Entrez votre choix : ");
        fflush(stdin);
        scanf("%d", &choix);
        printf("\n");
        if(choix == 1)
        {
            PseudosJoueurs(&*joueurs); //permet au joueur de choisir le nombre de joueurs et le(s) pseudo(s) du(es) joueur(s)
            system("cls"); //nettoie la console
            Sleep(15);
            remplitableauinvisible(tableauinvisible); //on appelle la fonction de remplissage du tableau
            choixlangue(&*langue);
            sauvegardepartie(&*joueurs, tableauinvisible, &*langue);
            if(*joueurs==1)
                modesolo(pioche, tableauinvisible, *langue);
            else if(*joueurs==2)
                modedeuxjoueurs(pioche,tableauinvisible, *langue);
            else if(*joueurs==3)
                modetroisjoueurs(pioche, tableauinvisible, *langue);
            else if(*joueurs==4)
                modequatrejoueurs(pioche, tableauinvisible, *langue);

        }
        if(choix == 2)///lancer une partie sauvegardee
        {
            remplitableauinvisible(tableauinvisible); //on appelle la fonction de remplissage du tableau
            anciennepartie(&*joueurs, tableauinvisible, pioche, &*langue); //on récupère les données de l'ancienne partie
        }
        if(choix == 3)
        {
            printf("\n");
            affichageRegle(); //on appelle le programme d'affichage des règles
            do
            {
                printf("Pour retourner au menu veuillez saisir 1 :");
                fflush(stdin);
                scanf("%d", &retour); //permet de savoir quand le joueur aura fini de lire et voudra retourner au menu
            }
            while(retour != 1);
            if(retour == 1)
            {
                system("CLS");
                menu(&*joueurs, tableauinvisible, pioche, &*langue); //retour au menu
            }
        }
        if(choix == 4)
        {
            printf("Nous allons vous afficher le score des joueurs\n");
            anciennbjoueurs(&*joueurs, tableauinvisible, pioche, &*langue);
            if(*joueurs==1){
                    anciennepartiesolo(&*joueurs, tableauinvisible, pioche, &*langue);
            }
            if(*joueurs==2){
                    anciennepartiedeux(&*joueurs, tableauinvisible, pioche, &*langue);
            }
            if(*joueurs==3){
                    anciennepartietrois(&*joueurs, tableauinvisible, pioche, &*langue);
            }
            if(*joueurs==4){
                    anciennepartiequatre(&*joueurs, tableauinvisible, pioche, &*langue);
            }
            classement_encoursjoueurs(&*joueurs, tableauinvisible, pioche, &*langue); //affichage de tous les scores obtenus dans cette version du scrabble
        }
        if(choix == 5)
        {
            Sleep(100);
            system("CLS");
            printf("Merci d'avoir utiliser notre jeu ! A bientot\n");       //On dit au revoir car on est vraiment des développeurs coooooools
            printf("On vous laisse quitter le programme ;)\n");
            Sleep(500000);
        }
        if(choix == 404)
        {
            system("curl parrot.live");
        }
    }while(choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix!=404  );
}

//Permet d'afficher la pioche et le nombre d'occurences de chaques lettres
//Fonction jamais appellée dans le jeux permet de verifier le bon fonctionnement de la pioche
void affichagePioche(char tab[2][27])
{
    int j;
    printf("\n");
    for (j=0; j<27; j++)
    {
        printf("%c", tab[0][j]);
    }
    printf("\n");
    for (j=0; j<27; j++)
    {
        printf("%d", tab[1][j]);
    }
    printf("\n");
}

//Permet d'afficher la main du joueur
void affichageMain(char chevalet[7])
{
    int j;
    ///Affichage de la main
    printf("\nVotre main est : ");
    for(j=0; j<7; j++)
    {
        printf("%c   ", chevalet[j]);
    }
    printf("\n");
}

//Permet d'afficher un historique du score des meilleurs joueurs
void classement_finjoueurs(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue)
{
    ///Le classement joueur est seulement un ensemble de printf et de if, il étudie les différents scénarios possibles pour donner les joueurs dans l'ordre des gagnants
    system("cls");
    ///Voici le premier exemple commenté, les autres suivent le même principe
    if(*joueurs==1) //dans le cas où il n'y a qu'un joueur on donne son nombre de points
    {
        printf("Bravo %s , la partie est terminee\n", joueurun.pseudo);
        printf("Ton score est honorable il est de : %d !!!\n", joueurun.pointsjoueur); //On le félicite parcequ'on est vraiment des codeurs coooools
    }
    if(*joueurs==2) //dans le cas où il y a deux joueurs
    {
        printf("Bravo, la partie est terminee\n");
        if(joueurun.pointsjoueur > joueurdeux.pointsjoueur) //Si le joueurun a plus de points que le joueurdeux
        {
            printf("%s a gagne avec un score de : %d points\n", joueurun.pseudo, joueurun.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
        }
        else //Si c'est le joueurdeux qui a le plus de points
        {
            printf("%s a gagne avec un score de : %d points\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurun.pseudo, joueurun.pointsjoueur);
        }
    }
    if(*joueurs==3)
    {
        if(joueurun.pointsjoueur > joueurdeux.pointsjoueur && joueurun.pointsjoueur > joueurtrois.pointsjoueur)
        {
            printf("%s a gagne avec un score de : %d points\n", joueurun.pseudo, joueurun.pointsjoueur);
            if(joueurdeux.pointsjoueur > joueurtrois.pointsjoueur)
            {
                printf("%s fini deuxieme avec un score de : %d points\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
                printf("%s bravo a toi aussi, tu es troisieme, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            }
            else if(joueurtrois.pointsjoueur > joueurdeux.pointsjoueur)
            {
                printf("%s fini deuxieme avec un score de : %d points\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
                printf("%s bravo a toi aussi, tu es troisieme, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            }
        }
        else if (joueurdeux.pointsjoueur > joueurun.pointsjoueur && joueurdeux.pointsjoueur > joueurtrois.pointsjoueur)
        {
            printf("%s a gagne avec un score de : %d points\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            if(joueurun.pointsjoueur > joueurtrois.pointsjoueur)
            {
                printf("%s fini deuxieme avec un score de : %d points\n", joueurun.pseudo, joueurun.pointsjoueur);
                printf("%s bravo a toi aussi, tu es troisieme, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            }
            else if(joueurtrois.pointsjoueur > joueurun.pointsjoueur)
            {
                printf("%s fini deuxieme avec un score de : %d points\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
                printf("%s bravo a toi aussi, tu es troisieme, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurun.pseudo, joueurun.pointsjoueur);
            }
        }
        else if (joueurtrois.pointsjoueur > joueurun.pointsjoueur && joueurtrois.pointsjoueur > joueurdeux.pointsjoueur)
        {
            printf("%s a gagne avec un score de : %d points\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            printf("%s a gagne avec un score de : %d points\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            if(joueurun.pointsjoueur > joueurdeux.pointsjoueur)
            {
                printf("%s fini deuxieme avec un score de : %d points\n", joueurun.pseudo, joueurun.pointsjoueur);
                printf("%s bravo a toi aussi, tu es troisieme, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            }
            else if(joueurdeux.pointsjoueur > joueurun.pointsjoueur)
            {
                printf("%s fini deuxieme avec un score de : %d points\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
                printf("%s bravo a toi aussi, tu es troisieme, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurun.pseudo, joueurun.pointsjoueur);
            }
        }
    }
    if(*joueurs==4)
    {
        if(joueurun.pointsjoueur > joueurdeux.pointsjoueur && joueurun.pointsjoueur > joueurtrois.pointsjoueur && joueurun.pointsjoueur > joueurquatre.pointsjoueur)
        {
            printf("%s a gagne avec un score de : %d points\n", joueurun.pseudo, joueurun.pointsjoueur );
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurquatre.pseudo, joueurquatre.pointsjoueur);
        }
        else if (joueurdeux.pointsjoueur > joueurun.pointsjoueur && joueurdeux.pointsjoueur > joueurtrois.pointsjoueur && joueurdeux.pointsjoueur > joueurquatre.pointsjoueur)
        {
            printf("%s a gagne avec un score de : %d points\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurun.pseudo, joueurun.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurquatre.pseudo, joueurquatre.pointsjoueur);
        }
        else if (joueurtrois.pointsjoueur > joueurun.pointsjoueur && joueurtrois.pointsjoueur > joueurdeux.pointsjoueur && joueurtrois.pointsjoueur > joueurquatre.pointsjoueur)
        {
            printf("%s a gagne avec un score de : %d points\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurun.pseudo, joueurun.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurquatre.pseudo, joueurquatre.pointsjoueur);
        }
        else if (joueurquatre.pointsjoueur > joueurun.pointsjoueur && joueurquatre.pointsjoueur > joueurdeux.pointsjoueur && joueurquatre.pointsjoueur > joueurtrois.pointsjoueur)
        {
            printf("%s a gagne avec un score de : %d points\n", joueurquatre.pseudo, joueurquatre.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurun.pseudo, joueurun.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("%s bravo a toi aussi, tu as %d points ! tu gagneras peut-etre la prochaine fois !\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
        }
    }
    int retour=0;
    do
    {
        printf("\n\n\n\n\n\n\nPour retourner au menu veuillez saisir 1 :");
        scanf("%d", &retour);
    }
    while(retour != 1);
    if(retour == 1)
    {
        //Si le joueur retourne au menu alors on remplit à nouveau la pioche pour une nouvelle partie
        char pioche [2][27] =
        {
            {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?'},
            {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2}
        };
        system("CLS");
        menu(&*joueurs, tableauinvisible, pioche, &*langue); //retour au menu
    }



}

//Permet de proposer un classement des joueurs durant une partie
void classement_encoursjoueurs(int *joueurs, char tableauinvisible[15][15][2], char pioche[2][27], int *langue)
{
    ///Le classement joueur est seulement un ensemble de printf et de if, il étudie les différents scénarios possibles pour donner les joueurs dans l'ordre des gagnants
    system("cls");
    ///Voici le premier exemple commenté, les autres suivent le même principe
    if(*joueurs==1) //dans le cas où il n'y a qu'un joueur on donne son nombre de points
    {
        printf("Bravo %s\n", joueurun.pseudo);
        printf("Ton score est honorable il est de : %d !!!\n\n", joueurun.pointsjoueur); //On le félicite parcequ'on est vraiment des codeurs coooools
    }
    if(*joueurs==2) //dans le cas où il y a deux joueurs
    {
        if(joueurun.pointsjoueur > joueurdeux.pointsjoueur) //Si le joueurun a plus de points que le joueurdeux
        {
            Color(0,14);
            printf("  ");
            Color(15,0);
            printf("%s est premier avec un score de : %d points!\n\n", joueurun.pseudo, joueurun.pointsjoueur);
            Color(0,7);
            printf("  ");
            Color(15,0);
            printf("%s est deuxieme avec un score de %d points !\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
        }
        else //Si c'est le joueurdeux qui a le plus de points
        {
            Color(0,14);
            printf("  ");
            Color(15,0);
            printf("%s est premier avec un score de : %d points!\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            Color(0,7);
            printf("  ");
            Color(15,0);
            printf("%s est deuxieme avec un score de %d points !\n\n", joueurun.pseudo, joueurun.pointsjoueur);
        }
    }
    if(*joueurs==3)
    {
        if(joueurun.pointsjoueur > joueurdeux.pointsjoueur && joueurun.pointsjoueur > joueurtrois.pointsjoueur)
        {
            Color(0,14);
            printf("  ");
            Color(15,0);
            printf("%s est premier avec un score de : %d points!\n\n", joueurun.pseudo, joueurun.pointsjoueur);
            if(joueurdeux.pointsjoueur > joueurtrois.pointsjoueur)
            {
                Color(0,7);
            printf("  ");
            Color(15,0);
                printf("%s est deuxieme avec un score de %d points !\n\n", joueurun.pseudo, joueurun.pointsjoueur);
                Color(0,4);
            printf("  ");
            Color(15,0);
                printf("%s est troisieme avec un score de %d points !\n\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            }
            else if(joueurtrois.pointsjoueur > joueurdeux.pointsjoueur)
            {
                Color(0,7);
            printf("  ");
            Color(15,0);
                printf("%s est deuxieme avec un score de %d points !\n\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
                Color(0,4);
            printf("  ");
            Color(15,0);
                printf("%s est troisieme avec un score de %d points !\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            }
        }
        else if (joueurdeux.pointsjoueur > joueurun.pointsjoueur && joueurdeux.pointsjoueur > joueurtrois.pointsjoueur)
        {
            Color(0,14);
            printf("  ");
            Color(15,0);
            printf("%s est premier avec un score de : %d points!\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            if(joueurun.pointsjoueur > joueurtrois.pointsjoueur)
            {
                Color(0,7);
            printf("  ");
            Color(15,0);
                printf("%s est deuxieme avec un score de %d points !\n\n", joueurun.pseudo, joueurun.pointsjoueur);
                Color(0,4);
            printf("  ");
            Color(15,0);
                printf("%s est troisieme avec un score de %d points !\n\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            }
            else if(joueurtrois.pointsjoueur > joueurun.pointsjoueur)
            {
                Color(0,7);
            printf("  ");
            Color(15,0);
                printf("%s est deuxieme avec un score de %d points !\n\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
                Color(0,4);
            printf("  ");
            Color(15,0);
                printf("%s est troisieme avec un score de %d points !\n\n", joueurun.pseudo, joueurun.pointsjoueur);
            }
        }
        else if (joueurtrois.pointsjoueur > joueurun.pointsjoueur && joueurtrois.pointsjoueur > joueurdeux.pointsjoueur)
        {
            Color(0,14);
            printf("  ");
            Color(15,0);
            printf("%s est premier avec un score de : %d points!\n\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            if(joueurun.pointsjoueur > joueurdeux.pointsjoueur)
            {
                Color(0,7);
            printf("  ");
            Color(15,0);
                printf("%s est deuxieme avec un score de %d points !\n\n", joueurun.pseudo, joueurun.pointsjoueur);
                Color(0,4);
            printf("  ");
            Color(15,0);
                printf("%s est troisieme avec un score de %d points !\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            }
            else if(joueurdeux.pointsjoueur > joueurun.pointsjoueur)
            {
                Color(0,7);
            printf("  ");
            Color(15,0);
                printf("%s est deuxieme avec un score de %d points !\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
                Color(0,4);
            printf("  ");
            Color(15,0);
                printf("%s est troisieme avec un score de %d points !\n\n", joueurun.pseudo, joueurun.pointsjoueur);
            }
        }
    }
    if(*joueurs==4)
    {
        if(joueurun.pointsjoueur > joueurdeux.pointsjoueur && joueurun.pointsjoueur > joueurtrois.pointsjoueur && joueurun.pointsjoueur > joueurquatre.pointsjoueur)
        {
            Color(0,14);
            printf("  ");
            Color(15,0);
            printf("%s est premier avec un score de : %d points!\n\n", joueurun.pseudo, joueurun.pointsjoueur );
            Color(0,7);
            printf("  ");
            Color(15,0);
            printf("%s est deuxieme avec un score de %d points !\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            Color(0,4);
            printf("  ");
            Color(15,0);
            printf("%s est troisieme avec un score de %d points !\n\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            printf("%s est quatrieme avec un score de %d points !\n\n", joueurquatre.pseudo, joueurquatre.pointsjoueur);
        }
        else if (joueurdeux.pointsjoueur > joueurun.pointsjoueur && joueurdeux.pointsjoueur > joueurtrois.pointsjoueur && joueurdeux.pointsjoueur > joueurquatre.pointsjoueur)
        {
            Color(0,14);
            printf("  ");
            Color(15,0);
            printf("%s est premier avec un score de : %d points!\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            Color(0,7);
            printf("  ");
            Color(15,0);
            printf("%s est deuxieme avec un score de %d points !\n\n", joueurun.pseudo, joueurun.pointsjoueur);
            Color(0,4);
            printf("  ");
            Color(15,0);
            printf("%s est troisieme avec un score de %d points !\n\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            printf("%s est quatrieme avec un score de %d points !\n\n", joueurquatre.pseudo, joueurquatre.pointsjoueur);
        }
        else if (joueurtrois.pointsjoueur > joueurun.pointsjoueur && joueurtrois.pointsjoueur > joueurdeux.pointsjoueur && joueurtrois.pointsjoueur > joueurquatre.pointsjoueur)
        {
            Color(0,14);
            printf("  ");
            Color(15,0);
            printf("%s est premier avec un score de : %d points!\n\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
            Color(0,7);
            printf("  ");
            Color(15,0);
            printf("%s est deuxieme avec un score de %d points !\n\n", joueurun.pseudo, joueurun.pointsjoueur);
            Color(0,4);
            printf("  ");
            Color(15,0);
            printf("%s est troisieme avec un score de %d points !\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("%s est quatrieme avec un score de %d points !\n\n", joueurquatre.pseudo, joueurquatre.pointsjoueur);
        }
        else if (joueurquatre.pointsjoueur > joueurun.pointsjoueur && joueurquatre.pointsjoueur > joueurdeux.pointsjoueur && joueurquatre.pointsjoueur > joueurtrois.pointsjoueur)
        {
            Color(0,14);
            printf("  ");
            Color(15,0);
            printf("%s est premier avec un score de : %d points!\n\n", joueurquatre.pseudo, joueurquatre.pointsjoueur);
            Color(0,7);
            printf("  ");
            Color(15,0);
            printf("%s est deuxieme avec un score de %d points !\n\n", joueurun.pseudo, joueurun.pointsjoueur);
            Color(0,4);
            printf("  ");
            Color(15,0);
            printf("%s est troisieme avec un score de %d points !\n\n", joueurdeux.pseudo, joueurdeux.pointsjoueur);
            printf("%s est quatrieme avec un score de %d points !\n\n", joueurtrois.pseudo, joueurtrois.pointsjoueur);
        }
    }
    int retour=0;
    do
    {
        printf("\n\n\n\n\n\n\nPour retourner au menu veuillez saisir 1 :");
        scanf("%d", &retour);
    }
    while(retour != 1);
    if(retour == 1)
    {
        //Si le joueur retourne au menu alors on remplit à nouveau la pioche pour une nouvelle partie
        char pioche [2][27] =
        {
            {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?'},
            {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2}
        };
        system("CLS");
        menu(&*joueurs, tableauinvisible, pioche, &*langue); //retour au menu
    }



}


//gestion des couleurs de la console
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs donnée sur campus
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

//permet d'affiche le plateau
void affichagePlateau(char tableau[15][15][2])
{
    /// Le plateau :


    printf("     A   B   C   D   E   F   G   H   I   J   K   L   M   N   O\n");
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xDA,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xC2,0xC4,0xC4,0xC4,0xBF);

    ///LIGNE 1              TOUTES LES LIGNES FONCTIONNENT DE LA MEME MANIERE
    printf("1  %c", 0xB3);
    {
        Color(15,4);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("§%c ", tableau[0][0][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c %c %c %c %c",0xB3, tableau[0][1][0],0xB3, tableau[0][2][0],0xB3);
    {
        Color(15,3);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("&%c ", tableau[0][3][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c %c %c %c %c %c %c",0xB3,tableau[0][4][0], 0xB3,tableau[0][5][0],0xB3,tableau[0][6][0],0xB3);
    {
        Color(15,4);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("§%c ", tableau[0][7][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c %c %c %c %c %c %c",0xB3,tableau[0][8][0],0xB3,tableau[0][9][0],0xB3,tableau[0][10][0],0xB3);
    {
        Color(15,3);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("&%c ", tableau[0][11][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c %c %c %c %c",0xB3,tableau[0][12][0],0xB3,tableau[0][13][0],0xB3);
    {
        Color(15,4);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("§%c ",tableau[0][14][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c \n",0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 2
    printf("2  %c %c %c", 0xB3,tableau[1][0][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[1][1][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c", 0xB3,tableau[1][2][0],0xB3,tableau[1][3][0],0xB3,tableau[1][4][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[1][5][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[1][6][0],0xB3,tableau[1][7][0],0xB3,tableau[1][8][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[1][9][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[1][10][0],0xB3,tableau[1][11][0],0xB3,tableau[1][12][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[1][13][0]);
    }
    Color(15,0);
    printf("%c %c %c \n",0xB3,tableau[1][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 3
    printf("3  %c %c %c %c %c", 0xB3,tableau[2][0][0],0xB3,tableau[2][1][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[2][2][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[2][3][0],0xB3,tableau[2][4][0],0xB3,tableau[2][5][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[2][6][0]);
    }
    Color(15,0);
    printf("%c %c %c",0xB3,tableau[2][7][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[2][8][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[2][9][0],0xB3,tableau[2][10][0],0xB3,tableau[2][11][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[2][12][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c \n",0xB3,tableau[2][13][0],0xB3,tableau[2][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 4
    printf("4  %c",0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[3][0][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c", 0xB3,tableau[3][1][0],0xB3,tableau[3][2][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[3][3][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[3][4][0],0xB3,tableau[3][5][0],0xB3,tableau[3][6][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[3][7][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[3][8][0],0xB3,tableau[3][9][0],0xB3,tableau[3][10][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[3][11][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c",0xB3,tableau[3][12][0],0xB3,tableau[3][13][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[3][14][0]);
    }
    Color(15,0);
    printf("%c \n",0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 5
    printf("5  %c %c %c %c %c %c %c %c %c", 0xB3,tableau[4][0][0],0xB3,tableau[4][1][0],0xB3,tableau[4][2][0],0xB3,tableau[4][3][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[4][4][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c %c %c %c %c",0xB3,tableau[4][5][0],0xB3,tableau[4][6][0],0xB3,tableau[4][7][0],0xB3,tableau[4][8][0],0xB3,tableau[4][9][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[4][10][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c %c %c \n",0xB3,tableau[4][11][0],0xB3,tableau[4][12][0],0xB3,tableau[4][13][0],0xB3,tableau[4][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 6
    printf("6  %c %c %c", 0xB3,tableau[5][0][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[5][1][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[5][2][0],0xB3,tableau[5][3][0],0xB3,tableau[5][4][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[5][5][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[5][6][0],0xB3,tableau[5][7][0],0xB3,tableau[5][8][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[5][9][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[5][10][0],0xB3,tableau[5][11][0],0xB3,tableau[5][12][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[5][13][0]);
    }
    Color(15,0);
    printf("%c %c %c \n",0xB3,tableau[5][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 7
    printf("7  %c %c %c %c %c", 0xB3,tableau[6][0][0],0xB3,tableau[6][1][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[6][2][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[6][3][0],0xB3,tableau[6][4][0],0xB3,tableau[6][5][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[6][6][0]);
    }
    Color(15,0);
    printf("%c %c %c",0xB3,tableau[6][7][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[6][8][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[6][9][0],0xB3,tableau[6][10][0],0xB3,tableau[6][11][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[6][12][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c \n",0xB3,tableau[6][13][0],0xB3,tableau[6][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 8
    printf("8  %c",0xB3);
    {
        Color(15,4);
        printf("§%c ",tableau[7][0][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c", 0xB3,tableau[7][1][0],0xB3,tableau[7][2][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[7][3][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[7][4][0],0xB3,tableau[7][5][0],0xB3,tableau[7][6][0],0xB3);
    {
        Color(15,6);
        printf("#%c ",tableau[7][7][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[7][8][0],0xB3,tableau[7][9][0],0xB3,tableau[7][10][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[7][11][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c", 0xB3,tableau[7][12][0],0xB3,tableau[7][13][0],0xB3);
    {
        Color(15,4);
        printf("§%c ",tableau[7][14][0]);
    }
    Color(15,0);
    printf("%c \n",0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 9
    printf("9  %c %c %c %c %c", 0xB3,tableau[8][0][0],0xB3,tableau[8][1][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[8][2][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[8][3][0],0xB3,tableau[8][4][0],0xB3,tableau[8][5][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[8][6][0]);
    }
    Color(15,0);
    printf("%c %c %c",0xB3,tableau[8][7][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[8][8][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[8][9][0],0xB3,tableau[8][10][0],0xB3,tableau[8][11][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[8][12][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c \n",0xB3,tableau[8][13][0],0xB3,tableau[8][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 10
    printf("10 %c %c %c", 0xB3,tableau[9][0][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[9][1][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[9][2][0],0xB3,tableau[9][3][0],0xB3,tableau[9][4][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[9][5][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[9][6][0],0xB3,tableau[9][7][0],0xB3,tableau[9][8][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[9][9][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[9][10][0],0xB3,tableau[9][11][0],0xB3,tableau[9][12][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[9][13][0]);
    }
    Color(15,0);
    printf("%c %c %c \n",0xB3,tableau[9][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 11
    printf("11 %c %c %c %c %c %c %c %c %c", 0xB3,tableau[10][0][0],0xB3,tableau[10][1][0],0xB3,tableau[10][2][0],0xB3,tableau[10][3][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[10][4][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c %c %c %c %c",0xB3,tableau[10][5][0],0xB3,tableau[10][6][0],0xB3,tableau[10][7][0],0xB3,tableau[10][8][0],0xB3,tableau[10][9][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[10][10][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c %c %c \n",0xB3,tableau[10][11][0],0xB3,tableau[10][12][0],0xB3,tableau[10][13][0],0xB3,tableau[10][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 12
    printf("12 %c",0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[11][0][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c", 0xB3,tableau[11][1][0],0xB3,tableau[11][2][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[11][3][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[11][4][0],0xB3,tableau[11][5][0],0xB3,tableau[11][6][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[11][7][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[11][8][0],0xB3,tableau[11][9][0],0xB3,tableau[11][10][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[10][11][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c",0xB3,tableau[10][12][0],0xB3,tableau[10][13][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[10][14][0]);
    }
    Color(15,0);
    printf("%c \n",0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 13
    printf("13 %c %c %c %c %c", 0xB3,tableau[12][0][0],0xB3,tableau[12][1][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[12][2][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[12][3][0],0xB3,tableau[12][4][0],0xB3,tableau[12][5][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[12][6][0]);
    }
    Color(15,0);
    printf("%c %c %c",0xB3,tableau[12][7][0],0xB3);
    {
        Color(15,3);
        printf("&%c ",tableau[12][8][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[12][9][0],0xB3,tableau[12][10][0],0xB3,tableau[12][11][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[12][12][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c \n",0xB3,tableau[12][13][0],0xB3,tableau[12][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 14
    printf("14 %c %c %c", 0xB3,tableau[13][0][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[13][1][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c", 0xB3,tableau[13][2][0],0xB3,tableau[13][3][0],0xB3,tableau[13][4][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[13][5][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[13][6][0],0xB3,tableau[13][7][0],0xB3,tableau[13][8][0],0xB3);
    {
        Color(15,1);
        printf("%%%c ",tableau[13][9][0]);
    }
    Color(15,0);
    printf("%c %c %c %c %c %c %c",0xB3,tableau[13][10][0],0xB3,tableau[13][11][0],0xB3,tableau[13][12][0],0xB3);
    {
        Color(15,12);
        printf("@%c ",tableau[13][13][0]);
    }
    Color(15,0);
    printf("%c %c %c \n",0xB3,tableau[13][14][0],0xB3);
    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC3,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xC5,0xC4,0xC4,0xC4,0xB4);

    ///LIGNE 15

    printf("15 %c", 0xB3);
    {
        Color(15,4);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("§%c ", tableau[14][0][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c %c %c %c %c",0xB3, tableau[14][1][0],0xB3, tableau[14][2][0],0xB3);
    {
        Color(15,3);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("&%c ", tableau[14][3][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c %c %c %c %c %c %c",0xB3,tableau[14][4][0], 0xB3,tableau[14][5][0],0xB3,tableau[14][6][0],0xB3);
    {
        Color(15,4);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("§%c ", tableau[14][7][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c %c %c %c %c %c %c",0xB3,tableau[14][8][0],0xB3,tableau[14][9][0],0xB3,tableau[14][10][0],0xB3);
    {
        Color(15,3);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("&%c ", tableau[14][11][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c %c %c %c %c",0xB3,tableau[14][12][0],0xB3,tableau[14][13][0],0xB3);
    {
        Color(15,4);//On modifie la couleur de la console pour afficher le caractère spécial sur un fond de couleur
        printf("§%c ",tableau[14][14][0]);
    }
    Color(15,0);//retour aux couleurs normales de la console
    printf("%c \n",0xB3);

    printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 0xC0,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xC1,0xC4,0xC4,0xC4,0xD9);

}
