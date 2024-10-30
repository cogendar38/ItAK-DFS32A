#include <stdio.h>
#include <stdlib.h>
#include "../includes/carte.h"
#include "../includes/game.h"

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
	Carte tableau[3][5];
	Carte main[10];
	int tailleMain = 10;	

	// Initialisation
	Game_init(tableau);

	// Retour à la ligne
	printf("\n");
	return 0;
}
