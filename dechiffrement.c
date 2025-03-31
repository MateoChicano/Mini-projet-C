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
#include "misc.c"

int aGarder[5] = {32, 33, 44, 46, 63}; // ponctuation et espace

int main(int argc, char const *argv[])
{
    char message[TAILLE_MAX] = "Lucas Recanz";
    char messageChiffre[TAILLE_MAX];
    chiffrementCesar(message, 30, messageChiffre);
    printf("%s\n", messageChiffre);
    return 0;
}
/* Fonction de chiffrement César qui prend en argument le message à chiffrer, la clé de chiffrement
et le message une fois chiffré.*/
void chiffrementCesar(char message[], int cle, char messageChiffre[]) {
    int i =0;
    for (i; i<strlen(message); i++) {
        char caractere = message[i];
        if (message[i] >= 'A' && message[i] <= 'Z') {
            
        }
}

void chiffrementVigenere(char message[], char cle[], char messageDechiffre[]) {
    // à faire
}