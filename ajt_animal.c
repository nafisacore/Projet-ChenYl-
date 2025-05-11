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

    printf("Nom (lettres uniquement) : ");
    fgets(nouvel_animal.nom, sizeof(nouvel_animal.nom), stdin);
    nouvel_animal.nom[strcspn(nouvel_animal.nom, "\n")] = '\0';

    for (int i = 0; nouvel_animal.nom[i]; i++) {
        if (!isalpha(nouvel_animal.nom[i])) {
            printf("Pas de chiffres ni de symboles dans le nom !\n");
            return;
        }
    }

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

    printf("Année de naissance : ");
    if (scanf("%d", &nouvel_animal.annee_naissance) != 1) {
        printf("Erreur année.\n");
        vide_buffer();
        return;
    }
    vide_buffer();

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
