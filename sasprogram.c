#include <stdio.h>
#include <stdlib.h>
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

void addTache(struct todoList taches[], int Ntaches){
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


void printTache(struct todoList taches[], int Ntaches){

 for (int i = 0; i < Ntaches; i++)
    {
        printf("-----tache numero :%d-----\n",i+1);
        printf("Identifiant : %d\n", taches[i].ident);
        printf("titre : %s\n", taches[i].titre);
        printf("description : %s\n", taches[i].description);
        printf("deadline :     year: %d     month: %d     day: %d\n", taches[i].delai.year, taches[i].delai.month, taches[i].delai.day);
        switch(taches[i].sta){
        case 1:
            printf("statut :1- Todo");
            break;
        case 2:
            printf("statut :2- Doing");
            break;
        case 3:
            printf("statut :3- Done");
            break;

        }
        /*printf("statut : %s\n", taches[i].sta);*/
        printf("\n");
    }
}


void modifTache(){}
void suppTache(){}
void searchTache(){}
void statisticTache(){}








int main() {


    printf("               ___  ___ _____ _   _ _   _ \n");
    printf("               |  \\/  ||  ___| \\ | | | | |\n");
    printf("               | .  . || |__ |  \\| | | | |\n");
    printf("               | |\\/| ||  __|| . ` | | | |\n");
    printf("               | |  | || |___| |\\  | |_| |\n");
    printf("               \\_|  |_/\\____/\\_| \\_/\\___/\n");




    struct todoList taches[100];
      int Ntaches = 0;
    int choix;

    while (true) {

        printf("\n1) -----------Ajouter une nouvelle tache----------------");
        printf("\n2) -----------Ajouter plusieurs nouvelles taches--------");
        printf("\n3) -----------Afficher la liste de toutes les taches----");
        printf("\n4) -----------Modifier une tache------------------------");
        printf("\n5) -----------Supprimer une tache par identifiant-------");
        printf("\n6) -----------Rechercher les taches---------------------");
        printf("\n7) -----------Statistiques------------------------------");
        printf("\n\nVEUILLEZ ENTER VOTRE CHOIX :");
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
            printf("3) Afficher la liste de toutes les taches\n");
            printTache(taches,Ntaches);
            break;
        case 4:
            printf("4) Modifier une tache\n");
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


            //system("pause");
    }





    return 0;
}
