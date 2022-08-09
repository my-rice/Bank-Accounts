#include <stdio.h>
#include <stdlib.h>

#include "info.h"
#include "list.h"
#include "list.h"

TList list_create()
{
  return NULL;
}

TList list_destroy(TList list){
  TList curr, succ;
  curr = list;
  while(curr!=NULL) 
  {
    succ=curr->link;
    free(curr);
    curr=succ;
  }
  return NULL;
}

void list_print(TList list)
{
  TList curr;
  curr=list;
  while(curr!=NULL){
    print_info(curr->info);
    curr=curr->link;
  }
}

TNode* list_search(TList list, TKey key){

  TList curr;
  curr=list;
  while((curr!=NULL) && greater(key, curr->info.key))
  {
    curr=curr->link;
  }

  /* Analisi delle post - condizioni
  C1: valore da cercare piu� 
    piccolo della Testa : 		  	curr != NULL
  C2: valore da cercare maggiore 
    della Coda : 			   	curr != NULL
  C3: valore da cercare compreso tra 
    quello di Testa e quello di Coda :  	curr->info>=info
  */
  if ((curr!=NULL) && equal(curr->info.key, key))
  /* Elemento trovato */
    return curr;
  else
   return NULL;
}

/* Inserisce l�elemento di valore info nella lista list, preservandone l�ordinamento; restituisce la lista risultante.
* PRE: list e� ordinata
* NOTA: consuma il parametro list; inoltre se l� elemento da inserire e� gia� presente, esso viene duplicato .
*/
TList list_insert(TList list, TInfo info){
  TList prec, curr, new_node;
  prec=NULL;
  curr=list;
  /* F1: ricerca della posizione di inserimento */
  while  ((curr!=NULL) && greater(info.key, curr->info.key)){
    prec=curr;
    curr=curr->link;
  }
  /* F2: allocazione del nuovo nodo */
  new_node=(TNode *) malloc (sizeof(TNode));
  if (new_node==NULL)
  {
    printf("Non e� possibile allocare l�elemento\n");
    exit(1);
  }
  new_node->info=info;
  /* F3: aggiornamento della catena dei collegamenti */
  if (prec==NULL)
  {
    /* C1: inserimento in Testa */
    new_node->link=list;
    list=new_node;
    return list;
  }
  else {
    /* C2: inserimento in posizione centrale o in coda */
    prec->link=new_node; 
    new_node->link=curr;
    return list;
  }
}

/* Cancella un elemento di valore info dalla lista list, preservandone l�ordinamento; restituisce la lista risultante .
* PRE: list e� ordinata
* NOTA: consuma il parametro list; inoltre se l�elemento da inserire e� duplicato cancella la prima occorrenza .
*/
TList list_delete(TList list, TKey key){
  TList prec, curr;
  prec=NULL;
  curr=list;
  /* F1: ricerca dell� elemento da cancellare */
  while ((curr!=NULL) && greater(key, curr->info.key)){
    prec=curr;
    curr=curr->link;
  }
  /* Analisi delle post - condizioni */
  if ((curr!=NULL) && equal(curr->info.key, key)){
   /* Elemento trovato */
   /* F2: aggiornamento della catena dei collegamenti */
   if (prec==NULL){
     /* Cancellazione dell�elemento di Testa */
      list=curr->link;
   }
   else{
     /* Cancellazione dell�elemento all�interno della lista */
      prec->link=curr->link;
   }
   /* F3: Deallocazione del Nodo cancellato logicamente */
   free (curr);
  }
  return list;
}

TList list_min(TList list) {
  TList curr, min;
  curr = list;
  min = curr;
  while (curr!=NULL){
    if (greater(min->info.key, curr->info.key)) {
      min = curr;
    }
    curr = curr->link;
  }
  return min;
}

int list_count_nodes(TList list) {
  TList curr;
  int n = 0;
  curr = list;
  while (curr!=NULL){
    n = n + 1;
    curr = curr->link;
  }
  return n;
}



TList list_reverse(TList list) {
  TList curr,prec,succ;
  curr = list;
  prec = NULL ;
  while (curr!=NULL){
    succ = curr->link;
    curr->link = prec;
    prec = curr;
    curr = succ;
  }
  return prec;
}

TList list_copy(TList list) {
  TList curr, l2, succ;
  curr = list;
  succ = NULL;
  while (curr!=NULL){
    TList tmp = (TNode *) malloc(sizeof(TNode));
    tmp->info = curr->info;
    tmp->link = NULL;
    if (succ == NULL){
       l2 = tmp;
       succ = tmp;
    }
    else {
       succ->link = tmp;
       succ = tmp; 
    }   
    curr = curr->link;
  }
  return l2;
}

TList list_merge(TList list1, TList list2) {
  TList curr1, curr2, lf;
  curr1 = list1;
  curr2 = list2;
  lf = NULL;
  while (curr1!=NULL && curr2!=NULL){
    if(greater(curr1->info.key,curr2->info.key)){
       lf = list_insert(lf, curr2->info);
       curr2 = curr2->link;
    }
    else {
       lf = list_insert(lf, curr1->info);
       curr1 = curr1->link; 
    }
  }
  if(curr1==NULL){
    while(curr2!=NULL){
      lf = list_insert(lf, curr2->info);
      curr2 = curr2->link;
    }
  }
  else {
    while(curr1!=NULL){
      lf = list_insert(lf, curr1->info);
      curr1 = curr1->link;
    }
  }
 return lf;
}



