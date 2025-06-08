#include "prototype.h"

#define RESET "\x1b[0m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BOLD "\x1b[1m"




int hrouf(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z') && str[i] != '\0') {
            return 1;
        }
    }
    return 0;
}


int unique(Contact *tete, const char *id) {
    Contact *current = tete;
    while (current != NULL) {
        if (strcmp(current->ID, id) == 0) {
            printf(" %s ID Existe Deja!!! \n %s",RED,RESET);
            return 0;
        }
        current = current->suiv;
    }
    return 1;
}



void ajout(Contact **tete, int n) {
    Contact *nouveau, *dernier = NULL;

    for (int i = 0; i < n; i++) {
        nouveau = (Contact *)malloc(sizeof(Contact));
        if (nouveau == NULL) {
            printf("Erreur d'allocation memoire.\n");
            exit(1);
        }

        do {
            printf("* ID     *   ");
            scanf("%s", nouveau->ID);
        } while (strlen(nouveau->ID) > 8 || !unique(*tete, nouveau->ID));


        do {
            printf("* Nom    *   ");
            scanf("%s", nouveau->nom);
        } while (hrouf(nouveau->nom));

        do {
            printf("* Prenom *   ");
            scanf("%s", nouveau->prenom);
        } while (hrouf(nouveau->prenom));


        printf("* Age    *   ");
        scanf("%d", &nouveau->age);



        do {
            printf("* Numero *   ");
            scanf("%s", nouveau->numero);
        } while (!hrouf(nouveau->numero) || strlen(nouveau->numero) > 8);

        printf("\n*******\n\n");
        nouveau->suiv = NULL;

        if (*tete == NULL) {
            *tete = nouveau;
        } else {
            dernier->suiv = nouveau;
        }
        dernier = nouveau;
    }
}





void ajout1(Contact **tete) {
    Contact *nouveau, *dernier = NULL;

    nouveau = (Contact *)malloc(sizeof(Contact));
    if (nouveau == NULL) {
        printf("Erreur d'allocation memoire.\n");
        return;
    }

    do {
        printf("* ID     *   ");
        scanf("%s", nouveau->ID);
    } while (strlen(nouveau->ID) > 7 || !unique(*tete, nouveau->ID));


    do {
        printf("* Nom    *   ");
        scanf("%s", nouveau->nom);
    } while (hrouf(nouveau->nom));

    do {
        printf("* Prenom *   ");
        scanf("%s", nouveau->prenom);
    } while (hrouf(nouveau->prenom));

    printf("* Age    *   ");
    scanf("%d", &nouveau->age);

    do {
        printf("* Numero *   ");
        scanf("%s", nouveau->numero);
   } while (!hrouf(nouveau->numero) || strlen(nouveau->numero) > 8);

    nouveau->suiv = NULL;
    printf("%s Contact ajoute avec succes !\n",GREEN);

    if (*tete == NULL) {
        *tete = nouveau;
    } else {
        dernier = *tete;
        while (dernier->suiv != NULL) {
            dernier = dernier->suiv;
        }
        dernier->suiv = nouveau;
    }
}


Contact* trier(Contact *tete) {
    if (tete == NULL || tete->suiv == NULL) {
        return tete;
    }

    Contact *tri = NULL;

    while (tete != NULL) {
        Contact *courant = tete;
        tete = tete->suiv;

        if (tri == NULL || courant->age < tri->age) {
            courant->suiv = tri;
            tri = courant;
        } else {
            Contact *temp = tri;
            while (temp->suiv != NULL && temp->suiv->age < courant->age) {
                temp = temp->suiv;
            }
            courant->suiv = temp->suiv;
            temp->suiv = courant;
        }
    }
    return tri;
}

void afficher(Contact *tete) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    tete = trier(tete);

    printf(" *--------------------------------------------------------------*\n");
    printf(" * %-10s %-15s %-15s %-10s %-5s *\n", "ID", "NOM", "PRENOM", "AGE", "NUMERO");
    printf(" *--------------------------------------------------------------*\n");

    // Loop through the list and print each contact
    Contact *c = tete;
    while (c != NULL) {
        printf(" * %-10s %-15s %-15s %-10d %-5s  *\n", c->ID, c->nom, c->prenom, c->age, c->numero);
        c = c->suiv;
    }

    printf(" *--------------------------------------------------------------*\n");
}

Contact* recherche(Contact *tete, const char *id) {
    while (tete != NULL) {
        if (strcmp(tete->ID, id) == 0) {
            return tete;
        }
        tete = tete->suiv;
    }
    return NULL;
}

void supprime(Contact **tete, const char *id) {
    Contact *prev = NULL, *current = *tete;

    while (current != NULL && strcmp(current->ID, id) != 0) {
        prev = current;
        current = current->suiv;
    }

    if (current == NULL) {
        printf("%s Contact avec ID %s introuvable.\n", RED , id);
        return;
    }

    if (prev == NULL) {
        *tete = current->suiv;
    } else {
        prev->suiv = current->suiv;
    }

    free(current);
    printf("%s Contact supprimer avec succes.\n",GREEN);
}

void modifier(Contact *tete, const char *id) {
    Contact *temp = tete;

    while (temp != NULL) {
        if (strcmp(temp->ID, id) == 0) {
            printf("%s  \nContact trouve !\n%s",GREEN,RESET);
        do{
            printf("nouveau Nom : ");
            scanf("%s", temp->nom);
        }while(hrouf(temp->nom));

        do{
            printf("nouveau Prenom : ");
            scanf("%s", temp->prenom);
        }while(hrouf(temp->prenom));


            printf("nouveau Age : ");
            scanf("%d", &temp->age);


        do{
            printf("nouveau Numero : ");
            scanf("%s", temp->numero);
        } while (!hrouf(temp->numero) || strlen(temp->numero) > 7);


            printf(" %s  \nContact modifie avec succes !\n%s",GREEN,RESET);
            return;
        }

        temp = temp->suiv;
    }

    printf("%s  \nAucun contact trouve avec l'ID: %s \n%s",RED, id, RESET);
}

void liberer(Contact *tete) {
    Contact *tmp;
    while (tete != NULL) {
        tmp = tete;
        tete = tete->suiv;
        free(tmp);
    }
}
