#include "header.h"

int main()
{
    int Joueurs; //Déclaration de la variable contenant le nombre de joueurs
    int langue; //Déclaration de la variable associée à la langue utilisée
    char tableauinvisible[15][15][2]; //Déclaration de notre fidèle tableau invisible qui nous suivra tout au long du projet

    //Déclaration de la pioche et premier remplissage
    char pioche [2][27] =
    {
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?'},
        {9, 2, 2, 3, 15, 2, 2, 2, 8, 1, 1, 5, 3, 6, 6, 2, 1, 6, 6, 6, 6, 2, 1, 1, 1, 1, 2}
    };
    menu(&Joueurs, tableauinvisible, pioche, &langue); //on récupère par pointeur le nombre de joueurs pour pouvoir créer une boucle de jeu


    return 0;
}
