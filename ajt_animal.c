#include "animal.h"


void ajouter_animal(Animal** animaux, int* nb_animaux) {
    if (*nb_animaux >= MAX_ANIMAUX) {
        printf("Trop d'animaux.\n");
        return;
    }

    Animal nouvel_animal;
    nouvel_animal.id = *nb_animaux + 1;

    // Nettoyer le buffer avant toute saisie fgets si nécessaire
    vide_buffer();

    //demander nom + sécurisations
    printf("Nom (lettres uniquement et première lettre en majuscule) : ");
    do {
        fgets(nouvel_animal.nom, sizeof(nouvel_animal.nom), stdin);
        nouvel_animal.nom[strcspn(nouvel_animal.nom, "\n")] = '\0';  // Enlève le '\n' ajouté par fgets

        // Vérifie que la première lettre est en majuscule
        if (nouvel_animal.nom[0] < 'A' || nouvel_animal.nom[0] > 'Z') {
            printf("La première lettre doit être en majuscule !\n");
            continue;  // Redemander tant que la première lettre n'est pas une majuscule
        }

        // Vérifie que le nom ne contient que des lettres
        int valid = 1;
        for (int i = 0; nouvel_animal.nom[i]; i++) {
        if (!isalpha(nouvel_animal.nom[i])) {
            valid = 0;
            break;
        }
        }

        if (!valid) {
            printf("Le nom ne doit contenir que des lettres sans chiffres ni symboles !\n");
        }
    } while (nouvel_animal.nom[0] == '\0' || !isalpha(nouvel_animal.nom[0]) || !isupper(nouvel_animal.nom[0]));


    char espece_txt[20];
    printf("Espèce (chien, chat, hamster, autruche) : ");
    fgets(espece_txt, sizeof(espece_txt), stdin);
    espece_txt[strcspn(espece_txt, "\n")] = '\0';

    if (strcmp(espece_txt, "chien") != 0 && strcmp(espece_txt, "chat") != 0 &&
        strcmp(espece_txt, "hamster") != 0 && strcmp(espece_txt, "autruche") != 0) {
        printf("Espèce inconnue !\n");
        return;
    }

    nouvel_animal.espece = chaine_en_espece(espece_txt);

    printf("Année de naissance (entre 1990 et 2025) : ");
    while (scanf("%d", &nouvel_animal.annee_naissance) != 1 || nouvel_animal.annee_naissance < 1990 || nouvel_animal.annee_naissance > 2025) {
        printf("Erreur : vous devez entrer une année valide (entre 1990 et 2025).\n");
        vide_buffer();  
        printf("Année de naissance (entre 1990 et 2025) : ");
    }

    vide_buffer();  // Après avoir reçu la valeur correcte, on vide le buffer.


    printf("Poids (kg) : ");
    if (scanf("%f", &nouvel_animal.poids) != 1) {
        printf("Erreur poids.\n");
        vide_buffer();
        return;
    }
    vide_buffer();

    nouvel_animal.commentaire = malloc(500);
    if (!nouvel_animal.commentaire) {
        printf("Erreur d'allocation.\n");
        return;
    }

    printf("Commentaire (vide si rien) : ");
    fgets(nouvel_animal.commentaire, 500, stdin);
    nouvel_animal.commentaire[strcspn(nouvel_animal.commentaire, "\n")] = '\0';

    // Réallocation du tableau d'animaux pour accueillir le nouvel élément
    Animal* temp = realloc(*animaux, (*nb_animaux + 1) * sizeof(Animal));
    if (temp == NULL) {
        printf("Erreur de réallocation mémoire.\n");
        free(nouvel_animal.commentaire);
        return;
    }
    *animaux = temp;

    // Ajouter l'animal au tableau
    (*animaux)[*nb_animaux] = nouvel_animal;
    (*nb_animaux)++;

    printf("Animal ajouté avec succès !\n");
}

