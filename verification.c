#include "header.h"

//Propose aux joueurs de choisir une langue de vérification de l'orthographe
//On renvoit à l'appelant le choix du joueur avec un entier : 1.français    2.anglais   3.espagnol  4.allemand
void choixlangue(int *langue)
{
    do
    {
        system("cls");
        printf("Dans quelle langue voulez-vous jouer ?\n\n");
        Color(3,0);
        printf("Fra");
        Color(15,0);
        printf("nc");
        Color(4,0);
        printf("ais");
        Color(15,0);
        printf(" : taper 1 \n\n");

        Color(3,0);
        printf("A");
        Color(15,0);
        printf("n");
        Color(4,0);
        printf("gla");
        Color(15,0);
        printf("i");
        Color(3,0);
        printf("s ");
        Color(15,0);
        printf(" : taper 2 \n\n");

        Color(4,0);
        printf("Esp");
        Color(14,0);
        printf("ag");
        Color(4,0);
        printf("nol");
        Color(15,0);
        printf(" : taper 3 \n\n");

        Color(15,0);
        printf("All");
        Color(4,0);
        printf("em");
        Color(14,0);
        printf("and");
        Color(15,0);
        printf(" : taper 4 \n\n");
        scanf("%d", &*langue);
        printf("Debut de la partie dans :");
        Sleep(2000);
        for (int i=5; i>0; i--)
        {
            system("cls"); //
            printf("%d...", i);
            Sleep(1000);
        }
        system("cls");
        //DEBUT DE LA PARTIE
    }
    while(*langue!=1 && *langue!=2 && *langue!=3 && *langue !=4);
    if(*langue==1)
    {
        printf("Nous allons lancer une partie en francais\n");
    }
    else if(*langue==2)
    {
        printf("Nous allons lancer une partie en anglais\n");
        printf("Les regles sont les memes qu'en francais, seulement, vous rentrerez vos mots en anglais et ils seront verifies dans un dictionnaire anglais\n");
    }
    else if(*langue==3)
    {
        printf("Nous allons lancer une partie en espagnol\n");
        printf("Les regles sont les memes qu'en francais, seulement, vous rentrerez vos mots en espagnol et ils seront verifies dans un dictionnaire espagnol\n");
    }
    else if(*langue==4)
    {
        printf("Nous allons lancer une partie en allemand\n");
        printf("Les regles sont les memes qu'en francais, seulement, vous rentrerez vos mots en allemand et ils seront verifies dans un dictionnaire allemand\n");
    }
    Sleep(7000);
}

//Permet de verifier la possibilite d'ecritutre du mot en fct des lettres du chevalet
void verifMot (char mot[15], char chevalet[7], int *autor, char pioche [2][27], int changement[7], int *compteurTour)
{
    //Declaration
    int i, j, k, compteur;
    //Initialisation des compteurs
    compteur =0;
    k =0;

    //test du mot saisi
    for(j=0; j<15; j++)
    {
        mot[j] = toupper(mot[j]);           //On passe le mot saisi en maj pour ne pas créer de pb avec la grille
    }
    for(i=0; i<strlen(mot); i++)            //On parcourt le le mot saisi qui est un str
    {
        j=0;

        while(mot[i] != chevalet[j] && j<7)            //Tant que la lettre au rang j du chevalet est differente de la lettre au rang i du mot, j augmente de 1
        {
            j++;
        }
        if(mot[i] == chevalet[j])
        {
            //Si un lettre est reperee a la fois dans le mot et dans le chevalet, le compteur de verification augmente de 1
            compteur++;
            changement[k] = j;
            k++;
        }
    }
    //Affichage
    if(*compteurTour == 0)
    {
        if (compteur == strlen(mot))            //Si la taille du compteur est égale a la taille du mot saisi, on peut placer le mot
        {
            //car il est possible d'ecrire le mot avec les lettre de la chevalet
            //printf("\nVous avez le droit de placer le mot\n\n");
            *autor = 1;
        }
        else if (compteur != strlen(mot))
        {
            //printf("\nVous n'avez pas le droit de placer le mot\n\n");
            *autor = 0;
        }
    }
    if(*compteurTour != 0)
    {
        if (compteur +1 == strlen(mot))            //Si la taille du compteur est égale a la taille du mot saisi, on peut placer le mot
        {
            //car il est possible d'ecrire le mot avec les lettre de la chevalet
            //printf("\nVous avez le droit de placer le mot\n\n");
            *autor = 1;
        }
        else if (compteur +1 != strlen(mot))
        {
            //printf("\nVous n'avez pas le droit de placer le mot\n\n");
            *autor = 0;
        }
    }
}

