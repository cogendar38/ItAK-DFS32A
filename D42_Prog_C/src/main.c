#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carte.h"
#include "game.h"

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
	Game_init(&game);

	Carte carteChoisie = Game_prompt(game.player[0], game.tailleMainJoueur[0]);
	printf("Carte choisie : ");
	Carte_show(carteChoisie);

	// Retour à la ligne
	printf("\n");
	return 0;
}
