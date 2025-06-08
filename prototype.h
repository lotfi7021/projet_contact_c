#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact {
    char ID[8];
    char nom[20];
    char prenom[20];
    int age;
    char numero[8];
    struct Contact* suiv;
} Contact;

int hrouf(const char *str);
int unique(Contact *tete, const char *id);
void supprime(Contact **tete, const char *id);
void ajout(Contact **tete, int n);
void ajout1(Contact **tete);
Contact* trier(Contact *tete);
void afficher(Contact *tete);
Contact* recherche(Contact *tete, const char *id);
void liberer(Contact *tete);


#endif