//Permet de gérer la contestation d'un mot saisi
void contestation (int nbJoueurs, int *autorisation)
{
    int choixContestation;
    int rangJ;

    printf("Quelqu'un veut-il contester le mot place dans la grille (0 pour non/1 pour oui)\n");
    do
    {
        fflush(stdin);
        scanf("%d", &choixContestation);
    }
    while(choixContestation<0 || choixContestation>1);//Blindage de la saisi du choix de contestation

    if(choixContestation == 1)
    {
        printf("Nous vous laissons discutez entre vous du placement du mot...\n");//On laisse les joueurs débattre entre eux
        Sleep(4000);
        printf("Alors ? Veuillez saisir 1 si le mot peut etre place\n");//Demande de resultat de la reflexion
        fflush(stdin);
        scanf("%d", &*autorisation);//saisi du résultat


        ///Si le mot peut être placé, le joueur ayant contesté perd des points
        if(*autorisation == 1)
        {
            if (nbJoueurs ==2)  //selon le nombre de joueur
            {
                printf("Quel joueur a voulu contester ce mot ? Saisir 1 pour %s ou 2 pour %s\n", joueurun.pseudo, joueurdeux.pseudo);   //demande le nom du joueur quia contester pour diminuer son score de -10
                do
                {
                    fflush(stdin);
                    scanf("%d", &rangJ);
                }
                while( rangJ<1 || rangJ>2); //blindage de la saisie
                if(rangJ == 1)
                {
                    printf("%s tu vas perdre 10 points\n", joueurun.pseudo);//on affiche un message comme quoi son score va être réduit
                    joueurun.pointsjoueur = joueurun.pointsjoueur -10; //on retire 10 à son score
                }
                if(rangJ == 2)
                {
                    printf("%s tu vas perdre 10 points\n", joueurdeux.pseudo);
                    joueurdeux.pointsjoueur = joueurdeux.pointsjoueur -10;
                }

            }
            ///Meme procedé que pour 2 jouerus mais avec 1 joueur en plus
            if (nbJoueurs ==3)
            {
                printf("Quel joueur a voulu contester ce mot ? Saisir 1 pour %s ou 2 pour %s ou 3 pour %s\n", joueurun.pseudo, joueurdeux.pseudo, joueurtrois.pseudo);
                fflush(stdin);
                do
                {
                    fflush(stdin);
                    scanf("%d", &rangJ);
                }
                while( rangJ<1 || rangJ>3);
                if(rangJ == 1)
                {
                    printf("%s tu vas perdre 10 points\n", joueurun.pseudo);
                    joueurun.pointsjoueur = joueurun.pointsjoueur -10;
                }
                if(rangJ == 2)
                {
                    printf("%s tu vas perdre 10 points\n", joueurdeux.pseudo);
                    joueurdeux.pointsjoueur = joueurdeux.pointsjoueur -10;
                }
                if(rangJ == 3)
                {
                    printf("%s tu vas perdre 10 points\n", joueurtrois.pseudo);
                    joueurtrois.pointsjoueur = joueurtrois.pointsjoueur -10;
                }

            }
            ///Meme procedé que pour 2 jouerus mais avec 2 joueur en plus
            if (nbJoueurs ==4)
            {
                printf("Quel joueur a voulu contester ce mot ? Saisir 1 pour %s ou 2 pour %s ou 3 pour %s ou 4 pour %s\n", joueurun.pseudo, joueurdeux.pseudo, joueurtrois.pseudo, joueurquatre.pseudo);
                do
                {
                    fflush(stdin);
                    scanf("%d", &rangJ);
                }
                while( rangJ<1 || rangJ>4);
                if(rangJ == 1)
                {
                    printf("%s tu vas perdre 10 points\n", joueurun.pseudo);
                    joueurun.pointsjoueur = joueurun.pointsjoueur -10;
                }
                if(rangJ == 2)
                {
                    printf("%s tu vas perdre 10 points\n", joueurdeux.pseudo);
                    joueurdeux.pointsjoueur = joueurdeux.pointsjoueur -10;
                }
                if(rangJ == 3)
                {
                    printf("%s tu vas perdre 10 points\n", joueurtrois.pseudo);
                    joueurtrois.pointsjoueur = joueurtrois.pointsjoueur -10;
                }
                if(rangJ == 4)
                {
                    printf("%s tu vas perdre 10 points\n", joueurquatre.pseudo);
                    joueurquatre.pointsjoueur = joueurquatre.pointsjoueur -10;
                }

            }
        //Sachant qu'après le débat les joueurs se sont mis d'accord pour autoriser le placement du mot, l'autorisation de contestation doit prendre sa valeur vraie
        *autorisation=1;

        }
        ///Si la demande de contestation est vraie, le mot ne peut pas être placé, on ajoute des points au joueur  ayant contesté
        if(*autorisation != 1)
        {
            if (nbJoueurs ==2)//On adapte le code en fonction du nombre de joueur
            {
                printf("Quel joueur a voulu contester ce mot ? Saisir 1 pour %s ou 2 pour %s\n", joueurun.pseudo, joueurdeux.pseudo);//Demande du joueur qui a contesté
                do
                {
                    fflush(stdin);
                    scanf("%d", &rangJ);
                }
                while( rangJ<1 || rangJ>2);//blindage de la saisie
                if(rangJ == 1)
                {
                    printf("%s tu vas gagner 5 points\n", joueurun.pseudo);//on annonce qu'il va gagner des points avec sa contestation
                    joueurun.pointsjoueur = joueurun.pointsjoueur +5;//on augmente son score de +5
                }
                if(rangJ == 2)
                {
                    printf("%s tu vas gagner 5 points\n", joueurdeux.pseudo);//on annonce qu'il va gagner des points avec sa contestation
                    joueurdeux.pointsjoueur = joueurdeux.pointsjoueur +5;//on augmente son score de +5
                }

            }
            ///Meme procedé que pour 2 jouerus mais avec 1 joueur en plus
            if (nbJoueurs ==3)
            {
                printf("Quel joueur a voulu contester ce mot ? Saisir 1 pour %s ou 2 pour %s ou 3 pour %s\n", joueurun.pseudo, joueurdeux.pseudo, joueurtrois.pseudo);
                do
                {
                    fflush(stdin);
                    scanf("%d", &rangJ);
                }
                while( rangJ<1 || rangJ>3);
                if(rangJ == 1)
                {
                    printf("%s tu vas gagner 5 points\n", joueurun.pseudo);
                    joueurun.pointsjoueur = joueurun.pointsjoueur +5;
                }
                if(rangJ == 2)
                {
                    printf("%s tu vas gagner 5 points\n", joueurdeux.pseudo);
                    joueurdeux.pointsjoueur = joueurdeux.pointsjoueur +5;
                }
                if(rangJ == 3)
                {
                    printf("%s tu vas gagner 5 points\n", joueurtrois.pseudo);
                    joueurtrois.pointsjoueur = joueurtrois.pointsjoueur +5;
                }

            }
            ///Meme procedé que pour 2 jouerus mais avec 2 joueur en plus
            if (nbJoueurs ==4)
            {
                printf("Quel joueur a voulu contester ce mot ? Saisir 1 pour %s ou 2 pour %s ou 3 pour %s ou 4 pour %s\n", joueurun.pseudo, joueurdeux.pseudo, joueurtrois.pseudo, joueurquatre.pseudo);
                do
                {
                    fflush(stdin);
                    scanf("%d", &rangJ);
                }
                while( rangJ<1 || rangJ>4);
                if(rangJ == 1)
                {
                    printf("%s tu vas gagner 5 points\n", joueurun.pseudo);
                    joueurun.pointsjoueur = joueurun.pointsjoueur +5;
                }
                if(rangJ == 2)
                {
                    printf("%s tu vas gagner 5 points\n", joueurdeux.pseudo);
                    joueurdeux.pointsjoueur = joueurdeux.pointsjoueur +5;
                }
                if(rangJ == 3)
                {
                    printf("%s tu vas gagner 5 points\n", joueurtrois.pseudo);
                    joueurtrois.pointsjoueur = joueurtrois.pointsjoueur +5;
                }
                if(rangJ == 4)
                {
                    printf("%s tu vas gagner 5 points\n", joueurquatre.pseudo);
                    joueurquatre.pointsjoueur = joueurquatre.pointsjoueur +5;
                }

            }
            //Le mot est contesté, il ne peut pas être placé
            //Donc l'autorisation prend sa valeur fausse et la suite des actions de placement du mot ne seront pas proposées au joueur
            *autorisation =0;
        }
    }
    //Si le choix des joueurs est de ne pas contester, l'autorisation prend automatique sa valeur vraie
    if (choixContestation==0){
            *autorisation =1;}
}

