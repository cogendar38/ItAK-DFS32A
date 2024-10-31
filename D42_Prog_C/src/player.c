#include "player.h"
#include "carte.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Player Player_createPlayer()
{
	Player player;

	player.tailleMain = 0;

	// Prompt l'utilisateur pour récupérer nom
	printf("Veuillez saisir votre nom : \n");
	scanf("%19s", player.name);

	printf("Bonjour %s\n", player.name);

	return player;
}

// Vider le board du joueur
void Player_emptyTheBoard(Player *player)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Carte carte;
			carte.couleur = -1;
			carte.niveau = -1;
			carte.force = -1;
			player->board[i][j] = carte;
		}
	}

	printf("Plateau de jeux pour %s initialiser avec succès.\n", player->name);
}

// Afficher la main d'un joueur
void Player_afficherMain(Player *player)
{
	printf("Main de %s :\n", player->name);
	for (int i = 0; i < player->tailleMain; i++)
	{
		printf("Index %d : ", i);
		Carte_show(player->main[i]);
	}
}