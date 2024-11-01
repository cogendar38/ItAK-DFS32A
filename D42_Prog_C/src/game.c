#include "game.h"
#include "party.h"
#include "utils.h"

#include <stdio.h>

void Game_start(Game *game)
{
    // Initialisation du jeu
    separator(10);
    printf("Bienvenue dans GOZU\n");
    separator(10);

    char response;
    do {
        Party party = Party_play();

        // Affichez le gagnant (exemple simplifié)
        //printf("Le gagnant est : %s\n", party.winner.name);

        printf("Voulez-vous refaire une partie ? (o/n) : ");
        scanf(" %c", &response);
    } while (response == 'o' || response == 'O');

    printf("Merci d'avoir joué !\n");
}