#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdbool.h>

typedef void* Element;

typedef struct Node {
    Element data;
    struct Node* next;
} Node;

typedef Node* Liste;

Liste creer(Element data);
Liste ajoutTete(Element data, Liste l);
void afficheListe(Liste l, void (*afficheElement)(Element));
void detruireListe(Liste l, void (*detruireElement)(Element));
Liste ajoutFin(Liste l, Element data);
Liste cherche(Liste l, Element data, bool (*equalsElement)(Element, Element));

#endif
