#include "animal.h"


//convertir une espèce en chaîne de caractères
const char* espece_en_chaine(Espece e) {
    switch (e) {
        case CHIEN: return "chien";
        case CHAT: return "chat";
        case HAMSTER: return "hamster";
        case AUTRUCHE: return "autruche";
        default: return "inconnu";
    }
}

//convertir une chaîne de caractères en espèce
Espece chaine_en_espece(const char* s) {
    if (strcmp(s, "chien") == 0) return CHIEN;
    if (strcmp(s, "chat") == 0) return CHAT;
    if (strcmp(s, "hamster") == 0) return HAMSTER;
    if (strcmp(s, "autruche") == 0) return AUTRUCHE;
    return CHIEN;
}



// Charge le nombre d'animaux depuis le fichier
void charger_nombre_animaux(int *nb_animaux) {
    FILE *f = fopen("nb_animaux.txt", "r");
    if (f != NULL) {
        fscanf(f, "%d", nb_animaux);
        fclose(f);
    } else {
        printf("Erreur d'ouverture du fichier.\n");
        *nb_animaux = 0;
        exit(1);
    }
}

// Sauvegarde le nombre d'animaux dans le fichier
void sauvegarder_nombre_animaux(int nb_animaux) {
    FILE *f = fopen("nb_animaux.txt", "w");
    if (f != NULL) {
        fprintf(f, "%d", nb_animaux);
        fclose(f);
    }
    else{
        printf("Erreur d'ouverture du fichier.\n");
        exit(2);
    }
}

// Charge les animaux depuis le fichier
void charger_animaux(Animal* animaux, int* nb_animaux) {
    charger_nombre_animaux(nb_animaux);
    if (*nb_animaux > MAX_ANIMAUX) {
        *nb_animaux = MAX_ANIMAUX;
    }

    animaux = malloc(*nb_animaux * sizeof(Animal));
    if (animaux == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(3);
    }

    FILE *f = fopen("animaux.txt", "r");
    if (f == NULL) {
        printf("Pas de fichier animaux.txt trouvé.\n");
        exit(4);
    }

    for (int i = 0; i < *nb_animaux; i++) {
        char comm[500];
        char esp[50];

        fscanf(f, "%d;%s;%s;%d;%f;%199[^\n]\n",
               &animaux[i].id,
               animaux[i].nom,
               esp,
               &animaux[i].annee_naissance,
               &animaux[i].poids,
               comm);
        animaux[i].espece = chaine_en_espece(esp);
        animaux[i].commentaire = malloc(strlen(comm) + 1);
        if (animaux[i].commentaire == NULL) {
            printf("Erreur d'allocation mémoire.\n");
            exit(6);
        }
        strcpy(animaux[i].commentaire, comm);
    }

    fclose(f);
}

//Sauvegarde les animaux dans le fichier
void sauvegarder_animaux(Animal* animaux, int nb_animaux) {
    FILE *f = fopen("animaux.txt", "w");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier animaux.txt\n");
        return;
    }

    for (int i = 0; i < nb_animaux; i++) {
        fprintf(f, "%d;%s;%s;%d;%.2f;%s\n",
                animaux[i].id,
                animaux[i].nom,
                espece_en_chaine(animaux[i].espece),
                animaux[i].annee_naissance,
                animaux[i].poids,
                animaux[i].commentaire);
    }

    fclose(f);
    sauvegarder_nombre_animaux(nb_animaux); 
}

void liberer_memoire(Animal* animaux, int nb_animaux) {
    // Libérer la mémoire allouée pour les commentaires des animaux
    for (int i = 0; i < nb_animaux; i++) {
        free(animaux[i].commentaire); 
    }
}    
