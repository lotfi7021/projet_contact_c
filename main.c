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

// Function to print the menu with color and centered
void printColoredMenu() {
    // Menu content
    const char *menu[] = {
        "******************************************************",
        "*                                                    *",
        "*                  MENU DE GESTION                   *",
        "*                                                    *",
        "******************************************************",
        "*                                                    *",
        "*   1. Ajouter un nouveau contact                    *",
        "*   2. Afficher la liste des contacts                *",
        "*   3. Chercher un contact par ID                    *",
        "*   4. Supprimer un contact                          *",
        "*   5. Modifier un contact                           *",
        "*   6. Exit                                          *",
        "******************************************************"
    };

  int width = 120;


    for (int i = 0; i < sizeof(menu) / sizeof(menu[0]); i++) {
        int padding = (width - strlen(menu[i])) / 2;


        if (i == 0 || i == 4 || i == 12) {

            printf("%*s%s%s\n", padding, "", GREEN, menu[i], RESET);
        } else if (i == 1 || i == 2 || i == 3 || i == 13) {

            printf("%*s%s%s\n", padding, "", MAGENTA, menu[i], RESET);
        } else if (i >= 5 && i <= 11) {

            printf("%*s%s%s\n", padding, "", CYAN, menu[i], RESET);
        }
    }


    printf("%s CHOISIR UNE OPTION %s", YELLOW , RESET);
}

int main() {
    Contact *tete = NULL;
    int n, i;
    char id[8];


    printf("%s bienvenue dans le gestionnaire de Contact \n\n",GREEN);

    do {
        printf("%s Donner le nombre de contacts (5 Contact au minimum) : ",RESET);
        scanf("%d", &n);
    } while (n < 1);

    // Add contacts
    printf("\nAjout des contacts :\n");
    ajout(&tete, n);

    do {
        printColoredMenu();
        scanf("%d", &i);

        switch (i) {
        case 1:
            ajout1(&tete);
            break;

        case 2:
            printf("%s \nListe des contacts ajoutes : \n %s",BLUE,RESET);
            afficher(tete);
            break;

        case 3:
            printf("Recherche contact par ID :\n");
            printf("Donner ID d'un contact : ");
            scanf("%s", id);

            Contact *T = recherche(tete, id);
            if (T != NULL) {
                printf("\nContact Trouve:\n");
                printf("\nID: %s\n", T->ID);
                printf("NOM: %s\n", T->nom);
                printf("PRENOM: %s\n", T->prenom);
                printf("AGE: %d\n", T->age);
                printf("NUMERO: %s\n", T->numero);
            } else {
                printf("%s\nAucun contact trouve pour l'ID : %s\n", id,RED);
            }
            break;

        case 4:
            printf("%s Supprimer un contact :\n %s ",RED,RESET);
            printf("Donner ID d'un contact : ");
            scanf("%s", id);
            supprime(&tete, id);
            break;

        case 5:
            printf("Modifier un contact :\n ");
            printf("Donner ID d'un contact : ");
            scanf("%s", id);
            modifier(tete, id);
            break;

        default:
            break;
        }
    } while (i != 6);

    liberer(tete);
    return 0;
}
