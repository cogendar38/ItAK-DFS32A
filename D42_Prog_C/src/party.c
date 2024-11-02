#include "party.h"
#include "card.h"
#include "utils.h"
#include <stdio.h>

/**
 * @brief Lance une nouvelle partie de GOZU.
 *
 * Demande aux joueurs de saisir leur nom, puis crée une nouvelle partie
 * avec ces deux joueurs. Affiche ensuite un message de bienvenue.
 * @return la partie créée.
 */
Party Party_play() {
    // Lancer une partie
    printf("Lancement de la partie...\n");

    Party party;

    // Création des joueurs
    printf("Création du premier joueur...\n");
    Player player1;
    party.joueurs[0] = player1;
    Player_createPlayer(&party.joueurs[0]);

    printf("Création du deuxième joueur...\n");
    Player player2;
    party.joueurs[1] = player2;
    Player_createPlayer(&party.joueurs[1]);

    separator(10);
    printf("Nouvelle partie\n%s vs %s\n", party.joueurs[0].name, party.joueurs[1].name);

    // Génération de la pioche 
    int nbCartes = Party_cardsGenerate(party.pioche);
    
    // Fin de partie
    // TODO: Définir le gagnant

    return party;
}

/**
* @brief Génére les cartes de la pioche
* @return le nombre de cartes créees
*/
int Party_cardsGenerate(Card *pioche) {
    int index = 0;

    // Chaque niveaux
	for (int n = 0; n < 3; n++)
	{
		// Chaque couleur
		for (int c = 0; c < 10; c++)
		{
			// Chaque force
			for (int f = 0; f < 6; f++)
			{
				// Création de la carte
				Card card = Card_create(n,c,f);
				pioche[index] = card;
				index++;
			}
		}
	}

	printf("%d %s\n", index, "cartes crée(s)");
	return index;
}