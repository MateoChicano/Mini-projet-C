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
#define TAILLE_MAX 1000
#define ALPHABET "abcdefghijklmnopqrstuvwxyz" 

char* chiffrementCesar(char* message, int cle) {
    char messageDechiffre[TAILLE_MAX];
    for (int i=0; i<strlen(message); i++) {
        
        messageDechiffre[i] += ALPHABET[strchr(ALPHABET, message[i]) - ALPHABET + cle];
    }
}
