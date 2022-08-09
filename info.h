#ifndef INFO_H
#define INFO_H

#define MAXKEY 9
#define MAXCAR 16
#define MINA -2000
#define MINB -1500
#define MINC -1000


/*Definizione della chiave*/
typedef char *TKey;

/*Definizione della struttura per l'informazione satellite*/
struct SSatellite{
   char tipologia;
   char cognome[MAXCAR];
   char nome[MAXCAR];
   int versamenti;
   int prelievi;
   float saldo;
};

/*Definizione del tipo per l'informazione satellite*/
typedef struct SSatellite TSatellite;

/*Definzione della struttura per l'informazione*/
struct SInfo {
  TKey key;
  TSatellite satellite;
};

/*Definizione del tipo per l'informazione*/
typedef struct SInfo TInfo;

/*Legge da tastiera i dati dell'info. Restituisce l'info letta*/
TInfo read_info();

/*Legge da tastiera i dati dell'informazione satellite. Restituisce 
  l'informazione satellite letta*/
TSatellite read_satellite();

/*Legge da tastiera la chiave. Restituisce la chiave letta*/
TKey read_key();

/*Stampa l'informazione*/
void print_info(TInfo x);

/*Stampa la chiave */
void print_key(TKey k);

/*Stampa l'informazione satellite*/
void print_satellite(TSatellite s);

/*Confronta la chiave x con quella y. Restituisce 1 se x = y, 0 altrimenti*/
int equal(TKey x, TKey y);

/*Confronta la chiave x con quella y. Restituisce 1 se x > y, 0 altrimenti*/
int greater(TKey x, TKey y);

#endif
