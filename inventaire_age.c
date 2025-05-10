#include "animal.h"

void inv_age(Animal* animaux, int nb_animaux) {
    int tranche1 = 0, tranche2 = 0, tranche3 = 0, tranche4 = 0;

    if (nb_animaux == 0) {
        printf("Aucun animal dans le refuge.\n");
        return;
    }

    for (int i = 0; i < nb_animaux; i++) {
        int age = 2025 - animaux[i].annee_naissance;

        if (age <= 2)
            tranche1++;
        else if (age <= 5)
            tranche2++;
        else if (age <= 9)
            tranche3++;
        else
            tranche4++;
    }

    printf("Nombre total d'animaux : %d\n", nb_animaux);
    printf("0 à 2 ans     : %d animaux\n", tranche1);
    printf("3 à 5 ans     : %d animaux\n", tranche2);
    printf("6 à 9 ans     : %d animaux\n", tranche3);
    printf("10 ans et +   : %d animaux\n", tranche4);
}

