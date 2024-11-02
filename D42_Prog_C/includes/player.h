#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <stdio.h>

typedef struct {
	Card main;
	char name[50];
	int mainLength;
	int forceTotal;
	Card *board[];
} Player;

void Player_createPlayer(Player *player);

#endif //PLAYER_H