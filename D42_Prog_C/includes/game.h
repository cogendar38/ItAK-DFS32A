#ifndef GAME_H
#define GAME_H

typedef struct {
	Carte tableau[3][5];
	Carte main[10];
    Carte pioche[180];
	int tailleMain;
} Game;

void Game_init(Game *game);
void Game_genererCartes(Carte pioche[]);
void Game_melanger(Carte pioche[], int taille);

#endif
