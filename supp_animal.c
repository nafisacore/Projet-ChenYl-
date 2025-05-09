#include "animal.h"

void supp_animal(Animal* animaux, int* nb_animaux) {
    int id_suppression;
    printf("Entrez l'ID de l'animal adopté : ");
    scanf("%d", &id_suppression);

    //vérification
    if (scanf("%d", &id_suppression) != 1) {
        printf("Entrée invalide. Veuillez entrer un nombre entier.\n");
        vide_buffer();  
        return;;
    }

    int trouve = 0;
    for (int i = 0; i < *nb_animaux; i++) {
        if (animaux[i].id == id_suppression) {
            // Libère la mémoire du commentaire de l’animal à supprimer
            free(animaux[i].commentaire);

            // Décale les suivants vers la gauche
            for (int j = i; j < *nb_animaux - 1; j++) {
                animaux[j] = animaux[j + 1];
            }

            (*nb_animaux)--;

            animaux = realloc(animaux, (*nb_animaux) * sizeof(Animal));
            if (animaux == NULL && *nb_animaux > 0) {
                printf("Erreur de réallocation mémoire.\n");
                exit(30);
            }

            sauvegarder_animaux(animaux, *nb_animaux);
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
