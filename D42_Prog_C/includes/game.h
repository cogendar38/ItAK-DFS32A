#ifndef GAME_H
#define GAME_H

#include "carte.h"
#include "player.h"

typedef struct {
	Carte tableau[3][5];
	Carte main[10];
    Carte pioche[180];
	int taillePioche;
	Player players[2];
} Game;

void Game_init(Game *game);
int Game_genererCartes(Carte *pioche);
void Game_melanger(Carte *pioche, int taille);
void Game_distribuer(Game *game, int numberOfCards);
void Game_start(Game *game);
void Game_playCarte(Game *game, Carte carte, int playerNumber);
Carte Game_prompt(Player *player);
void Gamer_piocherCarte(Game *game, int playerNumber);

#endif
