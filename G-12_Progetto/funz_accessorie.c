/*
 * funz_accezzorie.c
 *
 *  Created on: 20 mag 2020
 *				Author: Giuseppe Monitillo
 *      		Author: Rosa Vicenti
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strutture.h"
#include "funzioni_inserimenti.h"
#include "visualizza.h"
#include "mod_canc.h"
#include "funzionalita.h"
#include "funz_accessorie.h"


FILE* risorse;
FILE* risorse_scaricate;
FILE* creatori;

void puliscinput()
{

	while(getchar()!='\n');

}

void formatta_stringa(char* s)
{

	int i=0;

	for(i=0; i< sizeof(s) ; i++)
	{
		if(i==0){s[i] = toupper(s[i]);

	} else { s[i] = tolower(s[i]);}

	}
}


short int ricerca_max_scaricamenti(risorsa_t risorsa[], int dim)
{

	short int max_scaricamenti = 0;
	short int codice_ris_max = 0;
	int i = 0;

	for(i=0 ; i<dim ; i++)
	{
		if(risorsa[i].conta_scar > max_scaricamenti)
		{
			codice_ris_max = risorsa[i].codice_risorsa;
		}
	}

	return codice_ris_max;
}
//evita che venga inserito un valore che non rientri nel range di valori stabilito
unsigned short int controllo_scelta(unsigned short int min, unsigned short int max)
{
	unsigned short int n_scelta = 0;
	unsigned short  int controllo_scelta = 0;

	do
	{


		fflush(stdin);

		printf(" Valore inserito: ");
		controllo_scelta =  scanf("%hu" , &n_scelta); // restituisce 0 se nessun valore e' stato letto

		if(n_scelta<min || n_scelta>max || controllo_scelta < 1)
		{
			puts(" \n **Errore di inserimento** \n");
			puts(" Reinserire il valore");

		}

	}while(n_scelta<min || n_scelta>max || controllo_scelta < 1);  //cicla finche' l'utente non inserisce un codice valido(secondo quanto stabilito dal menu)

	return n_scelta;
}

int controllo_ins()
{

	short int valore=0;
	int controllo=0;

	do{
		puliscinput();
		printf(" Valore inserito: ");
		controllo = scanf("%hi" , &valore);

		if(controllo < 1 || valore < 0){
			puts(" **Errore di inserimento** \n");
			puts(" Valore inserito: ");
		}
	}while(controllo < 1);

	return valore;
}






void acquisisci_data(data_t *data)
{

	short int flag_data = 0,  //controlla che la data rispetti i vincoli stabiliti
			check_scanf = 0;  //controlla che le scanf vadano come previsto
	do
	{
		printf(" Anno: ");
		fflush(stdin);
		check_scanf = scanf("%hu", &data->anno);
	} while (data->anno < 1980 || data->anno > 2019 || check_scanf < 1); //controlla data minima 1980 e massima 2019

	do
	{
		printf(" Mese: ");
		fflush(stdin);
		check_scanf = scanf("%hu", &data->mese);
	} while (data->mese < 1 || data->mese > 12 //mese compreso tra 1 e 12
			|| check_scanf < 1);

	do
	{
		flag_data = 0;    //controllo dei giorni
		do
		{
			printf(" Giorno: ");
			fflush(stdin);
			check_scanf = scanf("%hu", &data->giorno);
		} while (check_scanf < 1);

		if (data->giorno < 1 || data->giorno > 31)
			flag_data = 1;
		else {
			if (data->mese == 2) {
				if (data->giorno > 28)
					flag_data = 1;
			} else if (data->mese == 4 || data->mese == 6
					|| data->mese == 9
					|| data->mese == 11) {
				if (data->giorno > 30)
					flag_data = 1;
			}
		}
	} while (flag_data == 1);

}



void elimina_new_line_terminale( char *s )
{
	int l = 0;

	if( NULL != s )
	{
		l = strlen(s);

		if( 0!=l && '\n'==s[l-1] )
			s[--l] = '\0';
	}


}
