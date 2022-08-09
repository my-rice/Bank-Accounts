#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "info.h"

TInfo read_info()
{
   TInfo info;

   info.key = read_key();
   info.satellite = read_satellite();

   return info;
}


int equal(TKey x, TKey y)
{
   if (strcmp(x, y) == 0)
      return 1;
   else
      return 0;
}

int greater(TKey x, TKey y)
{
   if (strcmp(x, y) == 1)
      return 1;
   else
      return 0;
}

void print_info(TInfo x)
{
   print_key(x.key);
   print_satellite(x.satellite);   
   printf("\n");
}

void print_key(TKey k)
{
   printf("%9s  ", k);
}

void print_satellite(TSatellite s)
{
   printf("%c  %16s  %16s  %3d  %3d  %7.2f", s.tipologia, s.cognome, s.nome, s.versamenti, s.prelievi, s.saldo);
}



TSatellite read_satellite()
{
   TSatellite sat;

   int saldo;

   do{
   printf ("Inserisci la tipologia del conto corrente [A/B/C] ");
   scanf ("\n%c", &sat.tipologia);
   } while (sat.tipologia != 'A' && sat.tipologia != 'B' && sat.tipologia != 'C');

   printf ("Inserisci il cognome del titolare del conto ");
   scanf ("%s", sat.cognome);

   printf ("Inserisci il nome del titolare del conto ");
   scanf ("%s", sat.nome);

   sat.versamenti = 1;

   sat.prelievi = 0;

   do{
   printf ("Inserisci il saldo iniziale [> 0] ");
   scanf ("%f", &sat.saldo);
   }while (sat.saldo <=0);
   
   return sat;
}


TKey read_key()
{
   TKey key;
   char tmp[MAXKEY];

   do
   {
   printf ("Inserisci il codice del conto corrente (8 caratteri): ");
   scanf ("%s", tmp);
   } while (strlen (tmp)!=MAXKEY-1);

   key = (TKey)malloc(MAXKEY*sizeof(TKey));
   strcpy (key, tmp);

   return key;

}

