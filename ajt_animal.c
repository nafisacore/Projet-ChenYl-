#include "animal.h"


void ajouter_animal(Animal** animaux, int* nb_animaux) {
    // Vérification du nombre maximal d'animaux
    if (*nb_animaux >= MAX_ANIMAUX) {
        printf("Trop d'animaux.\n");
        return;
    }

    // Déclaration de la structure Animal pour le nouvel animal
    Animal nouvel_animal;
    nouvel_animal.id = *nb_animaux + 1;

    // Nom de l'animal + sécurisation
    printf("Nom (lettres uniquement) : ");
    fgets(nouvel_animal.nom, sizeof(nouvel_animal.nom), stdin);
    nouvel_animal.nom[strcspn(nouvel_animal.nom, "\n")] = '\0';

    // Vérification qu'il n'y a pas de chiffres dans le nom
    for (int i = 0; nouvel_animal.nom[i]; i++) {
        if (nouvel_animal.nom[i] >= '0' && nouvel_animal.nom[i] <= '9') {
            printf("Pas de chiffres dans le nom !\n");
            return;
        }
    }

    // Espèce de l'animal + sécurisation
    char espece_txt[20];
    printf("Espèce (chien, chat, hamster, autruche) : ");
    fgets(espece_txt, sizeof(espece_txt), stdin);
    espece_txt[strcspn(espece_txt, "\n")] = '\0';

    // Vérification que l'espèce est valide
    if (strcmp(espece_txt, "chien") != 0 && strcmp(espece_txt, "chat") != 0 &&
        strcmp(espece_txt, "hamster") != 0 && strcmp(espece_txt, "autruche") != 0) {
        printf("Espèce inconnue !\n");
        return;
    }

    // Conversion de l'espèce 
    nouvel_animal.espece = chaine_en_espece(espece_txt);

    // Année de naissance : vérification de l'entrée
    printf("Année de naissance : ");
    if (scanf("%d", &nouvel_animal.annee_naissance) != 1) {
        printf("Erreur année.\n");
        return;
    }
    vide_buffer();  // Vider le buffer après l'entrée de l'année

    // Poids : vérification de l'entrée
    printf("Poids (kg) : ");
    if (scanf("%f", &nouvel_animal.poids) != 1) {
        printf("Erreur poids.\n");
        return;
    }
    vide_buffer();  // Vider le buffer après l'entrée du poids

    // Commentaire : lecture sécurisée
    nouvel_animal.commentaire = malloc(500);
    if (!nouvel_animal.commentaire) {
        printf("Erreur d'allocation.\n");
        return;
    }
    printf("Commentaire (vide si rien) : ");
    fgets(nouvel_animal.commentaire, 500, stdin);
    nouvel_animal.commentaire[strcspn(nouvel_animal.commentaire, "\n")] = '\0';

    // Réallouer de la mémoire 
    if (*nb_animaux >= MAX_ANIMAUX) {
        *animaux = realloc(*animaux, (*nb_animaux + 1) * sizeof(Animal));
        if (*animaux == NULL) {
            printf("Erreur de réallocation de mémoire.\n");
            exit(30);  
        }
    }

}
