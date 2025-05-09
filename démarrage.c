#include "animal.h"


void afficherMenu() {
    printf("__________________________________________\n"); 
    printf("|                                        |\n");
    printf("|        🐾  MENU CHENYL-TECH  🐾       |\n"); 
    printf("|________________________________________|\n"); 
    printf("|                                        |\n");
    printf("|    1. 🔍  Rechercher un animal  🔍    |\n"); 
    printf("|                                        |\n");
    printf("|    2. ➕   Ajouter un animal    ➕    |\n"); 
    printf("|                                        |\n");
    printf("|    3. 🏠  Adoption d'un animal  🏠    |\n");
    printf("|                                        |\n");
    printf("|    4. 🧹 Nettoyage hebdomadaire 🧹    |\n");
    printf("|                                        |\n");
    printf("|    5. 📋    Animaux par âge     📋    |\n");
    printf("|                                        |\n");
    printf("|    6. ❌        Quitter         ❌    |\n"); 
    printf("|________________________________________|\n");    
}
 

int main() {  
    int choix, verif;
    do {
        afficherMenu();
        printf("Entrer un nombre entre 1 et 4 : ");
        verif = scanf("%d", &choix);

        if (verif != 1) {
            printf("Entree invalide, reessayer : \n");
            vide_buffer();
            continue;
        }

        switch (choix) {
            case 1:
                rechercher_animal();
                quitter();
                break;
            case 2:
                ajouter_animal();
                quitter();
                break;
            case 3:
                supp_animal();
                quitter();
                break;
            case 4:
                day_clean();
                quitter();
                break;  
            case 5:
                inv_age();
                quitter();
                break;      
            case 6:
                printf("Au revoir !\n");
                exit(11);
                break;
            default:
                printf("Choix invalide, reessayer :\n");
        }
    } while (choix != 4 && choix != 2 && choix != 3 && choix != 1 && choix != 5 && choix != 6);
    liberer_memoire();
    free(animaux);  // Libère le tableau d'animaux
    return 0;
} 
