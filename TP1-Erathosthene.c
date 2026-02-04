// BRUNIAUX Mathis - AMPEN Axel - L3 Info - TP1 Erathosthene

#include <stdlib.h>
#include <stdio.h>


void cribleEratosthene(int N) {
    int *tableau = malloc((N + 1) * sizeof(int));
    if (tableau == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= N; i++) {
        tableau[i] = 0; // 0 signifie non coché
    }

    tableau[0] = 1; // Cocher 0
    tableau[1] = 1; // Cocher 1

    for (int p = 2; p * p <= N; p++) {
        if (tableau[p] == 0) { // Si p n'est pas coché
            for (int multiple = p * p; multiple <= N; multiple += p) {
                tableau[multiple] = 1; // Cocher le multiple
            }
        }
    }

    printf("Nombres premiers inférieurs ou égaux à %d :\n", N);
    for (int i = 2; i <= N; i++) {
        if (tableau[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(tableau);
}

int main() {
    int N = 100;
    if (N < 2) {
        fprintf(stderr, "N doit être un entier supérieur ou égal à 2.\n");
        return EXIT_FAILURE;
    }

    cribleEratosthene(N);

    return 0;
}


