#ifndef GAME_H
#define GAME_H

#include "party.h"

typedef struct {
    Party **parties;
    int num_parties;
} Game;

void Game_start(Game *game);

#endif // GAME_H