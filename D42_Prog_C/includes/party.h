#ifndef PARTY_H
#define PARTY_H

#include "player.h"
#include "card.h"

typedef struct {
	Player joueurs[2];
	Card pioche[180];
	Player winner;
} Party;

Party Party_play();

#endif //PARTY_H