#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a)
{
    return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire *a)
{
    *a = NULL;
}

void afficherElement(Element e)
{
    printf("%d", e);
}
// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e)
{
    ArbreBinaire a = malloc(sizeof(Noeud));
    a->val = e;
    a->filsGauche = NULL;
    a->filsDroit = NULL;
    return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e)
{
    ArbreBinaire parent = NULL;
    ArbreBinaire courant = a;
    while (courant)
    {
        parent = courant;
        if (courant->val == e)
            return a;
        if (courant->val < e)
            courant = courant->filsDroit;
        else
            courant = courant->filsGauche;
    }
    ArbreBinaire nouveau = creer(e);
    if (parent == NULL)
        return nouveau;
    if (parent->val < e)
        parent->filsDroit = nouveau;
    else
        parent->filsGauche = nouveau;
    return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e)
{
    if (estVide(a))
        return creer(e);
    else if (a->val == e)
        return a;
    else if (a->val < e)
        a->filsDroit = insere_r(a->filsDroit, e);
    else
        a->filsGauche = insere_r(a->filsGauche, e);
    return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a)
{
    ArbreBinaire courant = a;
    int cpt = 0;
    while (courant)
    {
        cpt++;
        courant = courant->filsDroit;
    }
    return cpt;
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e)
{
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a)
{
    return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem)
{

    return NULL;
}

void afficheRGD_r(ArbreBinaire a)
{
}

void afficheGRD_r(ArbreBinaire a)
{
    if (!estVide(a))
    {
        printf("(");
        afficheGRD_r(a->filsGauche);
        afficherElement(a->val);
        afficheGDR_r(a->filsDroit);
        printf(")");
    }
}

void afficheGDR_r(ArbreBinaire a)
{
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a)
{
    return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a)
{
    return NULL;
}

// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem)
{

    return NULL;
}

// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a, Element x)
{

    return NULL;
}

void detruire_r(ArbreBinaire a)
{
}
