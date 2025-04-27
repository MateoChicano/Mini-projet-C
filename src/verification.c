/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : verification de la validité des messages et des clés            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Récan Lucas                                                  *
*                                                                             *
*  Nom-prénom2 : Chicano-Quéralta Matéo                                        *
*                                                                             *
*  Nom-prénom3 :                                                              *
*                                                                             *
*  Nom-prénom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier :  verification.c                                             *
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
#include <ctype.h>
#include "verification.h"
#include "misc.h"

#define TAILLE_MAX 1000 //taille max de la chaîne de caractère
extern int aGarder[5];

/* Fonction de vérification de la validité du message entré par l'utilisateur. Prend en argument
le message et renvoie 0 si le message contient un caractère spécial, 1 sinon.*/
int verificationMessage(char message[]) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = (unsigned char)message[i];
        
        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              isIn(c, aGarder, strlen(message)))) {
            return 1; // Message invalide
        }
    }
    return 0; // Message valide
}


int verificationCle(char cle[], int choix_algo) {
    if (choix_algo == 1) {
        // Clé pour César : doit être un nombre entier
        for (int i=0; cle[i] != '\0'; i++) {
            if (!isdigit((unsigned char)cle[i])) {
                return 1;
            }
        }
    } else if (choix_algo == 2) {
        // Clé pour Vigenère : doit être uniquement des lettres
        for (int i = 0; cle[i] != '\0'; i++) {
            if (!isalpha((unsigned char)cle[i])) {
                return 1;
            }
        }
    } else {
        return 1;
    }
    return 0;
}