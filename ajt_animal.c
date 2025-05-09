#include "animal.h"


//Procédure ajouter un animal
void ajouter_animal(Animal** animaux, int* nb_animaux) {
    if (*nb_animaux >= MAX_ANIMAUX) {
        printf("Le nombre maximal d'animaux est atteint.\n");
        return;
    }

    Animal nouvel_animal;
    nouvel_animal.id = *nb_animaux + 1;  

    // Saisie des infos par l'utilisateur

    //nom
    printf("Entrez le nom de l'animal: ");
    scanf("%s", nouvel_animal.nom);
    
    //espece
    printf("Entrez l'espece (chien, chat, hamster, autruche): ");
    char race[20];
    scanf("%s", race);
    nouvel_animal.espece = chaine_en_espece(race);

    //année de naissance
    printf("Entrez l'année de naissance de l'animal: ");
    scanf("%d", &nouvel_animal.annee_naissance);

    //poids
    printf("Entrez le poids de l'animal en kg: ");
    scanf("%f", &nouvel_animal.poids);

    // Saisie du commentaire
    nouvel_animal.commentaire = malloc(500 * sizeof(char));  // Alloue de la mémoire pour le commentaire
    if (nouvel_animal.commentaire == NULL) {
        printf("Erreur d'allocation mémoire pour le commentaire.\n");
        exit(5);
    }

    printf("Entrez un commentaire : ");
    scanf(" %[^\n]", nouvel_animal.commentaire);  // Prend toute la ligne avec espaces

    // On agrandit le tableau pour ajouter l’animal
    *animaux = realloc(*animaux, (*nb_animaux + 1) * sizeof(Animal));
    if (*animaux == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(6);
    }

    // On met l’animal à la fin du tableau
    (*animaux)[*nb_animaux] = nouvel_animal;
    (*nb_animaux)++;

    sauvegarder_animaux(*animaux, *nb_animaux);        
    sauvegarder_nombre_animaux(*nb_animaux);   

    printf("L'animal a été ajouté avec succès !\n");

} 
