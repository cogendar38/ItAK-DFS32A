#ifndef PLAYER_H
#define PLAYER_H

#include "carte.h"

typedef struct {
	int number;
	char name[20];
	Carte main[10];
	int tailleMain;
	Carte board[3][5];
	int forceTotal;
} Player;

Player Player_createPlayer();
void Player_emptyTheBoard(Player *player);
void Player_afficherMain(Player *player);
void Player_playCarte(Player *player, Carte carte);
int Player_checkEmptySpace(Carte *line);

#endif