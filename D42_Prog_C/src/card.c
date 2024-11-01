#include "card.h"

/**
 * @brief Renvoie la couleur de la carte, en fonction de l'enum Couleur.
 * @param card la carte dont on veut la couleur.
 * @return un string qui correspond à la couleur de la carte.
 */
const char *Card_getCouleur(Card card)
{
    switch (card.couleur)
    {
        case COLOR_WHITE:
            return "Blanc";
        case COLOR_GRAY:
            return "Gris";
        case COLOR_BLACK:
            return "Noir";
        case COLOR_BLUE:
            return "Bleu";
        case COLOR_ORANGE:
            return "Orange";
        case COLOR_RED:
            return "Rouge";
        case COLOR_PURPLE:
            return "Violet";
        case COLOR_PINK:
            return "Rose";
        case COLOR_YELLOW:
            return "Jaune";
        case COLOR_GREEN:
            return "Vert";
        default:
            return "Couleur inconnue";
    }
}

/**
 * @brief Renvoie la force de la carte, en fonction de l'enum Force.
 * @param card la carte dont on veut la force.
 * @return un string qui correspond à la force de la carte.
 */
const char *Card_getForce(Card card)
{
    switch (card.force)
    {
        case FORCE_2:
            return "2";
        case FORCE_3:
            return "3";
        case FORCE_4:
            return "4";
        case FORCE_5:
            return "5";
        case FORCE_6:
            return "6";
        case FORCE_10:
            return "10";
        default:
            return "Force inconnue";
    }
}

/**
 * @brief Renvoie le niveau de la carte, en fonction de l'enum Niveau.
 * @param card la carte dont on veut le niveau.
 * @return un string qui correspond au niveau de la carte.
 */
const char *Card_getNiveau(Card card)
{
    switch (card.niveau)
    {
        case LEVEL_1:
            return "Niveau 1";
        case LEVEL_2:
            return "Niveau 2";
        case LEVEL_3:
            return "Niveau 3";
        default:
            return "Niveau inconnu";
    }
}