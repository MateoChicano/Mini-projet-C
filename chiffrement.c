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
#include "misc.h"

const int aGarder[5] = {32, 33, 44, 46, 63}; // ponctuation et espace

int main(int argc, char const *argv[])
{
    char message[TAILLE_MAX] = "Lucas Recan";
    char messageDechiffre[TAILLE_MAX];
    chiffrementCesar(message, 1231, messageDechiffre);
    printf("%s\n", messageDechiffre);
    return 0;
}

void chiffrementCesar(char message[], int cle, char messageDechiffre[]) {
    for (int i=0; i<strlen(message); i++) {
        if (isIn(message[i], aGarder, 5) == 0) {
            char nouveauCaractere = message[i] + cle;
            messageDechiffre[i] = (message[i] + cle)%122;
        } else {
            // Les espaces sont écrits tel quel
            messageDechiffre[i] = message[i];
        }
    }
}

void chiffrementVigenere(char message[], char cle[], char messageDechiffre[]) {
    for (int i=0; i<strlen(message); i++) {
        if (!messageDechiffre[i] == 32) {
            messageDechiffre[i] = message[i] + cle[i%strlen(cle)];
        }
    }
}