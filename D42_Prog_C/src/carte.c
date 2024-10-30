#include "../includes/carte.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Afficher une carte
void show(Carte carte)
{
	const char *niveaux[] = {"1", "2", "3"};
	const char *forces[] = {"2", "3", "4", "5", "6", "10"};
	const char *couleurs[] = {"blanc", "gris", "noir", "bleu", "orange", "rouge", "violet", "rose", "jaune", "vert"};

	printf("%s-%s-%s", niveaux[carte.niveau], couleurs[carte.couleur], forces[carte.force]);
}
