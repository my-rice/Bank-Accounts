#ifndef GESTIONE_STUDENTI_H
#define GESTIONE_STUDENTI_H

#include "hash.h"

/*La funzione legge il dato TInfo e inserisce un nuovo nodo nella tabella hash.
  La funzione restituisce 1 se l'inserimento va a buon fine, -1 altrimenti. (La funzione viene già fornita)*/
int inserisci_cc (THash conticorrenti);

/*La funzione legge il codice del conto corrente e l'operazione da effettuare.
  Successivamente cerca il conto corrente e se lo trova legge l'importo dell'operazione.
  Se l'operazione è di prelievo il saldo viene decrementato dell'importo inserito
  ed il  numero di prelievi viene incrementato di 1; se l'operazione è di versamento
  il saldo viene incrementato dell'importo inserito ed il numero di versamenti
  viene incrementato di 1. Per l'operazione di prelievo bisogna verificare le
  condizioni sulla tipologia, se il saldo non consente il prelievo l'operazione
  non viene effettuata. La funzione restituisce 2 se l'operazione di versamento
  va a buon fine, 1 se l'operazione di prelievo va a buon fine, 0 se l'operazione
  il saldo non è sufficiente per effettuare l'operazione, -1 se il conto corrente
  non viene trovato.*/
int prelievo_versamento_cc (THash conticorrenti);

/*La funzione calcola la somma dei saldi di tutti i conti correnti, la somma di tutte
  le operazioni di prelievo e di tutte le operazioni di versamento. Alla fine stampa
  i tre valori calcolati. La funzione non restituisce alcun valore.*/
void calcola_valori(THash conticorrenti);

/*La funzione cerca all'interno della tabella hash il conto con saldo maggiore
  e ne stampa le informazioni. Per la ricerca viene usata la funzione ausiliaria
  TNode* cerca(TList list).*/
void cerca_ricco (THash conticorrenti);

/*La funzione cerca cerca all'interno di una lista il conto con saldo maggiore.
 (La funzione deve essere ricorsiva)*/
TNode* cerca(TList list);

/*La funzione stampa, le informazioni di tutti i conti correnti in archivio.
  La funzione non restituisce alcun valore.(La funzione viene già fornita)*/
void stampa_cc (THash conticorrenti);

#endif
