/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement de messages                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Chicano-Quéralta Matéo                                       *
*                                                                             *
*  Nom-prénom2 : Récan Lucas                                                  *
*                                                                             *
*  Nom-prénom3 :                                                              *
*                                                                             *
*  Nom-prénom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : chiffrement.c                                             *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAILLE_MAX 1000
#include "chiffrement.h"
#include "dechiffrement.h"
//#include "chiffrement.c"
#include "misc.c"

int aGarder[5] = {32, 33, 44, 46, 63}; // ponctuation et espace

int main(int argc, char const *argv[])
{
    char message[TAILLE_MAX];
    char messageChiffre[TAILLE_MAX]  = "Iwpak ydeywjk .";
    dechiffrementCesar(message, 802, messageChiffre);
    printf("%s\n", message);
    return 0;
}
/* Fonction de chiffrement César qui prend en argument le message à chiffrer, la clé de chiffrement
et le message une fois chiffré.*/
void dechiffrementCesar(char message[], int cle, char messageChiffre[]) {
    int i =0;
    for (i; i<strlen(messageChiffre); i++) {
        char caractere = messageChiffre[i];
        if (isIn(caractere, aGarder, 5) == 0) {
            if (caractere >= 'A' && caractere <= 'Z') {
                message[i] = 'A' + (caractere - 'A' - cle) % 26;
            } else if (caractere >= 'a' && caractere <= 'z') {
                message[i] = 'a' + (caractere - 'a' - cle) % 26;
            }
            if (message[i] < 'a' || message[i] < 'A') {
                message[i] = message[i] + 26;
            }
        } else {
            // Les espaces et la ponctuation sont écrits tels quels
            message[i] = caractere;
        }
}
message[i] = '\0';
}