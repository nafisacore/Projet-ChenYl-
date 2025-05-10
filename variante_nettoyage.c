#include "animal.h"

void day_clean(Animal* animaux, int nb_animaux) {
    int total_minutes = 0;

    // Nettoyage des cages occupées
    for (int i = 0; i < nb_animaux; i++) {
        int temps_journalier = 0;
        int temps_hebdo = 0;

        switch (animaux[i].espece) {
            case HAMSTER:
            case CHAT:
                temps_journalier = 10;
                temps_hebdo = 20;
                break;
            case AUTRUCHE:
                temps_journalier = 20;
                temps_hebdo = 45;
                break;
            case CHIEN:
                temps_journalier = 5;
                temps_hebdo = 20;
                break;
            default:
                break;
        }

        int total = temps_journalier * 7 + temps_hebdo;
        total_minutes += total;
    }

    // Nettoyage des cages vides (2 min / jour = 14 min / semaine)
    int cages_vides = MAX_ANIMAUX - nb_animaux;
    int temps_vides = cages_vides * 14;
    total_minutes += temps_vides;

    printf("Temps total de nettoyage hebdomadaire : %d minutes = (%d heures %d min)\n",
           total_minutes, total_minutes / 60, total_minutes % 60);
}

