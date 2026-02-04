// BRUNIAUX Mathis - AMPEN Axel - L3 Info - TP1 Hanoi

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void hanoi(int n, char A, char B, char C) {

    // Cas de base
    if (n == 1) {
        printf("Déplacer le disque 1 de la tour %c à la tour %c\n", A, C);
        return;
    }

    // Déplacer n-1 disques de A à C en utilisant B comme tour intermédiaire
    hanoi(n - 1, A, C, B);
    printf("Déplacer le disque %d de la tour %c à la tour %c\n", n, A, C);
    hanoi(n - 1, B, A, C);
}

int main() {
    int n = 15; // Nombre de disques (modifiable)
    struct timeval tv1, tv2; // Variables pour mesurer le temps
    double elapsed; // Temps écoulé

    printf("\n Pour %d disques :\n", n);
    // Vérification de la validité de n
    if (n <= 0) {
        fprintf(stderr, "Le nombre de disques doit être un entier positif.\n");
        return EXIT_FAILURE;
    }

    gettimeofday(&tv1, NULL); // Démarrer le chronomètre
    
    hanoi(n, 'A', 'B', 'C');

    gettimeofday(&tv2, NULL); // Arrêter le chronomètre

    elapsed = (tv2.tv_sec - tv1.tv_sec) + (tv2.tv_usec - tv1.tv_usec) / 1000000.0; // Calculer le temps écoulé
    printf("\nTemps d'exécution : %.6f secondes\n", elapsed);
    return 0;
}



