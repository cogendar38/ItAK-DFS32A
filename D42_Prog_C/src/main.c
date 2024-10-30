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

	// Afficher la première carte
	for (int i = 0; i < 180; i++)
	{
		Carte_show(game.pioche[i]);
	}

	// Retour à la ligne
	printf("\n");
	return 0;
}
