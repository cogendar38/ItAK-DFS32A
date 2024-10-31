#ifndef PLAYER_H
#define PLAYER_H

#include "carte.h"

typedef struct {
	int number;
	char name[20];
	Carte main[10];
	int tailleMain;
} Player;

Player Player_createPlayer();

#endif