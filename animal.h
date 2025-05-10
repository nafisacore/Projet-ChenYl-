#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANIMAUX 50


//énumération des espèces
typedef enum {
    CHIEN,
    CHAT,
    HAMSTER,
    AUTRUCHE
} Espece;

//structure animale
typedef struct {
    int id;
    char nom[100];
    Espece espece;
    int annee_naissance;
    float poids;
    char *commentaire;
} Animal;

//démarrage.c
void afficherMenu();
void vide_buffer();
void ajouter_animal(Animal** animaux, int* nb_animaux);
void supp_animal(Animal** animaux, int* nb_animaux);

//recherche
void rechercher_animal(Animal* animaux, int nb_animaux);
void rechercher_par_nom(Animal* animaux, int nb_animaux);
void rechercher_par_id(Animal* animaux, int nb_animaux);

//recherche par age
int calculer_age(int annee_naissance);
void rechercher_par_age(Animal* animaux, int nb_animaux);

//variantes
void day_clean(Animal* animaux, int nb_animaux);
void inv_age(Animal* animaux, int nb_animaux);

//suite.c
const char* espece_en_chaine(Espece e);
Espece chaine_en_espece(const char* s);
void charger_nombre_animaux(int* nb_animaux);
void sauvegarder_nombre_animaux(int nb_animaux);
void charger_animaux(Animal** animaux, int* nb_animaux);
void sauvegarder_animaux(Animal* animaux, int nb_animaux);
void liberer_memoire(Animal* animaux, int nb_animaux);

