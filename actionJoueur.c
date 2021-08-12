#include "header.h"


//fonction qui gère le tour d'un joueur
void gestionLettre(char joueur[20], char mainJoueur[7], char pioche[2][27], char tableauinvisible[15][15][2], int *partie, int *compteurTour, int *pointstotaux, int langue, int nbJoueurs)
{
    printf("\nC'est le tour de : %s\n", joueur);
    srand(time(NULL));
    //Debut de partie
    remplirMain(pioche, mainJoueur);                //a repeter pour chaque joueur

    //Debut du tour d'un joueur
    actionJ(pioche, mainJoueur, tableauinvisible, &*compteurTour, &*pointstotaux, langue, nbJoueurs);
    Sleep(3000);

    if (mainJoueur[0]=='\0')
    {
        *partie=1;
    }
}

///FONCTION DE JEUX
//fonction de placement de mot horizontalement
void placerMotH(char mot[15], int coordX, int coordY, char tablo[15][15][2])
{
    int i;
    int stock;
    coordX = coordX;
    coordY = coordY - 1;

    stock = strlen(mot);

    for(i=0; i<stock; i++)
    {
        tablo[coordY][coordX+i][0] = mot[i];
    }

}
//fonction de placement de mot verticalement
void placerMotV(char mot[15], int coordX, int coordY, char tablo[15][15][2])
{
    int i;
    int stock;

    coordX = coordX;
    coordY = coordY-1;
    stock = strlen(mot);

    for(i=0; i<stock; i++)
    {
        tablo[coordY+i][coordX][0] = mot[i];
    }


}

//Actions possibles pour un joueur au début de son tour
void actionJ (char pioche [2][27], char mainJoueur[7], char tableauinvisible[15][15][2], int *compteurTour, int *pointstotaux, int langue, int nbJoueurs)
{
    int choix;
    do
    {
        printf("\nQue voulez-vous faire ?\n1. Saisir un mot\n2. Passer votre tour\n3. Changer des lettres de votre chevalet et passer votre tour\n");
        fflush(stdin);
        scanf("%d", &choix);
    }
    while (choix<1 || choix>3);
    //Saisir un mot
    if(choix == 1)
    {
        saisieMot(mainJoueur, pioche, tableauinvisible, &*compteurTour, &*pointstotaux, langue, nbJoueurs);
    }
    //Passer son tour
    if(choix == 2)
    {
        //passer son tour
        Sleep(10);
    }
    //Changer des lettres de son chevalet
    if(choix == 3)
    {
        changerMain(pioche, mainJoueur);
    }

    printf("\nVotre tour est fini, au joueur suivant !\n");
}

//Remplissage aleatoire de la chevalet d'un joueur
void remplirMain (char pioche [2][27], char chevalet[7])
{
    //Declaration
    int j, alea;
    //On genere la main d'un joueur
    while(strlen(chevalet)<7)
    {
        do
        {
            alea = rand()%(27);                     //on genere un nombre aleatoire pour piocher dans le sac au hasard
        }
        while (pioche [1][alea] <= 0);              //tant que le nombre alea ne correspond pas a une lettre presente dans le sac, on en genere un autre nb alea
        if (pioche[1][alea]> 0)                     //on verifie que la lettre correspondante au nombre alea est presente dans la pioche
        {
            chevalet[j] = pioche[0][alea];              //si la lettre est dans la pioche on la stock sur le chevalet du joueur
            pioche[1][alea] = pioche[1][alea] -1;   //et on retire 1 au compteur associe a la lettre
        }
        j++;
    }
    //Affichage
    affichageMain(chevalet);
}

