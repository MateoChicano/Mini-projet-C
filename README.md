# Projet chiffrement de message (R204)

Dans le but de développer une application de protection de textes confidentiels, notre équipe de développeurs doit concevoir un
outil permettant le chiffrement de messages (et le déchiffrement).

Le schéma ci-dessous montre l’enchaînement des traitements appliqué afin
de chiffrer un message en clair et d'afficher le résultat. Le schéma montre
également la procédure inverse : déchiffrer un message pour l’afficher en clair.

![image](https://github.com/user-attachments/assets/7acd53e3-afb2-4468-93e0-c3f54bc3ca0c)

## Équipe

Matéo Chicano-Quéralta

Lucas Récan

## Lien du dépot

https://github.com/MateoChicano/Mini-projet-C


## Documentation

### Le fichier chiffrement.c contient les fonctions suivantes :

`char* chiffrementCesar(char* message, int cle)`
  - Paramètres : le message à chiffrer et la clé de chiffrement
  - Renvoie : le message chiffré grâce à l'algorithme César

`char* chiffrementVigenere(char* message, int cle)`
  - Paramètres : le message à chiffrer et la clé de chiffrement
  - Renvoie : le message chiffré grâce à l'algorithme Vigenère

### Le fichier dechiffrement.c contient les fonctions suivantes :

`char* dechiffrementCesar(char* message, char* cle)`
  - Paramètres : le message à déchiffrer et la clé de chiffrement utilisée pour le chiffrer
  - Renvoie : le message déchiffré grâce à l'algorithme César

`char* dechiffrementVigenere(char* message, char* cle)`
  - Paramètres : le message à déchiffrer et la clé de chiffrement utilisée pour le chiffrer
  - Renvoie : le message déchiffré grâce à l'algorithme Vigenère

### Le fichier verification.c contient les fonctions suivantes :

`int verificationMessage(char message[])`
  - Paramètres : le message à vérifier
  - Renvoie : 0 si le message est valide, 1 sinon.

`int verificationCle(char cle[], int choix_algo)`
  - Paramètres : la clé à vérifier et le numéro de choix de l'algorithme.
  - Renvoie : 0 si la clé est valide, 1 sinon.