/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : dfichier main, avec le menu                                     *
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
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "chiffrement.h"
#include "dechiffrement.h"
#include "misc.h"
#include "verification.h"

#define MAX_MESSAGE_LEN 1024
#define MAX_KEY_LEN 256

int main(void) {
    int choix_action = 0;
    int choix_algo = 0;
    char message[MAX_MESSAGE_LEN];
    char cle[MAX_KEY_LEN];
    char resultat[MAX_MESSAGE_LEN];

    printf("=== Menu ===\n");
    printf("1. Chiffrement\n");
    printf("2. Dechiffrement\n");
    printf("Votre choix: ");
    scanf("%d", &choix_action);
    getchar();

    printf("\n=== Choisissez l'algorithme ===\n");
    printf("1. César\n");
    printf("2. Vigenère\n");
    printf("Votre choix: ");
    scanf("%d", &choix_algo);
    getchar();

    printf("\nEntrez votre message (max %d caractères) :\n", MAX_MESSAGE_LEN - 1);
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    // Vérification du message
    if (verificationMessage(message) != 0) {
        printf("Erreur : message invalide.\n");
        return 1;
    }

    printf("Entrez votre clé :\n");
    fgets(cle, sizeof(cle), stdin);
    cle[strcspn(cle, "\n")] = '\0';

    // Vérification de la clé
    if (verificationCle(cle, choix_algo) != 0) {
        printf("Erreur : clé invalide pour l'algorithme choisi.\n");
        return 1;
    }

    printf("\n=== Résultat ===\n");

    if (choix_action == 1) { // Chiffrement
        if (choix_algo == 1) { // César
            chiffrementCesar(message, atoi(cle), resultat);
            printf("Message codé : %s\n", resultat);
        } else if (choix_algo == 2) { // Vigenère
            chiffrementVigenere(message, cle, resultat);
            printf("Message codé : %s\n", resultat);
        } else {
            printf("Erreur : choix d'algorithme invalide.\n");
            return 1;
        }
    } else if (choix_action == 2) { // Dechiffrement
        if (choix_algo == 1) { // César
            dechiffrementCesar(message, atoi(cle), resultat);
            printf("Message décodé : %s\n", resultat);
        } else if (choix_algo == 2) { // Vigenère
            dechiffrementVigenere(message, cle, resultat);
            printf("Message décodé : %s\n", resultat);
        } else {
            printf("Erreur : choix d'algorithme invalide.\n");
            return 1;
        }
    } else {
        printf("Erreur : choix d'action invalide.\n");
        return 1;
    }

    printf("%s\n", resultat);

    return 0;
}