#include <stdlib.h>
#include <stdio.h>
#include "misc.h"

/* La fonction retourne 1 si l'entier est présent dans la liste d'entiers, sinon 0.
Prend en argument l'entier, la liste et la longueur de la liste.*/
int isIn(int n, int* liste, int longueur) {
    for (int i=0; i<longueur; i++) {
        if (liste[i] == n) {
            return 1;
        }
    }
    return 0;
}