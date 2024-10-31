#ifndef GAME_H
#define GAME_H

typedef struct {
	Carte tableau[3][5];
	Carte main[10];
    Carte pioche[180];
	int taillePioche;
	Carte player[2][50];
	int tailleMainJoueur[2];
} Game;

void Game_init(Game *game);
int Game_genererCartes(Carte *pioche);
void Game_melanger(Carte *pioche, int taille);
void Game_distribuer(Game *game, int numberOfCards);
void Game_start(Game *game);
void Game_afficherMain(Carte *mainJoueur, int tailleMain);
void Game_playCarte(Game *game, Carte carte, int playerNumber);
Carte Game_prompt(Carte *mainJoueur, int tailleMain);
void Gamer_piocherCarte(Game *game, int playerNumber);
int Game_checkEmptySpace(Game *game, int line);
void Game_emptyTheTable(Game *game);
#endif
