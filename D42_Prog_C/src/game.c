#include "carte.h"
#include "game.h"
#include "player.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Initialisation du jeu
void Game_init(Game *game)
{
	// Créer nos joueurs
	Player player1 = Player_createPlayer();
	Player player2 = Player_createPlayer();

	// Stocker les joueurs
	game->players[0] = player1;
	game->players[1] = player2;

	// Vider le board des joueurs
	Player_emptyTheBoard(&game->players[0]);
	Player_emptyTheBoard(&game->players[1]);

	// Création des cartes
	int nbCartes = Game_genererCartes(game->pioche);
	game->taillePioche = nbCartes;

	// Mélanger les cartes
	Game_melanger(game->pioche, nbCartes);

	// Distribuer les cartes aux joueurs
	Game_distribuer(game, 10);
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

	printf("%d %s\n", index, "cartes crée(s)");
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
	printf("Les cartes ont été mélangée\n");
}

// Piocher une carte
void Game_piocherCarte(Game *game, int playerNumber)
{
	if(game->taillePioche > 0)
	{
		game->players[playerNumber].main[game->players[playerNumber].tailleMain] = game->pioche[game->taillePioche - 1];
		(game->players[playerNumber].tailleMain)++;
		(game->taillePioche)--;
	}
	else
	{
		printf("La pioche est vide\n");
	}
}

// Distribuer les cartes au joueurs
void Game_distribuer(Game *game, int numberOfCards)
{
	for (int i = 0; i < numberOfCards; i++)
	{
		Game_piocherCarte(game, 0);
		Game_piocherCarte(game, 1);
	}
	printf("%d %s\n", numberOfCards, "cartes ont été distribuée à chaque joueur.");
}

// Prompt l'utilisateur pour choisir une carte
Carte Game_prompt(Player *player)
{
	// Afficher les cartes du joueur
	Player_afficherMain(player);

	printf("%s : %d \n", "Taille de la main du joueur", player->tailleMain);

	// Demander à l'utilisateur de choisir une carte
	int index;
	printf("Choisissez une carte (index) : ");
	scanf("%d", &index);
	return player->main[index];
}
