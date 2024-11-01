#include "party.h"
#include <stdio.h>

Party Party_play() {
    // Lancer une partie
    printf("Lancement de la partie...\n");

    Party party;

    // Création des joueurs
    printf("Création du premier joueur : \n");
    party.joueurs[0] = Player_createPlayer();

    printf("Création du deuxième joueur\n");
    party.joueurs[1] = Player_createPlayer();

    // Fin de partie
    // TODO: Définir le gagnant

    return party;
}