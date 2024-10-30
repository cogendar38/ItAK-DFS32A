#ifndef GAME_H
#define GAME_H

typedef struct {
	Carte tableau[3][5];
	Carte main[10];
    	Carte pioche[180];
	Carte player1[50];
	Carte player2[50];
} Game;

void Game_init(Game *game);
int Game_genererCartes(Carte *pioche);
void Game_melanger(Carte *pioche, int taille);
void Game_distribuer(Carte *pioche);
void Game_start(Game *game);
void Game_piocher(Carte *player, int playerNumber);
Carte Game_prompt(Carte *player);

#endif
