#include "player.h"
#include "carte.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Player Player_createPlayer()
{
	Player player;

	player.tailleMain = 0;
	player.forceTotal = 0;

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

// Chercher un emplacement disponible
int Player_checkEmptySpace(Carte *line) 
{
	for (int i = 0; i < 5; i++) {
        if (line[i].niveau == -1) {
            return i;
        }
    }
    return -1;
}

// Jouer une carte 
void Player_playCarte(Player *player, Carte carte)
{
	// Chercher un emplacement disponible
	int space = Player_checkEmptySpace(player->board[carte.niveau]);

	if(space == -1)
	{
		printf("Aucun emplacement disponible pour la rangée %d\n", carte.niveau + 1);
		return;
	}

	if (carte.niveau > 0)
	{
		switch (carte.niveau)
		{
			case 1:
				// Vérifier la présence d'une carte dans la rangée 0
				if (player->board[0][space].niveau == -1)
				{
					printf("/!\\ Impossible de jouer cette carte, vous devez d'abord jouer une niveau 1\n");
					return;
				}
				break;
			case 2:
				// Vérifier la présence d'une carte dans la rangée 1
				if (player->board[1][space].niveau == -1)
				{
					printf("/!\\ Impossible de jouer cette carte, vous devez d'abord jouer une niveau 2\n");
					return;
				}
				break;
		}
	}

	// Placer la carte
	player->board[carte.niveau][space] = carte;
	player->forceTotal = player->forceTotal + carte.force;

	// TODO: Supprimer la carte de la main du joueur
	printf("%s %d\n", "La carte à été placée dans la case ", space);
}