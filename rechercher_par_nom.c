#include "animal.h"

void rechercher_par_nom(Animal* animaux, int nb_animaux) {
    char nom_recherche[100];
    int trouve = 0;

    // Demander à l'utilisateur d'entrer le nom
    do {
        printf("\nEntrez le nom de l’animal à rechercher (1ère lettre en majuscules) : ");
        
        // Utilisation de fgets pour lire l'entrée complète
        if (fgets(nom_recherche, sizeof(nom_recherche), stdin) == NULL) {
            printf("Erreur de lecture.\n");
            return;
        }
        
        // Supprimer le caractère de nouvelle ligne ajouté par fgets
        nom_recherche[strcspn(nom_recherche, "\n")] = '\0';

        // Vérifier que le nom ne contient que des lettres (pas d'espaces ni de chiffres)
        int valid = 1;
        for (int i = 0; nom_recherche[i] != '\0'; i++) {
            if (!isalpha(nom_recherche[i])) {
                valid = 0;
                break;
            }
        }

        if (islower(nom_recherche[0])) {
            valid = 0;
        }

        if (!valid) {
            printf("Nom invalide, uniquement des lettres sans espaces autorisées.\n");
        }

    } while (nom_recherche[0] == '\0' || !isalpha(nom_recherche[0]) || islower(nom_recherche[0])); // Redemander si nom invalide

    // Recherche de l'animal
    for (int i = 0; i < nb_animaux; i++) {
        if (strcmp(animaux[i].nom, nom_recherche) == 0) {
            printf("\nAnimal trouvé !\n");
            printf("ID : %d\n", animaux[i].id);
            printf("Nom : %s\n", animaux[i].nom);
            const char *espc = espece_en_chaine(animaux[i].espece);
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
