/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : dechiffrement de messages                                         *
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
*  Nom du fichier : dechiffrement.c                                           *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAILLE_MAX 1000
#include "../include/dechiffrement.h"
#include "misc.h"

extern int aGarder[5]; // ponctuation et espace

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
            if (message[i] < 'a' && message[i]> 'Z' || message[i] < 'A') {
                message[i] = message[i] + 26;
            }
        } else {
            // Les espaces et la ponctuation sont écrits tels quels
            message[i] = caractere;
        }
}
message[i] = '\0';
}

void dechiffrementVigenere(char message[], char cle[], char messageChiffre[]) {
    int i = 0;
    char tampon[strlen(messageChiffre)];
    char messageee[TAILLE_MAX];

    for (i; i<strlen(messageChiffre); i++) {
        tampon[0] = messageChiffre[i];
        int nvCle = tolower(cle[i % strlen(cle)]) - 96;
        //printf("cle : %d\n", nvCle);
        //printf("avant :%s", tampon);
        dechiffrementCesar(messageee, nvCle, tampon);
        //printf("    apres :%s\n", messageee);
        strcat(message, messageee);
    }
    message[i] = '\0';
}