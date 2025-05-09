#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "suite.c"
#include "ajt_animal.c"
#include "supp_animal.c"
#include "rechercher_animal.c"
#include "rechercher_par_nom.c"
#include "rechercher_par_id.c"
#include "rechercher_par_age.c"
#include "variante_nettoyage.c"
#include "inventaire_age.c"
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

void vide_buffer(){
    while(getchar() != '\n'){
    }
}

void quitter(){
    int retour, verif;
        do {
            printf("\nSouhaitez-vous retourner au menu principal ? (1 = Oui / 0 = Non) : ");
            verif = scanf("%d", &retour);
            vide_buffer();

            if (verif != 1 || (retour != 0 && retour != 1)) {
                printf("Entrée invalide, veuillez taper 1 ou 0.\n");
            }
        } while (verif != 1 || (retour != 0 && retour != 1));

        if (retour == 0) {
            printf("Merci d'avoir utilisé Chenyl-Tech !\n");
            exit(10);
        }
}

