#include "animal.h"


void rechercher_animal(Animal* animaux, int nb_animaux) {
    int choixx, veriff;
    
    do{
        printf("Souhaitez-vous rechercher l'animal par :\n1. Son nom\n2. Son ID\n3. Son type d'âge\n4. Quitter\nChoisissez : ");
        veriff = scanf("%d", &choixx);

        if (veriff != 1) {
            printf("Entree invalide, reessayer : \n");
            vide_buffer();
            continue;
        }

        switch (choixx) {
            case 1:
                rechercher_par_nom(animaux, nb_animaux);
                break;
            case 2:
                rechercher_par_id(animaux, nb_animaux);
                break;
            case 3:
                rechercher_par_age(animaux, nb_animaux);
                break;
            case 4:
                printf("AU revoir !");
                break;
            default :
                printf("Choix invalide, choisissez un chiffre entre 1 et 4:");    
        }    
    }while(choixx != 1 && choixx != 2 && choixx != 3 && choixx != 4);
               
}
