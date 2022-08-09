#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestione_cc.h"

#define SIZE 4

/*La funzione legge il dato TInfo e inserisce un nuovo nodo nella tabella hash.
  La funzione restituisce 1 se l'inserimento va a buon fine, -1 altrimenti. (La funzione viene gi� fornita)*/
int inserisci_cc (THash conticorrenti)
{
   TInfo info;
   TNode *node;

   info = read_info();
   node = chained_hash_search(conticorrenti, info.key);
   if (node != NULL)
      return -1;

   chained_hash_insert(conticorrenti, info);
   return 1;
}

/*La funzione legge il codice del conto corrente e l'operazione da effettuare.
  Successivamente cerca il conto corrente e se lo trova legge l'importo dell'operazione.
  Se l'operazione � di prelievo il saldo viene decrementato dell'importo inserito
  ed il  numero di prelievi viene incrementato di 1; se l'operazione � di versamento
  il saldo viene incrementato dell'importo inserito ed il numero di versamenti
  viene incrementato di 1. Per l'operazione di prelievo bisogna verificare le
  condizioni sulla tipologia, se il saldo non consente il prelievo l'operazione
  non viene effettuata. La funzione restituisce 2 se l'operazione di versamento
  va a buon fine, 1 se l'operazione di prelievo va a buon fine, 0 se l'operazione
  il saldo non � sufficiente per effettuare l'operazione, -1 se il conto corrente
  non viene trovato.*/
int prelievo_versamento_cc (THash conticorrenti)
{
    TKey conto;
    conto = read_key();
    float importo,prelievo;
    char *operazione;
    
    TNode* m = chained_hash_search(conticorrenti, conto);
    if(m == NULL){
        return -1;
    }
    
    while(1){
        printf("Inserisci operazione PRELIEVO/VERSAMENTO: \n");
        scanf("%s",operazione);
        if(strcmp(operazione,"VERSAMENTO")==0){
            printf("Inserisci l'importo da versare: \n");
            scanf("%f",&importo);
            printf("\n%f\n",importo);
            m->info.satellite.saldo += importo;
            m->info.satellite.prelievi +=1;
            return 2;
        }
        else if(strcmp(operazione,"PRELIEVO")==0){
            printf("Inserisci l'importo da prelevare: \n");
            scanf("%f",&prelievo);
            printf("\n%f\n",prelievo);
            if(m->info.satellite.tipologia == 'A' && (m->info.satellite.saldo-prelievo) >=-2000){
                m->info.satellite.prelievi +=1;
                m->info.satellite.saldo -= prelievo;
                return 1;
            }
            else if(m->info.satellite.tipologia == 'B' && (m->info.satellite.saldo-prelievo) >=-1500){
                m->info.satellite.prelievi +=1;
                m->info.satellite.saldo -= prelievo;                
                return 1;
            }
            else if(m->info.satellite.tipologia == 'C' && (m->info.satellite.saldo-prelievo) >=-1000){
                m->info.satellite.prelievi +=1;
                m->info.satellite.saldo -= prelievo;                
                return 1;
            }else
                return 0;
        }
        else
           printf("Errore\n");
    }
    
}

/*La funzione calcola la somma dei saldi di tutti i conti correnti, la somma di tutte
  le operazioni di prelievo e di tutte le operazioni di versamento. Alla fine stampa
  i tre valori calcolati. La funzione non restituisce alcun valore.*/
void calcola_valori(THash conticorrenti)
{
    float saldi=0;
    int prelievi=0,versamenti=0;
    for(int i=0;i<conticorrenti.size;i++){
        for(TNode* m = conticorrenti.bucket[i];m!=NULL;m = m->link){
            saldi += m->info.satellite.saldo;
            prelievi += m->info.satellite.prelievi;
            versamenti += m->info.satellite.versamenti;
        }
    }
    printf("Somma dei saldi: %f\nsomma di tutte le operazioni di prelievo %d\n somma di tutte le operazioni di versamento%d",saldi,prelievi,versamenti);
}

/*La funzione cerca all'interno della tabella hash il conto con saldo maggiore
  e ne stampa le informazioni. Per la ricerca viene usata la funzione ausiliaria
  TNode* cerca(TList list).*/
void cerca_ricco (THash conticorrenti)
{
    
    TNode* m;
    if(chained_hash_empty(conticorrenti)){
        printf("hash vuoto\n");
        return;
    }
    
    float max = -2000;
    for(int i=0;i<conticorrenti.size;i++){
        m = cerca(conticorrenti.bucket[i]);
        if(m != NULL && m->info.satellite.saldo > max){
            max = m->info.satellite.saldo;
        }
    }
    printf("Conto Max: %.3f\n",max);
}

/*La funzione cerca cerca all'interno di una lista il conto con saldo maggiore.
 (La funzione deve essere ricorsiva)*/
TNode* cerca(TList list)
{
    if(list == NULL){
        return NULL;
    }
    TNode* m = cerca(list->link);
    if(m == NULL && list  == NULL){
        return NULL;
    }else if(m == NULL){
        return list;
    }else if(list == NULL){
        return m;
    }else if(list->info.satellite.saldo > m->info.satellite.saldo){
        return list;
    }else
        return m;
}

/*La funzione stampa, le informazioni di tutti i conti correnti in archivio.
  La funzione non restituisce alcun valore.(La funzione viene gi� fornita)*/
void stampa_cc (THash conticorrenti)
{
  printf ("I conti correnti della banca sono: \n");
  chained_hash_print(conticorrenti);
}

