#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>  /* for while loop */
int Ntaches;
int nbrTaches;

struct deadline
{
    int year;
    int month;
    int day;
};
struct todoList
{
    int ident;
    char titre[20];
    char description[500];
    struct deadline delai;
    int sta;
};
    struct todoList taches[100];
      int Ntaches = 0;

void addTache(){
    struct todoList nvtache;
    nvtache.ident = Ntaches + 1;


    printf("definer votre tache :\n");
    printf("Identifiant : %d\n", nvtache.ident);
    printf("Titre :");
    scanf(" %[^\n]s",&nvtache.titre);
    printf("description :");
    scanf(" %[^\n]s",&nvtache.description);



    printf("deadline :\n");
    printf("year :");
    scanf("%d",&nvtache.delai.year);
    printf("month :");
    scanf("%d",&nvtache.delai.month);
    printf("day :");
    scanf("%d",&nvtache.delai.day);
    printf("1- Todo     2-Doing     3-Done");
    printf("\nstatus :");
    scanf(" %d",&nvtache.sta);

    taches[Ntaches] = nvtache;

}


void printTache(){


 for (int i = 0; i < Ntaches; i++)
    {
        printf("-----TACHE NUMERO :%d-----\n",i+1);
        printf("| Identifiant : %d\n", taches[i].ident);
        printf("| titre : %s\n", taches[i].titre);
        printf("| description : %s\n", taches[i].description);
        printf("| deadline :     year: %d     month: %d     day: %d\n", taches[i].delai.year, taches[i].delai.month, taches[i].delai.day);
        switch(taches[i].sta){
        case 1:
            printf("| statut :1- Todo\n");
            break;
        case 2:
            printf("| statut :2- Doing\n");
            break;
        case 3:
            printf("| statut :3- Done\n");
            break;
        default:
            printf("| statut :non trouver\n");
            break;

        }
        /*printf("statut : %s\n", taches[i].sta);*/
        printf("-----TACHE NUMERO :%d-----\n",i+1);
        printf("\n\n");

    }

}

// Fonction pour trier les tâches par titre (tri à bulles)
void triparAlpha() {
    struct todoList tittri;
    for (int i = 0; i < Ntaches - 1; i++) {
        for (int j = 0; j < Ntaches - i - 1; j++) {
            if (strcmp(taches[j].titre, taches[j + 1].titre) > 0) {
                tittri = taches[j];
                taches[j] = taches[j + 1];
                taches[j + 1] = tittri;
            }
        }
    }
    printf("Tâches triées par titre.\n");
}





void modifTache() {
    int identmodif;
    printf("Entrer l'identifiant de la tache que vous voulez modifier :");
    scanf("%d", &identmodif);

    // Search for the task with the specified identifier

for (int i = 0; i < Ntaches; i++){
    if ((taches[i].ident == identmodif)) {
        int achnbdl;
        printf("Qu'est-ce que vous voulez modifier :\n");
        printf("1 - La description\n");
        printf("2 - Le statut\n");
        printf("3 - Le deadline\n");
        printf("Votre choix : ");
        scanf("%d", &achnbdl);

        switch (achnbdl) {
            case 1:
                printf("Modifier la description : ");
                scanf(" %[^\n]s", taches[i].description);
                break;
            case 2:
                printf("Modifier le statut (1- Todo, 2- Doing, 3- Done) : ");
                scanf("%d", &taches[i].sta);
                break;
            case 3:
                printf("Modifier le deadline :\n");

                printf("year :");
                scanf("%d",&taches[i].delai.year);
                printf("month :");
                scanf("%d",&taches[i].delai.month);
                printf("day :");
                scanf("%d",&taches[i].delai.day);
            default:
                printf("Choix non trouver\n");
                break;
        }
    } else {
        printf("tache avec lidentifiant %d non trouver.\n", identmodif);
    }
}
 }



void suppTache(){
    int identsupp;
    printf("Entrer l'identifiant de la tache que vous voulez supprimer :");
    scanf("%d", &identsupp);
    for (int i = 0; i < Ntaches; i++){
    if ((taches[i].ident == identsupp)){


    }

}
void searchTache(){}
void statisticTache(){}








int main() {


    printf("               ___  ___ _____ _   _ _   _ \n");
    printf("               |  \\/  ||  ___| \\ | | | | |\n");
    printf("               | .  . || |__ |  \\| | | | |\n");
    printf("               | |\\/| ||  __|| . ` | | | |\n");
    printf("               | |  | || |___| |\\  | |_| |\n");
    printf("               \\_|  |_/\\____/\\_| \\_/\\___/\n");





    int choix;

    while (true) {

        printf("\n                     1) -----------Ajouter une nouvelle tache----------------");
        printf("\n                     2) -----------Ajouter plusieurs nouvelles taches--------");
        printf("\n                     3) -----------Afficher la liste de toutes les taches----");
        printf("\n                     4) -----------Modifier une tache------------------------");
        printf("\n                     5) -----------Supprimer une tache par identifiant-------");
        printf("\n                     6) -----------Rechercher les taches---------------------");
        printf("\n                     7) -----------Statistiques------------------------------");
        printf("\n\n           VEUILLEZ ENTER VOTRE CHOIX :");
        scanf("%d",&choix);

        switch(choix){

        case 1:
            addTache(taches,Ntaches);
            Ntaches++;
            break;
        case 2:

            printf("\nentrer le nombre des taches que vous desirez: ");
            scanf("%d", &nbrTaches);

            for (int i = 1; i <= nbrTaches; i++)
            {
                printf("-----tache numero :%d-----\n",i);
                addTache(taches, Ntaches);
                Ntaches++;
            }
            break;
        case 3:
            printf("3) Afficher la liste de toutes les taches :\n\n");
            triparAlpha(taches, Ntaches);
            printTache(taches,Ntaches);
            break;
        case 4:
            printf("4) Modifier une tache\n");
            modifTache();
            break;
        case 5:
            printf("5) Supprimer une tache par identifiant\n");
            break;
        case 6:
            printf("6) -echercher les taches\n");
            break;
        case 7:
            printf("7) tatistiques\n");
            break;
        default:
            printf("vous avez entrer la fause command\n");
            }


            system("pause");
    }





    return 0;
}
