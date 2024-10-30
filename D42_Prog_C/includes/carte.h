#ifndef CARTE_H
#define CARTE_H

typedef enum { BLANC, GRIS, NOIR, BLEU, ORANGE, ROUGE, VIOLET, ROSE, JAUNE, VERT } Couleur;
typedef enum { FORCE_2, FORCE_3, FORCE_4, FORCE_5, FORCE_6, FORCE_10 } Force;
typedef enum { NIVEAU_1, NIVEAU_2, NIVEAU_3 } Niveau;

typedef struct {
	Niveau niveau;
	Force force;
	Couleur couleur;
} Carte;

void show(Carte carte);
#endif
