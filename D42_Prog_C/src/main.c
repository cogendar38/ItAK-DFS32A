#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "player.h"
#include "party.h"
#include "game.h"

int main(int argc, char* argv[])
{
	// Définition
	srand(time(NULL));
	Game game;

	// Lancement du jeu
	Game_start(&game);

	// Retour à la ligne
	printf("\n");
	return 0;
}
