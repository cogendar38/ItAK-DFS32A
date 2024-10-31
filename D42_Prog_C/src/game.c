#include "carte.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Initialisation du jeu
void Game_init(Game *game)
{
	// Vider le tableau
	Game_emptyTheTable(game);

	// Création des cartes
	int nbCartes = Game_genererCartes(game->pioche);
	game->taillePioche = nbCartes;
	game->tailleMainJoueur[0] = 0;
	game->tailleMainJoueur[1] = 0;

	// Mélanger les cartes
	Game_melanger(game->pioche, nbCartes);

	// Distribuer les cartes aux joueurs
	Game_distribuer(game, 10);
}

// Vider le tableau
void Game_emptyTheTable(Game *game)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Carte carte;
			carte.couleur = -1;
			carte.niveau = -1;
			carte.force = -1;
			game->tableau[i][j] = carte;
		}
	}
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
		game->player[playerNumber][game->tailleMainJoueur[playerNumber]] = game->pioche[game->taillePioche - 1];
		(game->tailleMainJoueur[playerNumber])++;
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

// Afficher la main d'un joueur
void Game_afficherMain(Carte *mainJoueur, int tailleMain)
{
	printf("%s\n", "Votre main de jeu : ");
	for (int i = 0; i < tailleMain; i++)
	{
		printf("Index %d : ", i);
		Carte_show(mainJoueur[i]);
	}
}

int Game_checkEmptySpace(Game *game, Carte carte, int line) {
    for (int i = 0; i < 5; i++) {
        if (game->tableau[line][i].niveau == -1) {
            // Espace vide
            game->tableau[line][i] = carte;
            return i;
        }
    }
    return -1;
}

// Jouer une carte
void Game_playCarte(Game *game, Carte carte, int playerNumber)
{
	switch (carte.niveau)
	{
		case 0:
			// Chercher un endroit
			int space = Game_checkEmptySpace(game, carte, 0);
			if (space == -1)
			{
				printf("Aucun emplacement libre dans la rangée 0");
			}
			else
			{
				printf("%s %d\n", "La carte à été placée dans la case ", space);
			}
			break;
		case 1:
			// Chercher un endroit vide dans la rangée 1 et vérifier si une carte est placée dans la rangée du dessus
			break;
		case 2:
			// Checher un endroit vide dans la rangée 2 et vérifier si une carte est placée dans la rangée du dessus
	}
}

// Prompt l'utilisateur pour choisir une carte
Carte Game_prompt(Carte *mainJoueur, int tailleMain)
{
	// Afficher les cartes du joueur
	Game_afficherMain(mainJoueur, tailleMain);

	printf("%s : %d \n", "Taille de la main du joueur", tailleMain);

	// Demander à l'utilisateur de choisir une carte
	int index;
	printf("Choisissez une carte (index) : ");
	scanf("%d", &index);
	return mainJoueur[index];
}
