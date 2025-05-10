#include "animal.h"

// Fonction pour supprimer un animal
void supp_animal(Animal** animaux, int* nb_animaux) {
    int id_suppression;

    // Lecture de l'ID avec validation de l'entrée
    while (1) {
        printf("Entrez l'ID de l'animal à supprimer : ");
        
        // Vérifie si l'entrée est un entier valide
        if (scanf("%d", &id_suppression) != 1) {
            printf("Entrée invalide.\n");
            vide_buffer();
        } else if (id_suppression <= 0 || id_suppression > *nb_animaux) {
            // Vérifie si l'ID est dans une plage valide
            printf("ID invalide. L'ID doit être compris entre 1 et %d.\n", *nb_animaux);
        } else {
            // Si l'entrée est valide, on sort de la boucle
            break;
        }
    }

    int trouve = 0;
    for (int i = 0; i < *nb_animaux; i++) {
        if ((*animaux)[i].id == id_suppression) {
            // Libère la mémoire du commentaire de l’animal à supprimer
            free((*animaux)[i].commentaire);

            // Décale les éléments suivants vers la gauche
            for (int j = i; j < *nb_animaux - 1; j++) {
                (*animaux)[j] = (*animaux)[j + 1];
            }

            (*nb_animaux)--;

            // Réallocation de mémoire pour le tableau d'animaux
            Animal* temp = realloc(*animaux, (*nb_animaux) * sizeof(Animal));
            if (temp == NULL && *nb_animaux > 0) {
                printf("Erreur de réallocation mémoire.\n");
                exit(30);
            }
            *animaux = temp;

            sauvegarder_animaux(*animaux, *nb_animaux);
            sauvegarder_nombre_animaux(*nb_animaux);

            printf("Animal supprimé.\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucun animal avec cet ID trouvé.\n");
    }
}
