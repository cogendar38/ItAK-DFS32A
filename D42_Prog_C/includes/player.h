#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <stdio.h>

typedef struct {
	Card main;
	char *name;
	int mainLength;
	int forceTotal;
	Card *board[];
} Player;

Player Player_createPlayer();

#endif //PLAYER_H
