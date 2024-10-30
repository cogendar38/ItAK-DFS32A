#include "carte.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Initialisation du jeu
void Game_init(Game *game)
{
	// Création des cartes
	int nbCartes = Game_genererCartes(game->pioche);

	// Mélanger les cartes
	Game_melanger(game->pioche, nbCartes);
}

// Génération des cartes de jeu
int Game_genererCartes(Carte *pioche)
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

	return index;
}

// Mélanger les cartes
void Game_melanger(Carte *pioche, int taille)
{
	if (taille > 1)
	{
		for (int i = 0; i < taille - 1; i++)
		{
			int j = i + rand() / (RAND_MAX / (taille - i) + 1);
			Carte temp = pioche[j];
			pioche[j] = pioche[i];
			pioche[i] = temp;
		}
	}	
}
