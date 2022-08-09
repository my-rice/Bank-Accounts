#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "info.h"
#include "bool.h"
#include "menu.h"
#include "gestione_cc.h"

#define SIZE 4
/*
 Si scriva un programma per la gestione dei conti correnti di una banca. I conti correnti possono essere di 3 tipologie diverse:
•	Tipologia A: è possibile avere un saldo negativo fino a -2000 euro
•	Tipologia B: è possibile avere un saldo negativo fino a -1500 euro
•	Tipologia C: è possibile avere un saldo negativo fino a -1000 euro
I dati relativi ad ogni conto corrente sono:
•	Codice conto corrente (Una stringa di 8 caratteri), campo chiave
•	Topologia conto corrente (Un carattere [A / B / C])
•	Cognome del titolare del conto (Una stringa di 15 caratteri)
•	Nome del titolare del conto (Una stringa di 15 caratteri)
•	Numero di operazioni di versamento (Un intero)
•	Numero di operazioni di prelievo (Un intero)
•	Saldo (Un reale)

Il programma memorizza i dati relativi ai conti correnti in una tabella hash con liste di collisione e con un bucket di dimensione 4. La funzione di hash somma i codici ascii dei caratteri della chiave e ne calcola il resto della divisione intera per 4. Il programma realizza le seguenti funzionalità:

•	Inserimento di un nuovo conto corrente. (Funzionalità già fornita)
•	Prelievo o versamento per un conto corrente.
•	Calcolo del numero totale di operazioni di versamento, di prelievo e della somma dei saldi per tutti i conti correnti.
•	Ricerca del conto corrente con saldo maggiore.
•	Stampa a video dei conti correnti. (Funzionalità già fornita)

Lo studente per la realizzazione dell’applicazione ha a disposizione:
•	I file necessari alla creazione dell’intero progetto;
•	Le funzioni standard per la gestione della tabella hash che devono essere usate senza apportare loro alcuna modifica (né ai prototipi né alla loro implementazione fornita);
•	La definizione dei prototipi delle funzioni che devono essere implementate. 

I file forniti sono i seguenti:
•	info.h (da non modificare)
o	Contiene la definizione del tipo TInfo ed i prototipi delle funzioni per la sua gestione.
•	info.c (da non modificare)
o	Contiene l’implementazione delle funzioni per la gestione di TInfo.
•	list.h (da non modificare)
o	Contiene la definizione del tipo TList ed i prototipi delle funzioni per la gestione di TList (funzioni standard) 
•	list.c (da non modificare)
o	Contiene l’implementazione delle funzioni per la gestione di TList (funzioni standard)
•	hash.h (da non modificare)
o	Contiene la definizione del tipo THash ed i prototipi delle funzioni per la gestione di THash (funzioni standard)
•	hash.c (da completare)
o	Contiene l’implementazione delle funzioni per la gestione di THash (funzioni standard). Lo studente dovrà implementare la funzione int f_hash(TKey key);
•	menu.h (da non modificare)
o	Contiene i prototipi delle funzioni di interfaccia utente.
•	menu.c (da non modificare)
o	Contiene l’implementazione delle funzioni di interfaccia utente.
•	gestione_cc.h (da non modificare)
o	Contiene i prototipi delle funzioni richieste dall’applicazione:
	int inserisci_cc(THash conticorrenti);
•	La funzione legge il dato TInfo e inserisce un nuovo nodo nella tabella hash.  La funzione restituisce 1 se l'inserimento va a buon fine, -1 altrimenti. (La funzione viene già fornita)
	int prelievo_versamento_cc (THash conticorrenti);
•	La funzione legge il codice del conto corrente e l’operazione da effettuare. Successivamente cerca il conto corrente e se lo trova legge l’importo dell’operazione. Se l’operazione è di prelievo il saldo viene decrementato dell’importo inserito ed il  numero di prelievi viene incrementato di 1; se l’operazione è di versamento il saldo viene incrementato dell’importo inserito ed il numero di versamenti  viene incrementato di 1. Per l’operazione di prelievo bisogna verificare le condizioni sulla tipologia, se il saldo non consente il prelievo l’operazione non viene effettuata. La funzione restituisce 2 se l’operazione di versamento va a buon fine, 1 se l’operazione di prelievo va a buon fine, 0 se l’operazione il saldo non è sufficiente per effettuare l’operazione, -1 se il conto corrente non viene trovato.
	void calcola_valori(THash conticorrenti);
•	La funzione calcola la somma dei saldi di tutti i conti correnti, la somma di tutte le operazioni di prelievo e di tutte le operazioni di versamento. Alla fine stampa i tre valori calcolati. La funzione non restituisce alcun valore.
	void cerca_ricco (THash conticorrenti);
•	La funzione cerca all’interno della tabella hash il conto con saldo maggiore e ne stampa le informazioni. Per la ricerca viene usata la funzione ausiliaria TNode* cerca(TList list).
	TNode* cerca(TList list);
•	La funzione cerca cerca all’interno di una lista il conto con saldo maggiore. (La funzione deve essere ricorsiva)
	void stampa_cc (THash conticorrenti);
•	La funzione stampa, le informazioni di tutti i conti correnti in archivio. La funzione non restituisce alcun valore. (La funzione viene già fornita)
•	gestione_cc.c (da completare) 
o	Contiene l’implementazione delle funzioni richieste dall’applicazione
•	conti_correnti.c (da completare)
o	Contiene il main del programma.
 
 
 */



