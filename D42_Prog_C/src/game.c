#include "../includes/carte.h"
#include "../includes/game.h"
#include <stdlib.h>
#include <stdio.h>

// Initialisation du jeu
void Game_init(Game *game)
{
	// Création des cartes
	Game_genererCartes(game->pioche);

	// Mélanger les cartes
	Game_melanger(game->pioche, 180);
}

// Génération des cartes de jeu
void Game_genererCartes(Carte pioche[])
{
	int index = 0;

	// Chaque niveaux
	for (int n = 0; n < 3; n++)
	{
		// Chaque couleur
		for (int c = 0; c < 10; c++)
		{
			// Chaque force
			for (int f = 0; f < 6; f++)
			{
				// Création de la carte
				Carte carte = Carte_create(n,c,f);
				pioche[index] = carte;
				index++;
			}
		}
	}
}

// Mélanger les cartes
void Game_melanger(Carte pioche[], int taille)
{
	for (int i = taille - 1; i > 0; i--)
	{
		int j = rand() % (i + 1);
		Carte temp = pioche[i];
		pioche[i] = pioche[j];
		pioche[j] = temp;
	}
}
