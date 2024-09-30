#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Liste creer(Element data) {
    Liste newNode = (Liste)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

Liste ajoutTete(Element data, Liste l) {
    Liste newNode = creer(data);
    if (newNode != NULL) {
        newNode->next = l;
    }
    return newNode;
}

void afficheListe(Liste l, void (*afficheElement)(Element)) {
    while (l != NULL) {
        afficheElement(l->data); 
        l = l->next;
    }
    printf("\n");
}

void detruireListe(Liste l, void (*detruireElement)(Element)) {
    Liste temp;
    while (l != NULL) {
        temp = l;
        l = l->next;
        detruireElement(temp->data); 
        free(temp);
    }
}


Liste ajoutFin(Liste l, Element data) {
    if (l == NULL) {
        return creer(data);
    }
    Liste temp = l;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = creer(data);
    return l;
}

Liste cherche(Liste l, Element data, bool (*equalsElement)(Element, Element)) {
    while (l != NULL) {
        if (equalsElement(l->data, data)) {
            return l;
        }
        l = l->next;
    }
    return NULL;
}
int listLength(Liste l) {
    int length = 0;
    while (l != NULL) {
        length++;
        l = l->next;
    }
    return length;
}