/*
•	Inserimento di un nuovo conto corrente. (Funzionalità già fornita)
•	Prelievo o versamento per un conto corrente.
•	Calcolo del numero totale di operazioni di versamento, di prelievo e della somma dei saldi per tutti i conti correnti.
•	Ricerca del conto corrente con saldo maggiore.
•	Stampa a video dei conti correnti. (Funzionalità già fornita)

 
 */
int main()
{
    int scelta,a,ret,c, inserimento, operazione;
    THash conti;

    /* Inizializzo le liste */
    conti = chained_hash_create(SIZE);
    

    /* Scelta della funzione per gestire l'archivio */
    
     scelta= 1;

/*
      while(scelta!=0){
          scelta = menu();
          if(scelta == 1){
              if(inserisci_cc (conti) == -1){
                printf("Errore\n");
              }else
                printf("Conto inserito correttamente\n");
          }
          if(scelta == 2){
            a = prelievo_versamento_cc(conti);
            if(a==-1){
                printf("Conto non trovato\n");
            }else if(a == 0){
                printf("Il saldo non è sufficiente per effettuare l'operazione\n");
            }else if(a == 1){
                printf("operazione di prelievo va a buon fine\n");
            }else
                printf("operazione di versamento va a buon fine\n");
          }
          if(scelta == 3){
              calcola_valori(conti);
          }
          if(scelta == 4){
            cerca_ricco (conti);
          }
          if(scelta == 5){
              stampa_cc (conti);
          }
*/
        while(scelta=menu()){
        switch(scelta){
            case 1:
                c = inserisci_cc (conti); 
                if(c == 1)
                    printf("Contocorrente inserito correttamente\n");
                else
                    printf("ERRORE!");
                break;
            case 2:
                ret = prelievo_versamento_cc(conti);
                if(ret == 2)
                    printf("L'operazione di versamento e\' andata a buon fine\n");
                else if(ret == 1)
                    printf("L'operazione di prelievo e\' andata a buon fine\n");
                else if(ret == 0)
                    printf("Saldo non sufficiente\n");
                else if(ret == -1)
                    printf("Conto non trovato\n");
                break;
            case 3:
                calcola_valori(conti);
                break;
            case 4:
                cerca_ricco(conti);
                break;
            case 5:
                stampa_cc(conti);
                break;
        }
    }
}
