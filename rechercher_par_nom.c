#include "animal.h"


void rechercher_par_nom(Animal* animaux, int nb_animaux) {
    char nom_recherche[100];
    int trouve = 0;
    int veriff;
    const char *espc;

    // Demander à l'utilisateur d'entrer le nom
    do {
        printf("Entrez le nom de l’animal à rechercher (seulement des lettres) : ");
        veriff = scanf("%s", nom_recherche);  // Lecture de l'entrée du nom

        if (veriff != 1) {
            printf("Entree invalide, veuillez réessayer.\n");
            vide_buffer();
        }
    } while (veriff != 1);

    for (int i = 0; i < nb_animaux; i++) {
        if (strcmp(animaux[i].nom, nom_recherche) == 0) {
            printf("Animal trouvé !\n");
            printf("ID : %d\n", animaux[i].id);
            printf("Nom : %s\n", animaux[i].nom);
            espc = espece_en_chaine(animaux[i].espece);
            printf("Espèce : %s\n", espc);  
            printf("Année de naissance : %d\n", animaux[i].annee_naissance);
            printf("Poids : %.2f kg\n", animaux[i].poids);

            // Affichage du commentaire
            if (animaux[i].commentaire != NULL && animaux[i].commentaire[0] != '\0') {
                printf("Commentaire : %s\n", animaux[i].commentaire);
            } else {
                printf("Commentaire : Aucun\n");
            }

            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun animal trouvé avec ce nom.\n");
    }
}
    if (!trouve) {
        printf("Aucun animal trouvé avec ce nom.\n");
    }
}
