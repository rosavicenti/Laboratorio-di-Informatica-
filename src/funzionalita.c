/*
 * funzionalita.c
 *
 *  Created on: 12 mag 2020
 *       Author: Giuseppe Monitillo
 *     	 Author: Rosa Vicenti
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutture.h"
#include "funzioni_inserimenti.h"
#include "menu.h"
#include "visualizza.h"
#include "mod_canc.h"
#include <malloc.h>
#include "ordinamenti.h"
#include "funz_accessorie.h"
#include "funzionalita.h"

#define VALORE_MIN_MATCHING 3		// valore min della sottostringa per la ricerca del suggerimento di una risorsa

float media(short int numero_elementi, float somma)
{

	float media = 0;

	media = somma / numero_elementi;
	media = media * 100;

	return media;
}

void medie_valutazioni(creatore_t creatore)
{

	FILE *creatori = NULL;
	FILE *risorse_scaricate = NULL;
	FILE *risorse = NULL;

	risorsa_t risorsa;
	risorsa_scaricata_t ris_scar;

	short int conta_valutazioni = 0, somma_valutazioni = 0;
	float media_valutazioni = 0;

	creatori = fopen("F_CREATORI.csv", "rb+");
	risorse = fopen("F_RISORSE.csv", "rb+");
	risorse_scaricate = fopen("F_SCARICAMENTI.csv", "rb+");
	if (creatori == NULL || risorse_scaricate == NULL
			|| risorse_scaricate == NULL) {
		puts(" **Errore nell'apertura dei file**");

	} else {

		fseek(creatori, (creatore.codice_creatore - 1) * sizeof(creatore_t),
				SEEK_SET);
		fread(&creatore, sizeof(creatore_t), 1, creatori);

		if (!feof(creatori) && creatore.codice_creatore != 0) {

			puts(
					"________________________________________________________________________________________");
			puts("\t\t \t ANALISI RISORSE REALIZZATE ");

			printf(
					" \n CODICE RISORSA    TITOLO               NUMERO DI SCARICAMENTI  VALUTAZIONE MEDIA RISORSA");

			fseek(risorse, 0, SEEK_SET);
			while (!feof(risorse)) {
				fread(&risorsa, sizeof(risorsa_t), 1, risorse);
				if (risorsa.codice_creatore == creatore.codice_creatore)
				{

					conta_valutazioni = 0, somma_valutazioni = 0;
					media_valutazioni = 0;

					fseek(risorse_scaricate, 0, SEEK_SET);
					while (!feof(risorse_scaricate)) {
						fread(&ris_scar, sizeof(risorsa_scaricata_t), 1,
								risorse_scaricate);

						// ricerca quali risorse, prodotte dal creatore in questione, sono state scaricate
						if (risorsa.codice_risorsa == ris_scar.codice_risorsa)
						{

							conta_valutazioni++;
							somma_valutazioni = somma_valutazioni+ ris_scar.valutazione;

							media_valutazioni = media(conta_valutazioni,somma_valutazioni) / 100;

						}
					}
					if (!feof(risorse))
					{
						puts("\n");
						printf(" %-16hi  %-20s %-24hi %-.2f ",
								risorsa.codice_risorsa,
								risorsa.titolo,
								conta_valutazioni,
								media_valutazioni);
					}
				}
			}

		} else {
			puts("\n");
			puts(" **Creatore non presente**");
		}

	}
	fclose(creatori);
	fclose(risorse_scaricate);
	fclose(risorse);

	puts("\n");
	system("pause");
}

void stampa_istogramma(int conta_tipologia[])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		puts("\n");
		stampa_tipologia(i + 1);		 // visualizza nome tipologia
		printf("\t");
		for (j = 0; j < conta_tipologia[i]; j++)
		{
			printf("|*|");
		}
		puts("\n");
	}

}

void statistiche_creatore()
{

	FILE *creatori = NULL;
	FILE *risorse = NULL;
	creatore_t creatore; 		//struttura di appoggio per scorrere il file
	risorsa_t risorsa; 			//struttura di appoggio per scorrere il file
	int conta_tipologia[NUM_TIPOLOGIE] = { 0 };			// conta le occorrenze di tipologia per il creatore analizzato
	short int i = 0;


	creatori = fopen("F_CREATORI.csv", "rb+");
	risorse = fopen("F_RISORSE.csv", "rb+");

	if (creatori == NULL || risorse == NULL)
	{
		puts(" **Errore nell'apertura dei file**");

	} else {

		puts(
				" \n Inserisci il creatore di cui si vogliono conoscere le statistiche");
		printf(" Codice creatore \n");
		creatore.codice_creatore = controllo_ins();

		fseek(creatori, (creatore.codice_creatore - 1) * sizeof(creatore_t),
				SEEK_SET);
		fread(&creatore, sizeof(creatore_t), 1, creatori);

		if (!feof(creatori) && creatore.codice_creatore != 0)
		{

			system("cls");

			printf(
					" \n   \t \t \t ISTOGRAMMA DELLE TIPOLOGIE RISORSE REALIZZATE DAL CREATORE:");
			printf(" %s %s", creatore.nome_creatore, creatore.cognome_creatore);
			ordina_creatori(creatori, 4);
			fseek(risorse, 0, SEEK_SET);

			fread(&risorsa, sizeof(risorsa_t), 1, risorse);
			while (!feof(risorse))
			{


				if (risorsa.codice_creatore == creatore.codice_creatore)
				{

					for (i = 0; i < (NUM_TIPOLOGIE - 1); i++)
					{
						if (risorsa.tipologia == (i + 1))		 // aggiungo +1 poiche' il ciclo parte da 0 ma le tipologie da 1
							conta_tipologia[i]++;
					}

				}
				fread(&risorsa, sizeof(risorsa_t), 1, risorse);
			}

		}

	}
	fclose(creatori);

	fclose(risorse);
	stampa_istogramma(conta_tipologia);
	puts("\n");


	medie_valutazioni(creatore);

}

void risorse_magg_scaricate()
{

	FILE *scaricamenti = NULL;
	FILE *risorse = NULL;

	int flag = 0, flag2 = 0, i = 0, j = 0, k = 0;  //variabili indice utilizzate all'interno dei cicli

	short int conta_ris_scar = 0, conta_ris_utili = 0; //variabili necessarie al fine di contare il numero di record nell'array dei codici
	//in modo dinamico (malloc)
	short int num_ins = 0;

	risorsa_scaricata_t ris_temp_sacricata = { 0, 0, 0, 0 };

	risorsa_t *risorsa;											//struct di appoggio per effettuare lettura e scrittura
	risorsa_t risorsa_temp = { 0, 0, 0, 0, 0, "", "", 0 };

	short int *codici_array;   //puntatore all'array dei codici
	short int codice_ris_max;

	codici_array = malloc(conta_ris_scar * sizeof(short int));

	scaricamenti = fopen("F_SCARICAMENTI.csv", "rb+");
	risorse = fopen("F_RISORSE.csv", "rb+");

	if (scaricamenti == NULL || risorse == NULL)
	{
		puts(" **Errore nell'apertura del file**");
	} else {

		//richista di inserire un intero che rappresenta il numero di risorse da prendere in considerazione
		//al fine di ricercare tra queste ultime il massimo
		//ossia il numero di codici da inserire nell'array dei codici

		puts("\n");
		printf(" Inserisci il numero di risorse da considereare (minimo %d) \n al fine di ricercarne quelle piu scaricate.\n" , MAX_SCARICAMENTI+3);


		num_ins = controllo_scelta(MAX_SCARICAMENTI+4 , 57599);


		//ciclo utile al fine di verificare se il numero inserito è maggiore delle risorse effettivamente scaricate, nel caso in cui sia vero
		//allora posiziona il puntatore all'inizio del file, oppure nel caso in cui è minore considera un numero di risorse pari al numero inserito
		//partendo dalla fine del file

		while (!feof(scaricamenti)
				) {

			fread(&ris_temp_sacricata, sizeof(risorsa_scaricata_t), 1,
					scaricamenti);
			conta_ris_scar++;
		}
		if(num_ins > conta_ris_scar)
		{

			fseek(scaricamenti, 0 , SEEK_SET);
			flag = 1;
		}else{

			num_ins = conta_ris_scar - num_ins;
			fseek(scaricamenti, (num_ins - 1) * sizeof(risorsa_scaricata_t),
					SEEK_SET);
		}
		//in base al codice salvato posiziono il puntatore e salvo tutti i codici a partire

		//ciclo utile al fine di determinare la dimensione dell'array che conterrà i codici, tale ciclo parte dalla posizione definita
		//precedentemente

		conta_ris_scar = 0;
		while (!feof(scaricamenti))
		{

			fread(&ris_temp_sacricata, sizeof(risorsa_scaricata_t), 1,
					scaricamenti);
			conta_ris_scar++;
		}

		codici_array = malloc(conta_ris_scar * sizeof(short int));

		//inizializzazione dell array
		for (j = 0; j < conta_ris_scar; j++)
		{
			codici_array[j] = 0;
		}

		//posizionamento del puntatore
		if(flag == 1){
			fseek(scaricamenti , 0 , SEEK_SET);
		}else{
			fseek(scaricamenti, (num_ins - 1) * sizeof(risorsa_scaricata_t),
					SEEK_SET);
		}

		//caricamento dei codici nell'array
		while (!feof(scaricamenti))
		{

			fread(&ris_temp_sacricata, sizeof(risorsa_scaricata_t), 1,
					scaricamenti);

			//ciclo per assicurarsi che non ci siano più codici uguali
			flag2 = 0;
			for (j = 0; j < conta_ris_scar; j++)
			{
				if (codici_array[j] == ris_temp_sacricata.codice_risorsa)
				{
					flag2 = 1;
				}
			}

			//se il codice in considerazione non è già stato caricato(flag2 == 0), allora lo carica
			if (flag2 != 1)
			{

				conta_ris_utili++;
				codici_array[conta_ris_utili - 1] =
						ris_temp_sacricata.codice_risorsa;
			}
		}

		//stampa dell'instestazione
		puts("\n");
		printf(
				" COD RISORSA TITOLO                NUM SCARICAMENTTI  DISCIPLINA  LIVELLO EDUCATIVO");


		risorsa = malloc(conta_ris_utili * sizeof(risorsa_t));

		//cliclo necessario al fine di caricare l'array che contiene le risorse selezionate in base ai codici dell'array dei codici
		for (k = 0; k < conta_ris_utili; k++)
		{

			if (codici_array[k] != 0) {
				//posiziona il puntatore sul codice e carica il blocco del file corrispondente
				fseek(risorse, (codici_array[k] - 1) * sizeof(risorsa_t),
						SEEK_SET);					//nell'array
				fread(&risorsa_temp, sizeof(risorsa_t), 1, risorse);

				risorsa[k] = risorsa_temp;
			}
		}

		//ricerca max numero di scaricamenti

		for (i = 0; i < MAX_SCARICAMENTI; i++)
		{
			codice_ris_max = ricerca_max_scaricamenti(risorsa,
					conta_ris_utili);

			fseek(risorse, (codice_ris_max - 1) * sizeof(risorsa_t),
					SEEK_SET);
			fread(&risorsa_temp, sizeof(risorsa_t), 1, risorse);

			if(risorsa_temp.conta_scar > 0)
			{
				puts("\n");
				printf(" %-12hi %-20s %-18hi ", risorsa_temp.codice_risorsa, risorsa_temp.titolo, risorsa_temp.conta_scar);
				stampa_disciplina(risorsa_temp.disciplina);
				stampa_livello_ed(risorsa_temp.livello_ed_risorsa);
			}

			//pone a 0 gli scaricamenti della risorsa già presa in considerazione, di conseguenza
			//la stessa viene scartata nella ricerca del massimo
			for (j = 0; j < conta_ris_utili; j++)
			{
				if (risorsa[j].codice_risorsa == codice_ris_max)
				{
					risorsa[j].conta_scar = 0;
				}
			}
		}




	}
	fclose(scaricamenti);
	fclose(risorse);

	puts("\n");
	system("PAUSE");
}




void menu_suggerimento_risorsa()
{


	int scelta_criterio = 0;

	printf(
			"\n Inserisci il criterio in base al quale vorresti ricevere un suggerrimento sulle risorse da scaricare \n");

	puts("\t\t\t ____________________________");
	puts("\t\t\t|                            |");
	puts("\t\t\t| 1) Tipologia               |");
	puts("\t\t\t| 2) Livello Educativo       |");
	puts("\t\t\t| 3) Disciplina              |");
	puts("\t\t\t| 4) Parola Chiave           |");
	puts("\t\t\t| 0) Torna al menu'          |");
	puts("\t\t\t|____________________________|");

	puts("\n");
	scelta_criterio = controllo_scelta(0, 4);

	suggerisci_risorsa(scelta_criterio);

	if (scelta_criterio == 0)
	{
		menu();
	}
	system("pause");


}

void suggerisci_risorsa(int scelta_criterio)
{

	FILE *utilizzatori = NULL;
	FILE *risorse = NULL;
	FILE *ris_scar = NULL;

	unsigned short int cod_utilizzatore = 0;	 // codice in base al quale fare la ricerca
	int flag1 = 0; 								// controlla che ci sia un codice utilizzatore corrispondente
	int flag=0;									// controlla che sia stata trovata una risorsa
	unsigned short int max_tipologia = 0, max_disciplina = 0;

	unsigned short int conta_disciplina[NUM_DISCIPLINE] = { 0 }; 		//conta discipline risorse scaricate dall'utilizzatore
	unsigned short int conta_tipologia[NUM_TIPOLOGIE] = { 0 }; 			//conta tipologie risorse  scaricate dall'utilizzatore
	char parola_chiave_ricercata[]="";

	utilizzatore_t utilizzatore; 				// struct per scorrere il file
	risorsa_t risorsa; 							// struct per scorrere il file
	risorsa_scaricata_t ris_scaricata;			 // struct per scorrere il file

	utilizzatori = fopen("F_UTILIZZATORI.csv", "rb+");
	risorse = fopen("F_RISORSE.csv", "rb+");
	ris_scar = fopen("F_SCARICAMENTI.csv", "rb+");

	if (utilizzatori == NULL || risorse == NULL || ris_scar == NULL)
	{
		puts(" **Errore nell'apertura dei file ");
	} else {
		ordina_utilizzatori(utilizzatori,4);			 // effettuo ordinamento del file in base al codice
		stampa_utilizzatori(1);

		puts("\n");
		printf(" Inserisci il codice dell'utilizzatore interessato \n");

		do { 		// controllo che il codice inserito sia presente nel file


			cod_utilizzatore = controllo_ins();

			fseek(utilizzatori, 0, SEEK_SET);

			while (!feof(utilizzatori))
			{
				fread(&utilizzatore, sizeof(utilizzatore_t), 1, utilizzatori);

				if (utilizzatore.codice_utilizzatore == cod_utilizzatore)
				{
					flag1 = 1;
				}
			}

		} while (flag1 == 0);



		fseek(ris_scar, 0, SEEK_SET);

		while (!feof(ris_scar))
		{

			fread(&ris_scaricata, sizeof(risorsa_scaricata_t), 1, ris_scar);
			if (cod_utilizzatore == ris_scaricata.codice_utilizzatore)
			{

				fseek(risorse,(ris_scaricata.codice_risorsa - 1) * sizeof(risorsa_t),SEEK_SET);
				fread(&risorsa, sizeof(risorsa_t), 1, risorse);

				conta_disciplina[risorsa.disciplina - 1]++; 		//conto occorrenze discipline
				conta_tipologia[risorsa.tipologia - 1]++; 			// conto occorrenze tipologie

			}
		}

		//cerco la disciplina risorsa piu' scaricata dall'utilizzatore
		for (int i = 0; i < NUM_DISCIPLINE; i++)
		{
			if (conta_disciplina[i] > max_disciplina)
			{

				max_disciplina = i + 1;
			}
		}
		//ricerco la tipologia risorsa piu' scaricata dall'utilizzatore
		for (int i = 0; i < NUM_TIPOLOGIE; i++)
		{
			if (conta_tipologia[i] > max_tipologia)
			{

				max_tipologia = i + 1;
			}
		}

		flag=0;
		fseek(risorse, 0, SEEK_SET);



		if (scelta_criterio==4)
		{

			printf("\n Inserisci la parola chiave: ");
			scanf("%s", parola_chiave_ricercata);
		}

		puts("\n");
		puts("___________________________________________________RISORSE____________________________________________________________\n");
		printf (" %-s   %-13s %-17s %-10s %-10s  %-24s %-10s  \n" ,  "CODICE" ,"TITOLO" , "CODICE CREATORE", "N SCARICAM" , " DISCIPLINA", "LIVELLO EDUCATIVO" , "TIPOLOGIA");

		while (!feof(risorse))
		{

			fread(&risorsa, sizeof(risorsa_t), 1, risorse);

			if(!feof(risorse))
			{
				if(scelta_criterio==1)
				{ 		// suggerimento in base alla tipologia

					if (max_tipologia == risorsa.tipologia)

					{

						printf("\n %-7hi  %-13s    ",  risorsa.codice_risorsa , risorsa.titolo  );
						printf("%-15hi %-12hi" ,  risorsa.codice_creatore , risorsa.conta_scar);
						stampa_disciplina(risorsa.disciplina);
						stampa_livello_ed(risorsa.livello_ed_risorsa);
						stampa_tipologia(risorsa.tipologia);

						flag = 1;
					}
				}


				if(scelta_criterio==2)
				{       // suggerimento in base al livello educativo


					if (utilizzatore.livello_ed_utilizzatore== risorsa.livello_ed_risorsa)

					{

						printf("\n %-7hi  %-13s    ",  risorsa.codice_risorsa , risorsa.titolo  );
						printf("%-15hi %-12hi" ,  risorsa.codice_creatore , risorsa.conta_scar);
						stampa_disciplina(risorsa.disciplina);
						stampa_livello_ed(risorsa.livello_ed_risorsa);
						stampa_tipologia(risorsa.tipologia);
						flag = 1;
					}
				}

				if(scelta_criterio==3)
				{       // suggerrimento in base alla tipologia

					if (max_tipologia == risorsa.tipologia)

					{


						printf("\n %-7hi  %-13s    ",  risorsa.codice_risorsa , risorsa.titolo  );
						printf("%-15hi %-12hi" ,  risorsa.codice_creatore , risorsa.conta_scar);
						stampa_disciplina(risorsa.disciplina);
						stampa_livello_ed(risorsa.livello_ed_risorsa);
						stampa_tipologia(risorsa.tipologia);
						flag = 1;
					}
				}

				if(scelta_criterio==4)
				{			 // suggerimento in base alla parola chiave

					if ((strspn (risorsa.parola_chiave,parola_chiave_ricercata))>VALORE_MIN_MATCHING)

					{

						printf("\n %-7hi  %-13s    ",  risorsa.codice_risorsa , risorsa.titolo  );
						printf("%-15hi %-12hi" ,  risorsa.codice_creatore , risorsa.conta_scar);
						stampa_disciplina(risorsa.disciplina);
						stampa_livello_ed(risorsa.livello_ed_risorsa);
						stampa_tipologia(risorsa.tipologia);
						flag = 1;
					}
				}

			}
		}

		if (flag == 0)
		{
			puts("\n Non ci sono risorse corrispondenti al valore cercato!");
		}

	}
	puts ("\n");
	fclose(risorse);
	fclose(utilizzatori);
	fclose(ris_scar);


}
