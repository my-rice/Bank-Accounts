#include <stdio.h>
#include "menu.h"

int menu()
{
    int scelta,i;
    
    printf("-------------------------------------------------\n");
    printf("PROGRAMMA PER LA GESTIONE DI CONTI CORRENTI\n\n");
    printf("1. Inserisci un conto corrente \n");
    printf("2. Prelievo/Versamento\n");
    printf("3. Calcolo prelievi, versamenti e saldo totale\n");
    printf("4. Cerca conto corrente con saldo maggiore\n");
    printf("5. Stampa a video dei conti correnti\n");
    printf("0. EXIT\n\n");
    printf("-------------------------------------------------\n");
    printf("Selezionare la scelta [0-5]: ");
    scanf("%d", &scelta);
    while((scelta<0)||(scelta>5)){
       printf("ERRORE! valore non consentito\n");                        
       printf("Selezionare la scelta [0-5]: ");
       scanf("%d", &scelta);
    }
    return scelta;

   pause();
}

void clear_screen()
{
   //system("CLS");
}

void pause()
{
   //system("pause");
}