//Permet de changer le nb de lettres que l'on veut depuis son chevalet
void changerMain(char pioche [2][27], char chevalet[7])
{
    //Declaration
    int i, k, alea, nbChange;
    int rangJeton;
    char lettre;

    //Changement de une lettre ou +
    do
    {
        printf("Combien de lettres voulez vous changer ?\n");
        fflush(stdin);
        scanf("%d", &nbChange);
    }
    while (nbChange < 1 || nbChange > 7);               //saisie blindee du nombre de lettres a changer

    for(k=0; k<nbChange; k++)
    {

        rangJeton = lettreChange(chevalet, &lettre);       //demande du rang du jeton
        for(i=0; i<27; i++)                             //on parcourt le tableau de la pioche
        {
            if (pioche[0][i] == lettre)                 //si la lettre qui doit etre echangee est reperee dans la pioche
            {
                pioche[1][i] = pioche[1][i]+1;          //on ajoute 1 au compteur d'occurence de cette lettre dans la pioche
            }
        }
        do
        {
            alea = rand()%(27);                         //on genere un nombre aleatoire pour piocher dans le sac au hasard
        }
        while (pioche [1][alea] <= 0);                  //tant que le nombre alea ne correspond pas a une lettre presente dans le sac, on en genere un autre nb alea
        if (pioche[1][alea]> 0)                         //on verifie que la lettre correspondante au nombre alea est presente dans la pioche
        {
            chevalet[rangJeton] = pioche[0][alea];          //si la lettre est dans la pioche on la stock sur le chevalet du joueur
            pioche[1][alea] = pioche[1][alea]-1;        //et on retire 1 au compteur associe a la lettre
        }
    }
    //Affichage

    affichageMain(chevalet);
}

//Permet de savoir le rang de la lettre le joueur veut changer
//Cette fonction renvoie aussi a l'appelant la lettre associee au rang
int lettreChange (char main[7], char *carac)
{
    //Declaration
    int choixLettre;
    //Saisie blindee du rang
    do
    {
        printf("Veuillez saisir le rang de la lettre de votre main que vous souhaitez echanger (entre 1 et 7) : ");
        fflush(stdin);

        scanf("%d", &choixLettre);
    }
    while (choixLettre<1 || choixLettre>7);
    choixLettre = choixLettre-1;                    //on reduit de 1 le rang de la lettre pour que cela corresponde a un rang de tableau
    *carac = main[choixLettre];                     //on stock la lettre associee au rang saisi
    return choixLettre;                             //on rend le rang par retour direct et le caractere associe par parametres
}

//Permet au joueur de saisir un mot
void saisieMot(char chevalet[7], char pioche [2][27], char tableauinvisible[15][15][2], int *compteurTour, int *pointstotaux, int langue, int nbJoueurs)
{
    //Declaration
    char mot [15];
    char coordonneeX, sens;
    int changement[8];
    int autorContestation;
    int i=0, j, autorMain,autorDico, alea, coordonneeY, coordonneeXbis;

    //Saisie du mot
    printf("\nVeuillez saisir le mot a placer dans la grille : ");
    fflush(stdin);
    gets(mot);
    for (j=0; j<8; j++)
    {
        changement[j] = 100;
    }
    //Verification du mot
    joker(mot);
    verifMot(mot, chevalet, &autorMain, pioche, changement, &*compteurTour);

    if(langue==2)
    {
        verifDicoAnglais(mot, &autorDico);
    }
    if(langue==1)
    {
        verifDico(mot, &autorDico);
    }
    if(langue==3)
    {
        verifDicoEspagnol(mot, &autorDico);
    }
    if(langue==4)
    {
        verifDicoAllemand(mot, &autorDico);
    }
    if(nbJoueurs==2 || nbJoueurs==3 || nbJoueurs==4){
        contestation(nbJoueurs, &autorContestation);
    }
    if(nbJoueurs==1){
        autorContestation=1;
    }
    //Si on a l'autorisation de placer le mot :
    if(autorMain == 1 && autorDico ==1 && autorContestation ==1)
    {
        *compteurTour = 1;
        printf("Vous avez le droit de placer le mot\n");
        while(changement[i] != 100)
        {

            do
            {
                alea = rand()%(27);                     //on genere un nombre aleatoire pour piocher dans le sac au hasard
            }
            while (pioche [1][alea] <= 0);              //tant que le nombre alea ne correspond pas a une lettre presente dans le sac, on en genere un autre nb alea
            if (pioche[1][alea]> 0)                     //on verifie que la lettre correspondante au nombre alea est presente dans la pioche
            {
                chevalet[changement[i]] = pioche[0][alea];              //si la lettre est dans la pioche on la stock sur le chevalet du joueur
                pioche[1][alea] = pioche[1][alea]-1;   //et on retire 1 au compteur associe a la lettre
            }
            i++;
        }
        //Saisie des coordonnées
        coordonnee(&coordonneeX, &coordonneeY, &sens, &coordonneeXbis);
        if(sens == 'v' || sens == 'V')
        {
            placerMotV(mot, coordonneeXbis, coordonneeY, tableauinvisible);
            scoreV(mot, &*pointstotaux, tableauinvisible, coordonneeXbis, coordonneeY);
        }
        if(sens == 'h' || sens == 'H')
        {
            placerMotH(mot, coordonneeXbis, coordonneeY, tableauinvisible);
            scoreH(mot, &*pointstotaux, tableauinvisible, coordonneeXbis, coordonneeY);
        }

    }
    //On a pas l'autorisation de placer le mot
    else if(autorDico ==0 || autorMain ==0)
    {
        printf("Vous n'avez pas le droit de placer le mot\n");
    }
    //Affichage
    printf("\n");
    //affichageMain(chevalet);
}

