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
*  Nom-prénom1 : Récan Lucas                                                  *
*                                                                             *
*  Nom-prénom2 :Chicano-Quéralta Matéo                                        *
*                                                                             *
*  Nom-prénom3 :                                                              *
*                                                                             *
*  Nom-prénom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier :  dechiffrement                                                         *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 1000
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

void main () {
    char message[TAILLE_MAX];
    printf("Entrez le message à déchiffrer : ");
    fgets(message, TAILLE_MAX, stdin);//On entre un message
    printf("%d\n", verification(message));
    if (verification(message) == 0) {
        perror("Erreur : Le message contient un caractère spécial\n");
        exit(1);
    } else {
        dechiffrementCesar(message, cle, messageDechiffre);
    } 
    

}
void chiffrementCesar(char message[], int cle, char messageDechiffre[]) {
    for (int i=0; i<strlen(message); i++) {
        if (isIn(message[i], aGarder, 5) == 0) {
            char nouveauCaractere = message[i] - cle;
            messageDechiffre[i] = (message[i] - cle)%122;
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