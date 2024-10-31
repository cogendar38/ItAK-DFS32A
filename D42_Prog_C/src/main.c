#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carte.h"
#include "game.h"
#include "player.h"

void separator(int length)
{
	for (int i = 0; i < 10; i++)
	{
		printf("----");
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	// Définition
	srand(time(NULL));
	Game game;

	// Initialisation du jeu
	printf("Démarrage en cours, veuillez patientez...\n");
	Game_init(&game);
	separator(10);

	int tourIndex = 0;

	do {
		Carte carteChoisie = Game_prompt(game.players[0].main, game.players[0].tailleMain);
		printf("Vous avez choisie la carte : ");
		Carte_show(carteChoisie);

		// Jouer la carte
		Game_playCarte(&game, carteChoisie, 0);

		tourIndex++;
	} while (tourIndex < 10);

	// Retour à la ligne
	printf("\n");
	return 0;
}
