#include "animal.h"


void rechercher_par_id(Animal* animaux, int nb_animaux) {
    int id_recherche, veriff;
    int trouve = 0;

    // Demander à l'utilisateur d'entrer un ID 
    do {
        printf("Entrez l'ID de l’animal à rechercher : ");
        int veriff = scanf("%d", &id_recherche); 

        if (veriff != 1) {
            printf("ID invalide, veuillez entrer un entier.\n");
            vide_buffer();  // Vide le buffer en cas d'entrée invalide
        }
    } while (id_recherche <= 0 || !veriff);  

    // Recherche de l'animal par ID
    for (int i = 0; i < nb_animaux; i++) {
        if (animaux[i].id == id_recherche) {
            printf("Animal trouvé !\n");
            printf("ID : %d\n", animaux[i].id);
            printf("Nom : %s\n", animaux[i].nom);
            printf("Espèce : %d\n", animaux[i].espece);  // Affichage de l'espèce
            printf("Année de naissance : %d\n", animaux[i].annee_naissance);
            printf("Poids : %.2f kg\n", animaux[i].poids);

            // Affichage du commentaire
            if (animaux[i].commentaire != NULL && animaux[i].commentaire[0] != '\0') {
                printf("Commentaire : %s\n", animaux[i].commentaire);
            } else {
                printf("Commentaire : Aucun\n");
            }

            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucun animal trouvé avec cet ID.\n");
    }
}

