/*
 * visualizza.c
 *
 *  Created on: 8 mag 2020
 *       Author: Giuseppe Monitillo
 *       Author: Rosa Vicenti
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "strutture.h"
#include "funzioni_inserimenti.h"
#include "menu.h"
#include "mod_canc.h"
#include "funzionalita.h"
#include "funz_accessorie.h"


void stampa_disciplina (unsigned short int disciplina)
{
	switch (disciplina){

	case (1): printf("Matematica"); break;
	case (2): printf("Storia    "); break;
	case (3): printf("Italiano  "); break;
	case (4): printf("Inglese   "); break;
	case (5): printf("Fisica    "); break;

	}

}


void stampa_livello_ed (unsigned short int livello_ed)
{
	switch (livello_ed)
	{

	case (1): printf("  Scuola Primaria         "); break;
	case (2): printf("  Scuola Sec. di 1 grado  "); break;
	case (3): printf("  Scuola Sec. di 2 grado  "); break;
	case (4): printf("  Istruzione Universitaria"); break;
	}

}

void stampa_tipologia(unsigned short int tipologia)
{
	switch (tipologia)
	{

	case (1): printf(" Testuale");
	break;

	case (2): printf(" Video lezione");
	break;

	case (3): printf(" Gioco didattico");
	break;
	}

}

//select è necessario al fine di far stampare o meno la pausa
void stampa_utilizzatori(int select)
{

	FILE *utilizzatori;
	utilizzatore_t utilizzatore; 	// struct per scorrere il file

	utilizzatori = fopen("F_UTILIZZATORI.csv" , "rb+");


	if(utilizzatori == NULL){
		puts(" **Errore nell'apertura del file**");
	}else{
		puts("\n");
		puts("___________________________________________________UTILIZZATORI________________________________________________________\n");
		printf (" %-10s %-12s %-8s  %-6s %-12s %-10s \n" , "CODICE" ," NOME",  "COGNOME" ,"ETA" ," DISCIPLINA", "LIVELLO EDUCATIVO");

		fread(&utilizzatore,sizeof(utilizzatore_t),1,utilizzatori);

		while(!feof(utilizzatori))
		{

			printf("\n %-10hi  %-10s  %-10s %-5d  ",utilizzatore.codice_utilizzatore,
													utilizzatore.nome_utilizzatore,
													utilizzatore.cognome_utilizzatore,
													utilizzatore.eta_utilizzatore);

			stampa_disciplina (utilizzatore.disciplina_utilizzatore);
			stampa_livello_ed (utilizzatore.livello_ed_utilizzatore);

			puts("\n");
			fread(&utilizzatore,sizeof(utilizzatore_t),1,utilizzatori);
		}
		printf("_______________________________________________________________________________________________________________________\n");
	}
	fclose(utilizzatori);

	if(select == 0)
	{
		puts("\n");
		puts(" Operazione andata a buon fine");
		system(" PAUSE");
	}else{
		puts("\n");
	}
}

void stampa_risorse(int select)
{
	FILE *risorse;
	risorsa_t risorsa;

	risorse = fopen("F_RISORSE.csv" , "rb+");

	if(risorse == NULL){
		puts(" **Errore nell'apertura del file**");
	}else{
		puts("\n");
		puts("___________________________________________________RISORSE____________________________________________________________\n");
		printf (" CODICE   TITOLO               PAROLA CHIAVE    DISCIPLINA  LIVELLO EDUCATIVO        TIPOLOGIA");
		puts("\n");

		fread(&risorsa , sizeof(risorsa_t) , 1 , risorse);

		while(!feof(risorse)){

				if(risorsa.codice_risorsa != 0)
				{
				printf("\n %-7hi  %-20s %-15s  ",  risorsa.codice_risorsa ,
												   risorsa.titolo,
												   risorsa.parola_chiave  );

				stampa_disciplina(risorsa.disciplina);
				stampa_livello_ed(risorsa.livello_ed_risorsa);
				stampa_tipologia(risorsa.tipologia);
				puts("\n");
			}

			fread(&risorsa , sizeof(risorsa_t) , 1 , risorse);

		}
		printf("_______________________________________________________________________________________________________________________\n");
	}
	fclose(risorse);



	if(select == 0){
		puts("\n");
		puts(" Operazione andata a buon fine");
		system(" PAUSE");
	}else{
		puts("\n");
	}
}


void stampa_creatori(int select)
{
	FILE *creatori;
	creatore_t creatore;

	creatori = fopen("F_CREATORI.csv" , "rb+");

	if(creatori == NULL){
		puts(" **Errore nell'apertura del file**");
	}else{
		puts("\n");
		puts("___________________________________________________CREATORI________________________________________________________\n");
		printf (" %-10s %-10s %-10s  %-5s %-12s %-10s \n" , "CODICE" ," NOME",  "COGNOME" ,"ETA" ," DISCIPLINA", "LIVELLO EDUCATIVO");



		fread(&creatore,sizeof(creatore_t),1,creatori);

		while(!feof(creatori)){
			if (creatore.codice_creatore!=0)

			{ printf("\n %-10d  %-10s  %-10s %-5d  ",   creatore.codice_creatore,
														creatore.nome_creatore,
														creatore.cognome_creatore,
														creatore.eta_creatore);

			stampa_disciplina (creatore.disciplina_creatore);
			stampa_livello_ed (creatore.livello_ed_creatore);

			puts("\n");}
			fread(&creatore,sizeof(creatore_t),1,creatori);
		}
		printf("_______________________________________________________________________________________________________________________\n");
	}
	fclose(creatori);



	if(select == 0)
	{
		puts("\n");
		puts(" Operazione andata a buon fine");
		system(" PAUSE");
	}else{
		puts("\n");
	}
}
