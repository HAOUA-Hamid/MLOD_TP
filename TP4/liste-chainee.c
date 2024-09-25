#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
    return l == NULL;
}

// cr�er une liste d'un seul �l�ment contenant la valeur v
Liste creer(Element v){
    Liste nouvelleListe = (Liste)malloc(sizeof(Cellule));
    if (nouvelleListe != NULL) {
        nouvelleListe->val = v;
        nouvelleListe->suiv = NULL;
    }
    return nouvelleListe;
}

// ajoute l'�l�ment v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
    Liste nouvelleListe = creer(v);
    if (nouvelleListe != NULL) {
        nouvelleListe->suiv = l;
    }
    return nouvelleListe;
}

void afficheElement(Element e) {
    printf("%i ", e);
}

// affiche tous les �l�ments de la liste l
// version it�rative
void afficheListe_i(Liste l) {
    Liste courant = l;
    while (courant != NULL) {
        afficheElement(courant->val);
        courant = courant->suiv;
    }
    printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
    if (l != NULL) {
        afficheElement(l->val);
        afficheListe_r(l->suiv);
    } else {
        printf("\n");
    }
}

void detruireElement(Element e) {}

// D�truit tous les �l�ments de la liste l
// version it�rative
void detruire_i(Liste l) {
    Liste courant = l;
    while (courant != NULL) {
        Liste suivant = courant->suiv;
        detruireElement(courant->val);
        free(courant);
        courant = suivant;
    }
}

// version r�cursive
void detruire_r(Liste l) {
    if (l != NULL) {
        detruire_r(l->suiv);
        detruireElement(l->val);
        free(l);
    }
}

// retourne la liste dans laquelle l'�l�ment v a �t� ajout� en fin
// version it�rative
Liste ajoutFin_i(Element v, Liste l) {
    if (l == NULL) {
        return creer(v);
    }
    Liste courant = l;
    while (courant->suiv != NULL) {
        courant = courant->suiv;
    }
    courant->suiv = creer(v);
    return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
    if (l == NULL) {
        return creer(v);
    }
    l->suiv = ajoutFin_r(v, l->suiv);
    return l;
}


// compare deux elements
bool equalsElement(Element e1, Element e2){
    return e1 == e2;
}

// Retourne un pointeur sur l'�l�ment de la liste l contenant la valeur v ou NULL
// version it�rative
Liste cherche_i(Element v, Liste l) {
    Liste courant = l;
    while (courant != NULL) {
        if (equalsElement(courant->val, v)) {
            return courant;
        }
        courant = courant->suiv;
    }
    return NULL;
}

// version r�cursive
Liste cherche_r(Element v, Liste l) {
    if (l == NULL) {
        return NULL;
    }
    if (equalsElement(l->val, v)) {
        return l;
    }
    return cherche_r(v, l->suiv);
}

// Retourne la liste modifi�e dans la laquelle le premier �l�ment ayant la valeur v a �t� supprim�
// ne fait rien si aucun �l�ment poss�de cette valeur
// version it�rative
Liste retirePremier_i(Element v, Liste l) {
    if (l == NULL) {
        return NULL;
    }
    if (equalsElement(l->val, v)) {
        Liste temp = l->suiv;
        detruireElement(l->val);
        free(l);
        return temp;
    }
    Liste courant = l;
    while (courant->suiv != NULL) {
        if (equalsElement(courant->suiv->val, v)) {
            Liste temp = courant->suiv;
            courant->suiv = temp->suiv;
            detruireElement(temp->val);
            free(temp);
            return l;
        }
        courant = courant->suiv;
    }
    return l;
}

// version recursive
Liste retirePremier_r(Element v, Liste l) {
    if (l == NULL) {
        return NULL;
    }
    if (equalsElement(l->val, v)) {
        Liste temp = l->suiv;
        detruireElement(l->val);
        free(l);
        return temp;
    }
    l->suiv = retirePremier_r(v, l->suiv);
    return l;
}

void afficheEnvers_r(Liste l) {
    if (l == NULL) {
        return;
    }
    afficheEnvers_r(l->suiv);
    afficheElement(l->val);
}
