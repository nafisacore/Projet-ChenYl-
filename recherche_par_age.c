#include "animal.h"



int calculer_age(int annee_naissance) {
    return 2025 - annee_naissance;  // Calcule l'âge en fonction de l'année actuelle
}


void rechercher_par_age(Animal* animaux, int nb_animaux) {
    int choix_age;
    char *espc;
    int trouve = 0;

    // Demander à l'utilisateur de spécifier un type d'âge
    do {
        printf("Choisissez un type d'âge d'animal à rechercher :\n");
        printf("1. Jeune (moins de 3 ans)\n");
        printf("2. Adulte (entre 3 et 10 ans)\n");
        printf("3. Âgé (plus de 10 ans)\n");
        printf("Votre choix : ");
        int veriff = scanf("%d", &choix_age);
        vide_buffer();  

        if (veriff != 1 || choix_age < 1 || choix_age > 3) {
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix_age < 1 || choix_age > 3);

    // Recherche des animaux en fonction de l'âge
    for (int i = 0; i < nb_animaux; i++) {
        int age = calculer_age(animaux[i].annee_naissance);

        if ((choix_age == 1 && age < 3) ||  // Jeune
            (choix_age == 2 && age >= 3 && age <= 10) ||  // Adulte
            (choix_age == 3 && age > 10)) {  // Âgé
            printf("Animal trouvé !\n");
            printf("ID : %d\n", animaux[i].id);
            printf("Nom : %s\n", animaux[i].nom);
            espc = espece_en_chaine(animaux[i].espece);
            printf("Espèce : %d\n", espc);  // Affichage de l'espèce
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
        printf("Aucun animal trouvé avec ce critère d'âge.\n");
    }
}