//Permet de saisir les coordonnées de la premiere lettre du mot et le sens de positionnement
//Les coordonnées et le sens sont rendus par parametres
void coordonnee(char* coordonneeX, int* coordonneeY, char* sens, int* coordonneeXbis)
{
    //Saisie de la colonne premiere lettre
    do
    {
        printf("Veuillez saisir la colonne dans laquelle sera placee la premiere lettre de votre mot : ");
        fflush(stdin);
        scanf("%c", &*coordonneeX);
    }
    while(*coordonneeX< 65 || *coordonneeX>79);
    changementCoord(&*coordonneeX, &*coordonneeXbis);
    //Saisie de la ligne premiere lettre
    do
    {
        printf("Veuillez saisir la ligne dans laquelle sera placee la premiere lettre de votre mot : ");
        fflush(stdin);
        scanf("%d", &*coordonneeY);
    }
    while(*coordonneeY< 1 || *coordonneeY>15);

    //Saisie du sens du mot
    do
    {
        printf("Veuillez saisir le sens du mot que vous voulez placer (V pour vertical / H pour horizontal) : ");
        fflush(stdin);
        scanf("%c", &*sens);
    }
    while(*sens != 'V' && *sens != 'H' && *sens != 'v' && *sens != 'h');

}

//Cette fonction permet la conversion du char d'identification de la colonne en un entier
//Les valeurs sont rendues par parametres à l'appellant
void changementCoord(char *coordonnee, int* coordonneeXbis)
{

    if(*coordonnee == 'A')
    {
        *coordonneeXbis = 0;
    }
    else if(*coordonnee == 'B')
    {
        *coordonneeXbis = 1;
    }
    else if(*coordonnee == 'C')
    {
        *coordonneeXbis = 2;
    }
    else if(*coordonnee == 'D')
    {
        *coordonneeXbis = 3;
    }
    else if(*coordonnee == 'E')
    {
        *coordonneeXbis = 4;
    }
    else if(*coordonnee == 'F')
    {
        *coordonneeXbis = 5;
    }
    else if(*coordonnee == 'G')
    {
        *coordonneeXbis = 6;
    }
    else if(*coordonnee == 'H')
    {
        *coordonneeXbis = 7;
    }
    else if(*coordonnee == 'I')
    {
        *coordonneeXbis = 8;
    }
    else if(*coordonnee == 'J')
    {
        *coordonneeXbis = 9;
    }
    else if(*coordonnee == 'K')
    {
        *coordonneeXbis = 10;
    }
    else if(*coordonnee == 'L')
    {
        *coordonneeXbis = 11;
    }
    else if(*coordonnee == 'M')
    {
        *coordonneeXbis = 12;
    }
    else if(*coordonnee == 'N')
    {
        *coordonneeXbis = 13;
    }
    else if(*coordonnee == 'O')
    {
        *coordonneeXbis = 14;
    }
}
