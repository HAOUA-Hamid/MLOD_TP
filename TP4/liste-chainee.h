#pragma once

#include <stdbool.h>

typedef int Element;

struct cellule_s {
	Element val;
	struct cellule_s* suiv;
};

typedef struct cellule_s Cellule;

typedef Cellule* Liste;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l);

// cr�er une liste d'un seul �l�ment contenant la valeur v
Liste creer(Element v);

// ajoute l'�l�ment v en tete de la liste l
Liste ajoutTete(Element v, Liste l);

void afficheElement(Element e);

// affiche tous les �l�ments de la liste l
// Attention, cette fonction doit �tre ind�pendante du type des �l�ments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut �tre vide !
// version it�rative
void afficheListe_i(Liste l);

// version recursive
void afficheListe_r(Liste l);

void detruireElement(Element e);

// D�truit tous les �l�ments de la liste l
// version it�rative
void detruire_i(Liste l);

// version r�cursive
void detruire_r(Liste l);

// retourne la liste dans laquelle l'�l�ment v a �t� ajout� en fin
// version it�rative
Liste ajoutFin_i(Element v, Liste l);

// version recursive
Liste ajoutFin_r(Element v, Liste l);

// Retourne un pointeur sur l'�l�ment de la liste l contenant la valeur v ou NULL
// version it�rative
Liste cherche_i(Element v,Liste l);

// version r�cursive
Liste cherche_r(Element v,Liste l);

// Retourne la liste modifi�e dans la laquelle le premier �l�ment ayant la valeur v a �t� supprim�
// ne fait rien si aucun �l�ment poss�de cette valeur
// version it�rative
Liste retirePremier_i(Element v, Liste l);

// version recursive
Liste retirePremier_r(Element v, Liste l);


void afficheEnvers_r(Liste l);
