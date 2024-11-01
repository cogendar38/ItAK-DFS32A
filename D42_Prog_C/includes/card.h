#ifndef CARD_H
#define CARD_H

typedef enum {
    COLOR_WHITE,
    COLOR_GRAY,
    COLOR_BLACK,
    COLOR_BLUE,
    COLOR_ORANGE,
    COLOR_RED,
    COLOR_PURPLE,
    COLOR_PINK,
    COLOR_YELLOW,
    COLOR_GREEN
} Couleur;

typedef enum {
    FORCE_2,
    FORCE_3,
    FORCE_4,
    FORCE_5,
    FORCE_6,
    FORCE_10
} Force;

typedef enum {
    LEVEL_1,
    LEVEL_2,
    LEVEL_3
} Niveau;

typedef struct {
    Couleur couleur;
    Force force;
    Niveau niveau;
} Card;

const char *Card_getCouleur(Card card);
const char *Card_getForce(Card card);
const char *Card_getNiveau(Card card);

#endif // CARD_H