#include "player.h"


/**
 * @brief Crée un joueur, en demandant son nom à l'utilisateur.
 * @return le joueur créé.
 */
void Player_createPlayer(Player *player)
{
    player->forceTotal = 0;
    player->mainLength = 0;

    // Demander à l'utilisateur de saisir son nom
    printf("Veuillez entrez votre nom (50 caractères maximum) : ");
    scanf("%50s", player->name);
}
