#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carte.h"
#include "game.h"
#include "player.h"

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
	printf("Démarrage en cours, veuillez patientez...\n");
	Game_init(&game);
	separator(10);

	int tourIndex = 0;
	int curentPlayer = 0;

	do {
		// Afficher le joueur qui doit jouer
		printf("%s à vous de jouer\n", game.players[curentPlayer].name);

		Carte carteChoisie = Game_prompt(&game.players[curentPlayer]);
		printf("Vous avez choisie la carte : ");
		Carte_show(carteChoisie);

		// Jouer la carte
		Player_playCarte(&game.players[curentPlayer], carteChoisie);

		tourIndex++;
		curentPlayer = !curentPlayer;
	} while (tourIndex < 4);

	// Afficher la force de chaque joueur
	printf("Joueur %s, force %d\n", game.players[0].name, game.players[0].forceTotal);
	printf("Joueur %s, force %d\n", game.players[1].name, game.players[1].forceTotal);

	// Retour à la ligne
	printf("\n");
	return 0;
}