#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hrouf(const char *str);
void supprime(Contact *c, char id, int n);
void ajout(Contact **tete, int n);
void afficher(Contact *tete, int n);
Contact* recherche(Contact *temp, int id);
void liberer(Contact *tete);
