#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int **data;
    unsigned int nLignes;
    unsigned int nColonnes;
} Matrice;

typedef enum {
    JANVIER = 1,
    FEVRIER,
    MARS,
    AVRIL,
    MAI,
    JUIN,
    JUILLET,
    AOUT,
    SEPTEMBRE,
    OCTOBRE,
    NOVEMBRE,
    DECEMBRE
} Mois;

typedef struct {
    unsigned int jour;
    Mois mois;
    unsigned int annee;
} Date;

void initialiseDate(Date *d) {
    printf("Entrez le jour: ");
    scanf("%u", &d->jour);
    printf("Entrez le mois (1-12): ");
    int mois;
    scanf("%d", &mois);
    d->mois = (Mois)mois;
    printf("Entrez l'année: ");
    scanf("%u", &d->annee);
}

void afficheDate(const Date *d) {
    printf("Date: %u/%u/%u\n", d->jour, d->mois, d->annee);
}

Date creerDateParCopie() {
    Date unedate;
    printf("Entrez le jour: ");
    scanf("%u", &unedate.jour);
    printf("Entrez le mois (1-12): ");
    int mois;
    scanf("%d", &mois);
    unedate.mois = (Mois)mois;
    printf("Entrez l'année: ");
    scanf("%u", &unedate.annee);
    return unedate;
}

Date* newDate() {
    Date *d = (Date*)malloc(sizeof(Date));
    printf("Entrez le jour: ");
    scanf("%u", &d->jour);
    printf("Entrez le mois (1-12): ");
    int mois;
    scanf("%d", &mois);
    d->mois = (Mois)mois;
    printf("Entrez l'année: ");
    scanf("%u", &d->annee);
    return d;
}

unsigned int nbreJours(Mois mois, unsigned int annee) {
    unsigned int joursParMois[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mois == FEVRIER && (annee % 4 == 0 && (annee % 100 != 0 || annee % 400 == 0))) {
        return 29;
    }
    return joursParMois[mois - 1];
}

int dateValide(Date uneDate) {
    if (uneDate.mois < JANVIER || uneDate.mois > DECEMBRE)
        return 0;
    if (uneDate.jour < 1 || uneDate.jour > nbreJours(uneDate.mois, uneDate.annee))
        return 0;
    return 1;
}

unsigned int jourDansAnnee(Date uneDate) {
    unsigned int jourTotal = 0;
    for (Mois mois = JANVIER; mois < uneDate.mois; mois++) {
        jourTotal += nbreJours(mois, uneDate.annee);
    }
    jourTotal += uneDate.jour;
    return jourTotal;
}

Matrice* creer(int valeurInitiale, unsigned int nLignes, unsigned int nColonnes) {
    Matrice *m = (Matrice*)malloc(sizeof(Matrice));
    m->nLignes = nLignes;
    m->nColonnes = nColonnes;
    m->data = (int**)malloc(nLignes * sizeof(int*));
    for (unsigned int i = 0; i < nLignes; i++) {
        m->data[i] = (int*)malloc(nColonnes * sizeof(int));
        for (unsigned int j = 0; j < nColonnes; j++) {
            m->data[i][j] = valeurInitiale;
        }
    }
    return m;
}

void liberer(Matrice *m) {
    for (unsigned int i = 0; i < m->nLignes; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void echangeContenu(int *a, int *b) {
    int j = *a;
    *a = *b;
    *b = j;
}

void matrix_mult(int64_t matriceResultat[SIZE][SIZE], int64_t matrice1[SIZE][SIZE], int64_t matrice2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matriceResultat[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                matriceResultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }
}

void matrix_print(int64_t matriceResultat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
       for (int j = 0; j < SIZE; j++) {
            printf("%lld ", matriceResultat[i][j]);
        }
        printf("\n");
    }
}

void matrix_print_dynamique(Matrice *matrice) {
    for (unsigned int i = 0; i < matrice->nLignes; i++) {
        for (unsigned int j = 0; j < matrice->nColonnes; j++) {
            printf("%d ", matrice->data[i][j]);
        }
        printf("\n");
    }
}

void matrix_mult_dynamique(Matrice *matriceResultat, Matrice *matrice1, Matrice *matrice2) {
    for (unsigned int i = 0; i < matriceResultat->nLignes; i++) {
        for (unsigned int j = 0; j < matriceResultat->nColonnes; j++) {
            matriceResultat->data[i][j] = 0;
            for (unsigned int k = 0; k < matrice1->nColonnes; k++) {
                matriceResultat->data[i][j] += matrice1->data[i][k] * matrice2->data[k][j];
            }
        }
    }
}

int main() {
    printf("exo1\n");
    int a = 10;
    int b = 20;
    echangeContenu(&a, &b);
    printf("a : %d, b : %d\n", a, b);

    printf("\nexo2\n");
    int64_t matrice1[][SIZE] = {{1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}};
    int64_t matrice2[][SIZE] = {{6,7,8,9,10}, {6,7,8,9,10}, {6,7,8,9,10}, {6,7,8,9,10}, {6,7,8,9,10}};
    int64_t matriceResultat[SIZE][SIZE];
    matrix_mult(matriceResultat, matrice1, matrice2);
    matrix_print(matriceResultat);

    printf("\nexo3\n");
    printf("b)\n");
    Date d1;
    initialiseDate(&d1);
    afficheDate(&d1);

    printf("c)\n");
    Date d2;
    d2 = creerDateParCopie();
    afficheDate(&d2);

    printf("d)\n");
    Date *d3;
    d3 = newDate();
    afficheDate(d3);
    free(d3);

    printf("\nexo3 Bonus\n");
    Date d4;
    initialiseDate(&d4);
    if (dateValide(d4)) {
        printf("Date is valid.\n");
        printf("This date is the %u day of the year.\n", jourDansAnnee(d4));
    } else {
        printf("Invalid date.\n");
    }

    printf("\nexo 4 (Matrices Dynamiques)\n");
    Matrice *A = creer(1, 2, 3);
    Matrice *B = creer(2, 3, 3);
    Matrice *C = creer(0, 2, 3);

    printf("Matrix A:\n");
    matrix_print_dynamique(A);

    printf("Matrix B:\n");
    matrix_print_dynamique(B);

    matrix_mult_dynamique(C, A, B);

    printf("Matrix A x B = C:\n");
    matrix_print_dynamique(C);

    liberer(A);
    liberer(B);
    liberer(C);

    return 0;
}
