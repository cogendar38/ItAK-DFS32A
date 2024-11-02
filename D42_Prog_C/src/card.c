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


/**
 * @brief Crée une carte avec un niveau, une couleur et une force spécifiés.
 * 
 * Cette fonction initialise une carte en mappant les entiers fournis
 * en paramètres vers les énumérations correspondantes pour le niveau,
 * la couleur et la force. Si les valeurs fournies ne correspondent pas
 * à une option valide, des valeurs par défaut sont utilisées.
 * 
 * @param niveau Un entier représentant le niveau de la carte (0 à 2).
 * @param couleur Un entier représentant la couleur de la carte (0 à 9).
 * @param force Un entier représentant la force de la carte (1 à 6).
 * 
 * @return Une structure Carte initialisée avec les valeurs spécifiées.
 */
Card Carte_create(int niveau, int couleur, int force)
{
	Card carte;

	// Mapping des niveaux
	switch (niveau) {
		case 0:
			carte.niveau = LEVEL_1;
		break;
		case 1:
			carte.niveau = LEVEL_2;
		break;
		case 2:
			carte.niveau = LEVEL_3;
		break;
	}

	// Mapping des couleurs
	switch (couleur) {
		case 0:
			carte.couleur = COLOR_WHITE;
		break;
		case 1:
			carte.couleur = COLOR_GRAY;
		break;
		case 2:
			carte.couleur = COLOR_BLACK;
		break;
		case 3:
			carte.couleur = COLOR_BLUE;
		break;
		case 4:
			carte.couleur = COLOR_ORANGE;
		break;
		case 5:
			carte.couleur = COLOR_RED;
		break;
		case 6:
			carte.couleur = COLOR_PURPLE;
		break;
		case 7:
			carte.couleur = COLOR_PINK;
		break;
		case 8:
			carte.couleur = COLOR_YELLOW;
		break;
		case 9:
			carte.couleur = COLOR_GREEN;
		break;
		default:
			carte.couleur = COLOR_WHITE; // Couleur par défaut
		break;
	}

	// Mapping des forces
	switch (force) {
		case 1:
			carte.force = FORCE_2;
		break;
		case 2:
			carte.force = FORCE_3;
		break;
		case 3:
			carte.force = FORCE_4;
		break;
		case 4:
			carte.force = FORCE_5;
		break;
		case 5:
			carte.force = FORCE_6;
		break;
		case 6:
			carte.force = FORCE_10;
		break;
		default:
			carte.force = FORCE_2; // Force par défaut
		break;
	}

    return carte;
}