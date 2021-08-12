#include "header.h"

void nbrJoueurs(int *nombreJoueurs)
{ //l'utilisateur va pouvoir choisir le nombre de joueurs dans la partie
        //on va blinder la saisie du nombre entre 1 et 4 pour �viter que le joueur ne tente de lancer sans joueur ou avec trop de joueurs
        do {
            printf("Veuillez selectionner le nombre de joueurs\n");
            printf("Attention le nombre de joueurs maximum est de 4\n");
            fflush(stdin);
            scanf("%d", &*nombreJoueurs);
            system("cls");
        }while(*nombreJoueurs<1 || *nombreJoueurs>4); //la boucle se r�p�te selon ces conditions

}

///Dans le cas o� l'utilisateur lance une partie � un joueur
void unjoueur()
{
    printf("Veuillez rentrer votre pseudo\n"); //le joueur va pouvoir choisir son pseudo
    scanf("%s", joueurun.pseudo); //le pseudo du joueur est directement envoy� � sa structure
    printf("Bienvenue %s !\n", joueurun.pseudo); //on lui souhaite la bienvenue parcequ'on est des d�veloppeurs cools

    Sleep(3000); //petite pause du programme pour laisser � l'utilisateur le temps de lire le message de bienvenue
    system("cls"); //on nettoie l'�cran pour que le jeu reste propre
    printf("Nous allons donc vous lancer une partie a un joueur\n");
    Sleep(3000);
    system("cls");

    printf("---------------Mode solo----------------\n");

    //LANCEMENT DU JEU POUR 1 JOUEUR
}

///Dans le cas o� l'utilisateur lance une partie � deux joueurs
void deuxjoueurs()
{
    printf("Veuillez rentrer le pseudo du joueur 1\n");    //le joueur 1 va pouvoir choisir son pseudo
    scanf("%s", joueurun.pseudo);                          //le pseudo du joueur est directement envoy� � sa structure
    printf("Bienvenue %s !\n",joueurun.pseudo);
    printf("Veuillez rentrer le pseudo du joueur 2\n");    //le joueur 2 va pouvoir choisir son pseudo
    scanf("%s", joueurdeux.pseudo);
    printf("Bienvenue %s !\n",joueurdeux.pseudo);

    Sleep(3000);        //petite pause du programme pour laisser � l'utilisateur le temps de lire le message de bienvenue
    system("cls");      //on nettoie l'�cran pour que le jeu reste propre
    printf("Nous allons donc vous lancer une partie a deux joueurs\n");
    Sleep(3000);
    system("cls");

    printf("-------------Mode 2 joueurs-------------\n");

    //LANCEMENT DU JEU POUR 2 JOUEURS
}

///Dans le cas o� l'utilisateur lance une partie � trois joueurs
void troisjoueurs()
{
    printf("Veuillez rentrer le pseudo du joueur 1\n"); //le joueur 1 va pouvoir choisir son pseudo
    scanf("%s", joueurun.pseudo);                       //le pseudo du joueur est directement envoy� � sa structure
    printf("Bienvenue %s !\n", joueurun.pseudo);
    printf("Veuillez rentrer le pseudo du joueur 2\n"); //le joueur 2 va pouvoir choisir son pseudo
    scanf("%s", joueurdeux.pseudo);
    printf("Bienvenue %s !\n", joueurdeux.pseudo);
    printf("Veuillez rentrer le pseudo du joueur 3\n"); //le pseudo du joueur est directement envoy� � sa structure
    scanf("%s", joueurtrois.pseudo);
    printf("Bienvenue %s !\n", joueurtrois.pseudo);

    Sleep(3000);        //petite pause du programme pour laisser � l'utilisateur le temps de lire le message de bienvenue
    system("cls");      //on nettoie l'�cran pour que le jeu reste propre
    printf("Nous allons donc vous lancer une partie a trois joueurs\n");
    Sleep(3000);
    system("cls");

    printf("-------------Mode 3 joueurs-------------\n");

    //LANCEMENT DU JEU POUR 3 JOUEURS
}

///Dans le cas o� l'utilisateur lance une partie � quatre joueurs
void quatrejoueurs()
{
    printf("Veuillez rentrer le pseudo du joueur 1\n"); //le joueur 1 va pouvoir choisir son pseudo
    scanf("%s", joueurun.pseudo);                       //le pseudo du joueur est directement envoy� � sa structure
    printf("Bienvenue %s !\n", joueurun.pseudo);
    printf("Veuillez rentrer le pseudo du joueur 2\n"); //le joueurs 2 va pouvoir choisir son pseudo
    scanf("%s", joueurdeux.pseudo);
    printf("Bienvenue %s !\n", joueurdeux.pseudo);
    printf("Veuillez rentrer le pseudo du joueur 3\n"); //le joueurs 3 va pouvoir choisir son pseudo
    scanf("%s", joueurtrois.pseudo);
    printf("Bienvenue %s !\n", joueurtrois.pseudo);
    printf("Veuillez rentrer le pseudo du joueur 4\n"); //le joueurs 4 va pouvoir choisir son pseudo
    scanf("%s", joueurquatre.pseudo);
    printf("Bienvenue %s !\n", joueurquatre.pseudo);

    Sleep(3000);        //petite pause du programme pour laisser � l'utilisateur le temps de lire le message de bienvenue
    system("cls");      //on nettoie l'�cran pour que le jeu reste propre
    printf("Nous allons donc vous lancer une partie a quatre joueurs\n");
    Sleep(3000);
    system("cls");

    printf("-------------Mode 4 joueurs-------------\n");

    //LANCEMENT DU JEU POUR 4 JOUEURS
}

//Organisation du lancement des parties en fonction du nombre de joueurs
void PseudosJoueurs(int *joueurs)
{

    nbrJoueurs(&*joueurs);  //on appelle la fonction nbrJoueurs en lui passant par pointeur la variable contenant le nombre de joueurs

    if(*joueurs==1)
        unjoueur(*joueurs); //on appelle la fonction de saisi du pseudo du joueur
    if(*joueurs==2)
        deuxjoueurs(*joueurs); //on appelle la fonction de saisi des pseudo des joueurs
    if(*joueurs==3)
        troisjoueurs(*joueurs); //on appelle la fonction de saisi des pseudo des joueurs
    if(*joueurs==4)
        quatrejoueurs(*joueurs); //on appelle la fonction de saisi des pseudo des joueurs

    printf("Nous vous souhaitons une agreable partie\n"); //Si on est si poli c'est parcequ'on est vraiment des codeurs cools
    Sleep(3000);       //pause dans le programme pour pouvoir tout lire avec le nettoyage de l'�cran
    system("cls");     //nettoyage de l'�cran

    //maintenant on sera redirig� vers le choix des langues
}
