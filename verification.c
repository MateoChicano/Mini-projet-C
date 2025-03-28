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
*  Nom du fichier :  verification                                             *
*                                                                             *
******************************************************************************/

//parcourir chaque caractère de la chaîne 
//vérifier un à un la validité des caractères
//si le caractère courant est un caractère spécial alors on renvoi un message d'erreur  
//si le caractère courant a un accent alors on le retranscrit
//renvoie une chaîne de caractère valide

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verification.h"

#define TAILLE_MAX 1000 //taille max de la chaîne de caractère

void main () {
    char message[TAILLE_MAX];
    printf("Entrez le message à vérifier : ");
    fgets(message, TAILLE_MAX, stdin);//On entre un message
    verification(message);
}

void verification (char message[]) {

    char messageVerifie[TAILLE_MAX];
    int i = 0;

    for (i; i < strlen(message); i++) { 
        if ((message[i] < 65 || message[i] > 90 && message[i] < 97 || message[i] > 122) && message[i] != 32 ) {
            printf("Erreur : caractère spécial détecté\n");
        } else {
        messageVerifie[i] = message[i]; //on copie le caractère dans la chaîne de caractère valide
        printf("Caractère %c valide\n", message[i]);
        }
    }
    printf("message véridié : %s\n", messageVerifie); //on affiche la chaîne de caractère valide
}