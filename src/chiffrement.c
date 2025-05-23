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
#include "../include/chiffrement.h"
#include "misc.h"

int aGarder[5] = {32, 33, 44, 46, 63}; // ponctuation et espace

/* Fonction de chiffrement César qui prend en argument le message à chiffrer, la clé de chiffrement
et le message une fois chiffré.*/
void chiffrementCesar(char message[], int cle, char messageChiffre[]) {
    strcpy(messageChiffre, "");
    int i = 0;
    for (i; i<strlen(message); i++) {
        char caractere = message[i];
        if (isIn(caractere, aGarder, 5) == 0) {
            if (caractere >= 'A' && caractere <= 'Z') {
                messageChiffre[i] = 'A' + (caractere - 'A' + cle) % 26;
            } else if (caractere >= 'a' && caractere <= 'z') {
                messageChiffre[i] = 'a' + (caractere - 'a' + cle) % 26;
            }
        } else {
            // Les espaces et la ponctuation sont écrits tels quels
            messageChiffre[i] = caractere;
        }
    }
    messageChiffre[i] = '\0';
}

void chiffrementVigenere(char message[], char cle[], char messageChiffre[]) {
    // converti chaque lettre en une clé et appeler cesar pour chaque caractère ?
    int i = 0;
    char tampon[strlen(message)];
    char messageee[TAILLE_MAX]; //stocke les caracteres cryptés un à un
    for (i; i<strlen(message); i++) {

        //strcpy(messageChiffre, "");
        tampon[0] = message[i];
        //printf("avant :%s", tampon);
        int nvCle = tolower(cle[i % strlen(cle)]) - 96;
        chiffrementCesar(tampon, nvCle, messageee);
        //printf("    apres :%s\n", messageChiffre);
        strcat(messageChiffre, messageee );
    }
    messageChiffre[i] = '\0';
}
