#include "player.h"
#include "carte.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

Player Player_createPlayer()
{
	Player player;

	player.tailleMain = 0;

	// Prompt l'utilisateur pour récupérer nom
	printf("Veuillez saisir votre nom : \n");
	scanf("%19s", player.name);

	printf("Bonjour %s\n", player.name);

	return player;
}