//Vérification de l'orthographe avec un dico français
void verifDico (char mot [15], int *autor)
{
    FILE *dico;
    dico = fopen("dictionnaire1.txt", "r");                     //Ouverture du dictionnaire

    char comparaison[30];
    *autor = 0;


    if (dico == NULL)
    {
        printf("On n'arrive pas a ouvrir le dico...\n");        //Message d'erreur d'ouverture du fichier .txt
    }

    while(!feof(dico) && strcmp(comparaison, mot)!=0)           //tant que l'on atteint pas la fin du fichier
    {
        fscanf(dico, "%s", comparaison);
        if(strcmp(comparaison, mot)==0)                         //test de comparaison avec le mot saisi par le joueur
        {
            printf("Le mot existe ! ");
            *autor =1;                                          //l'autorisation de placer le mot prend 1 donc devient vraie
        }
    }
    if(!autor)
    {
        printf("Le mot n'est pas present dans le dico\n");      //affichage d'un message si le mot n'existe pas dans le dictionnaire
        *autor = 0;
    }
    fclose(dico);
}

//Vérification de l'orthographe avec un dico anglais
//Pour voir le fonctionnement du dico regarder : void verifDico (dico en fr)
void verifDicoAnglais (char mot [15], int *autor)
{
    FILE *dico;
    dico = fopen("dicoanglais.txt", "r");

    char comparaison[30];
    *autor = 0;


    if (dico == NULL)
    {
        printf("On n'arrive pas a ouvrir le dico...\n");
    }

    while(!feof(dico) && strcmp(comparaison, mot)!=0)
    {
        fscanf(dico, "%s", comparaison);
        if(strcmp(comparaison, mot)==0)
        {
            printf("Le mot existe ! ");
            *autor =1;
        }
    }
    if(!autor)
    {
        printf("Le mot n'est pas present dans le dico\n");
        *autor = 0;
    }
    fclose(dico);
}

