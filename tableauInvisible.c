#include "header.h"

void remplitableauinvisible(char tablo[15][15][2])
{
    int i, j;
    for(i=0; i<15; i++)
    {
        for(j=0; j<15; j++)
        {
            tablo[i][j][0] = ' ';
        }
    }


    multiplicateurPlateau(tablo);
}


void multiplicateurPlateau(char tablo[15][15][2])   ///programme de remplissage des multiplicateurs du plateau
{
    int i,j;
    for(i=0; i<15; i++)
    {
        for(j=0; j<15; j++)
        {
            tablo[i][j][1] = ' ';
        }
    }
    ///ligne 1
    tablo[0][0][1] = '§';
    tablo[0][3][1] = '&';
    tablo[0][7][1] = '§';
    tablo[0][11][1] = '&';
    tablo[0][14][1] = '§';

    ///ligne 2
    tablo[1][1][1] = '@';
    tablo[1][5][1] = '%';
    tablo[1][9][1] = '%';
    tablo[1][13][1] = '@';

    ///ligne 3
    tablo[2][2][1] = '@';
    tablo[2][6][1] = '&';
    tablo[2][8][1] = '&';
    tablo[2][12][1] = '@';

    ///ligne 4
    tablo[3][0][1] = '&';
    tablo[3][3][1] = '@';
    tablo[3][7][1] = '&';
    tablo[3][11][1] = '@';
    tablo[3][14][1] = '&';

    ///ligne 5
    tablo[4][4][1] = '@';
    tablo[4][10][1] = '@';

    ///ligne 6
    tablo[5][1][1] = '%';
    tablo[5][5][1] = '%';
    tablo[5][9][1] = '%';
    tablo[5][13][1] = '%';

    ///ligne 7
    tablo[6][2][1] = '&';
    tablo[6][6][1] = '&';
    tablo[6][8][1] = '&';
    tablo[6][12][1] = '&';

    ///ligne 8
    tablo[7][0][1] = '§';
    tablo[7][3][1] = '&';
    tablo[7][7][1] = '#';
    tablo[7][11][1] = '&';
    tablo[7][14][1] = '§';

    ///ligne 9
    tablo[8][2][1] = '&';
    tablo[8][6][1] = '&';
    tablo[8][8][1] = '&';
    tablo[8][12][1] = '&';

    ///ligne 10
    tablo[9][1][1] = '%';
    tablo[9][5][1] = '%';
    tablo[9][9][1] = '%';
    tablo[9][13][1] = '%';

    ///ligne 11
    tablo[10][4][1] = '@';
    tablo[10][10][1] = '@';

    ///ligne 12
    tablo[11][0][1] = '&';
    tablo[11][3][1] = '@';
    tablo[11][7][1] = '&';
    tablo[11][11][1] = '@';
    tablo[11][14][1] = '&';

    ///ligne 13
    tablo[12][2][1] = '@';
    tablo[12][6][1] = '&';
    tablo[12][8][1] = '&';
    tablo[12][12][1] = '@';

    ///ligne 14
    tablo[13][1][1] = '@';
    tablo[13][5][1] = '%';
    tablo[13][9][1] = '%';
    tablo[13][13][1] = '@';

    ///ligne 15
    tablo[14][0][1] = '§';
    tablo[14][3][1] = '&';
    tablo[14][7][1] = '§';
    tablo[14][11][1] = '&';
    tablo[14][14][1] = '§';

}



