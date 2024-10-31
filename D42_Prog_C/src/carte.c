#include "carte.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Créer une carte
Carte Carte_create(int niveau, int couleur, int force)
{
	Carte carte;

	// Mapping des niveaux
	switch (niveau) {
		case 0:
			carte.niveau = NIVEAU_1;
		break;
		case 1:
			carte.niveau = NIVEAU_2;
		break;
		case 2:
			carte.niveau = NIVEAU_3;
		break;
	}

	// Mapping des couleurs
	switch (couleur) {
		case 0:
			carte.couleur = BLANC;
		break;
		case 1:
			carte.couleur = GRIS;
		break;
		case 2:
			carte.couleur = NOIR;
		break;
		case 3:
			carte.couleur = BLEU;
		break;
		case 4:
			carte.couleur = ORANGE;
		break;
		case 5:
			carte.couleur = ROUGE;
		break;
		case 6:
			carte.couleur = VIOLET;
		break;
		case 7:
			carte.couleur = ROSE;
		break;
		case 8:
			carte.couleur = JAUNE;
		break;
		case 9:
			carte.couleur = VERT;
		break;
		default:
			carte.couleur = BLANC; // Couleur par défaut
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

const char *Carte_getNiveau(int niveau)
{
    const char *niveaux[] = {"1", "2", "3"};

    // Vérifier si le niveau est valide
    if (niveau >= 0 && niveau < 3) {
        return niveaux[niveau];
    } else {
        // Retourner une chaîne de caractères par défaut si le niveau n'est pas valide
        return "Invalide";
    }
}

const char *Carte_getCouleur(int couleur)
{
	const char *couleurs[] = {"blanc", "gris", "noir", "bleu", "orange", "rouge", "violet", "rose", "jaune", "vert"};
	return couleurs[couleur];
}

const char *Carte_getForce(int force)
{
	const char *forces[] = {"2", "3", "4", "5", "6", "10"};
	return forces[force];	
}

// Afficher une carte
void Carte_show(Carte carte)
{
	const char *niveaux[] = {"1", "2", "3"};
	const char *forces[] = {"2", "3", "4", "5", "6", "10"};
	const char *couleurs[] = {"blanc", "gris", "noir", "bleu", "orange", "rouge", "violet", "rose", "jaune", "vert"};

	printf("Niveau %s - Couleur %s - Force %s\n", Carte_getNiveau(carte.niveau), Carte_getCouleur(carte.couleur), Carte_getForce(carte.force));
}