//Vérification de l'orthographe avec un dico anglais
//Pour voir le fonctionnement du dico regarder : void verifDico (dico en fr)
void verifDicoEspagnol (char mot [15], int *autor)
{
    FILE *dico;
    dico = fopen("espanol.txt", "r");

    char comparaison[30];
    *autor = 0;


    if (dico == NULL)
    {
        printf("On n'arrive pas a ouvrir le dico...\n");
    }

    while(!feof(dico) && strcmp(comparaison, mot)!=0)
    {
        fscanf(dico, "%s", comparaison);
        if(strcmp(comparaison, mot)==0)
        {
            printf("Le mot existe ! ");
            *autor =1;
        }
    }
    if(!autor)
    {
        printf("Le mot n'est pas present dans le dico\n");
        *autor = 0;
    }
    fclose(dico);
}

//Vérification de l'orthographe avec un dico anglais
//Pour voir le fonctionnement du dico regarder : void verifDico (dico en fr)
void verifDicoAllemand (char mot [15], int *autor)
{
    FILE *dico;
    dico = fopen("allemand.txt", "r");

    char comparaison[30];
    *autor = 0;


    if (dico == NULL)
    {
        printf("On n'arrive pas a ouvrir le dico...\n");
    }

    while(!feof(dico) && strcmp(comparaison, mot)!=0)
    {
        fscanf(dico, "%s", comparaison);
        if(strcmp(comparaison, mot)==0)
        {
            printf("Le mot existe ! ");
            *autor =1;
        }
    }
    if(!autor)
    {
        printf("Le mot n'est pas present dans le dico\n");
        *autor = 0;
    }
    fclose(dico);
}

//Permet de savoir quel lettre le joueur veut utiliser avec son joker
//la lettre voulue est directement remplacée dans la main
//On remplace le joker par la lettre pour eviter que le joueur essaye des combinaisons infinies avec son joker
void joker (char mot[15])
{
    int i;

    for(i=0; i<15; i++)                                                                                     //on parcourt le mot
    {
        if(mot[i]=='?')                                                                                     //on test la présence d'un joker
        {
            printf("Par quelle lettre (en majuscule) voulez-vous changer votre joker ?\n");
            do
            {
                scanf("%c", &mot[i]);
            }
            while(mot[i]<65 || mot[i]>90);

        }
    }
}
