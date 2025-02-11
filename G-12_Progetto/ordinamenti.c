/*
 * ordinamenti.c
 *
 *  Created on: 14 mag 2020
 *       Author: Giuseppe Monitillo
 *       Author: Rosa Vicenti
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strutture.h"
#include "funzioni_inserimenti.h"
#include "menu.h"
#include "visualizza.h"
#include "mod_canc.h"
#include <malloc.h>
#include "ordinamenti.h"
#include "funz_accessorie.h"


void menu_ordina_utilizzatori()
{

	FILE *utilizzatori = NULL;
	int scelta_criterio = 0;
	utilizzatori = fopen("F_UTILIZZATORI.csv", "r+b");

	if (utilizzatori == NULL)
	{
		puts(" **Errore nell'apertura dei file**");

	} else {
		printf(
				"\n Inserisci il criterio in base al quale vuoi effettuare l'ordinamento sugli utilizzatori \n");

		puts("\t\t\t ____________________________");
		puts("\t\t\t|                            |");
		puts("\t\t\t| 1) Eta' utilizzatore       |");
		puts("\t\t\t| 2) Cognome utilizzatore    |");
		puts("\t\t\t| 3) Nome utilizzatore       |");
		puts("\t\t\t| 4) Codice utilizzatore     |");
		puts("\t\t\t| 0) Torna al menu'          |");
		puts("\t\t\t|____________________________|");

		puts("\n");
		scelta_criterio = controllo_scelta(0, 4);
		ordina_utilizzatori(utilizzatori, scelta_criterio);
		if (scelta_criterio == 0)
		{
			menu();
		}
		system("pause");
		fclose(utilizzatori);
	}
}


void scambia_utilizzatori(utilizzatore_t tempi,
		utilizzatore_t temp3,
		int i,
		int p,
		FILE *utilizzatori)
{
	fseek(utilizzatori, sizeof(utilizzatore_t) * (p),SEEK_SET);
	fwrite(&tempi, sizeof(utilizzatore_t), 1, utilizzatori);


	fseek(utilizzatori, sizeof(utilizzatore_t) * (i),SEEK_SET);
	fwrite(&temp3, sizeof(utilizzatore_t), 1, utilizzatori);

}

/// funzione che effettua l'ordinamento dell'elenco utilizzatori in base a un determinato criterio definito
/// dall'utente
void ordina_utilizzatori(FILE *utilizzatori, int scelta_criterio)
{
	int num_utilizzatori = 0;
	int i = 0, j = 0; 		// indici per ordinamento selection sort
	int pos_min = 0;		// variabile per salvare la posizone del minimo nel selection sort

	utilizzatore_t tempi = { 0, "", "", 0, 0, 0 }; 		//struct per effettuare lo scambio quando il min è in posizione i
	utilizzatore_t tempj = { 0, "", "", 0, 0, 0 };		//struct per effettuare lo scambio quando il min è in posizione j
	utilizzatore_t temp3 = { 0, "", "", 0, 0, 0 }; 		// struct per conservare il record del valore min quando viene trovato

	fseek(utilizzatori, 0, SEEK_END);
	num_utilizzatori = ftell(utilizzatori) / sizeof(utilizzatore_t);
	rewind(utilizzatori);

	for (i = 0; i < num_utilizzatori - 1; i++)
	{


		fseek(utilizzatori, sizeof(utilizzatore_t) * (i), SEEK_SET);
		fread(&tempi, sizeof(utilizzatore_t), 1, utilizzatori);
		temp3 = tempi;
		pos_min = i;

		if (scelta_criterio == 1)
		{ 	//ordinamento per eta'

			for (j = i + 1; j < (num_utilizzatori); j++)
			{

				fseek(utilizzatori, sizeof(utilizzatore_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(utilizzatore_t), 1, utilizzatori);

				if (tempj.eta_utilizzatore < temp3.eta_utilizzatore)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_utilizzatori(tempi, temp3, i, pos_min, utilizzatori);

		}

		if (scelta_criterio == 2)
		{ 	//ordinamento per cognome

			for (j = i + 1; j < (num_utilizzatori); j++)
			{

				fseek(utilizzatori, sizeof(utilizzatore_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(utilizzatore_t), 1, utilizzatori);

				if (strcmp(temp3.cognome_utilizzatore,
						tempj.cognome_utilizzatore) > 0)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_utilizzatori(tempi, temp3, i, pos_min, utilizzatori);

		}
		if (scelta_criterio == 3)
		{		//ordinamento per nome

			for (j = i + 1; j < (num_utilizzatori); j++)
			{

				fseek(utilizzatori, sizeof(utilizzatore_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(utilizzatore_t), 1, utilizzatori);

				if (strcmp(temp3.nome_utilizzatore, tempj.nome_utilizzatore) > 0)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_utilizzatori(tempi, temp3, i, pos_min, utilizzatori);

		}

		if (scelta_criterio == 4)
		{ //ordinamento per codice

			for (j = i + 1; j < (num_utilizzatori); j++)
			{

				fseek(utilizzatori, sizeof(utilizzatore_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(utilizzatore_t), 1, utilizzatori);

				if (tempj.codice_utilizzatore < temp3.codice_utilizzatore)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_utilizzatori(tempi, temp3, i, pos_min, utilizzatori);

		}
	}
}


/// funzione che mostra all'utente un sottomenÃ¹ utile al fine di scegliere quale criterio necessita
/// seguire per effettuare l'ordinamento
void menu_ordina_creatori()
{

	FILE *creatori = NULL;
	int scelta_criterio = 0;
	creatori = fopen("F_CREATORI.csv", "r+b");

	if (creatori == NULL)
	{
		puts(" **Errore nell'apertura dei file**");

	} else {
		printf(
				"\n Inserisci il criterio in base al quale vuoi effettuare l'ordinamento sui creatori \n");

		puts("\t\t\t ____________________________");
		puts("\t\t\t|                            |");
		puts("\t\t\t| 1) Eta' creatori           |");
		puts("\t\t\t| 2) Cognome creatori        |");
		puts("\t\t\t| 3) Nome creatori           |");
		puts("\t\t\t| 4) Codice creatore         |");
		puts("\t\t\t| 0) Torna al menu'          |");
		puts("\t\t\t|____________________________|");

		puts("\n");
		scelta_criterio = controllo_scelta(0, 4);
		ordina_creatori(creatori, scelta_criterio);
		if (scelta_criterio == 0)
		{
			menu();
		}
		system("pause");
		fclose(creatori);
	}
}


void scambia_creatori(creatore_t tempi,
		creatore_t temp3,
		int i,
		int p,
		FILE *creatori)
{

	fseek(creatori, sizeof(creatore_t) * (p),SEEK_SET);
	fwrite(&tempi, sizeof(creatore_t), 1, creatori);


	fseek(creatori, sizeof(creatore_t) * (i),SEEK_SET);
	fwrite(&temp3, sizeof(creatore_t), 1, creatori);

}

/// funzione che effettua l'ordinamento dell'elenco creatori in base a un determinato criterio definito
/// dall'utente
void ordina_creatori(FILE *creatori, int scelta_criterio)
{
	int num_creatori = 0;
	int i = 0, j = 0;		//indici per il Selection Sort
	int pos_min = 0;		// per  salvare la posizione del minimo

	creatore_t tempi = { 0, "", "", 0, 0, 0 };		//struct per effettuare lo scambio quando il min è in posizione i
	creatore_t tempj = { 0, "", "", 0, 0, 0 };		//struct per effettuare lo scambio quando il min è in posizione j
	creatore_t temp3 = { 0, "", "", 0, 0, 0 };		//struct per conservare il record del valore del min quando viene trovato

	fseek(creatori, 0, SEEK_END);
	num_creatori = ftell(creatori) / sizeof(creatore_t);
	rewind(creatori);

	for (i = 0; i < num_creatori - 1; i++)
	{
		rewind(creatori);
		fseek(creatori, sizeof(creatore_t) * (i), SEEK_SET);
		fread(&tempi, sizeof(creatore_t), 1, creatori);

		temp3 = tempi;
		pos_min = i;

		//ordinamento per eta
		if (scelta_criterio == 1)
		{

			for (j = i + 1; j < (num_creatori); j++)
			{

				fseek(creatori, sizeof(creatore_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(creatore_t), 1, creatori);

				if (tempj.eta_creatore < temp3.eta_creatore)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_creatori(tempi, temp3, i, pos_min, creatori);

		}

		//ordinamento per cognome
		if (scelta_criterio == 2)
		{

			for (j = i + 1; j < (num_creatori); j++)
			{

				fseek(creatori, sizeof(creatore_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(creatore_t), 1, creatori);

				if (strcmp(temp3.cognome_creatore, tempj.cognome_creatore) > 0)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_creatori(tempi, temp3, i, pos_min, creatori);

		}

		//ordinamento per nome
		if (scelta_criterio == 3)
		{

			for (j = i + 1; j < (num_creatori); j++)
			{

				fseek(creatori, sizeof(creatore_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(creatore_t), 1, creatori);

				if (strcmp(temp3.nome_creatore, tempj.nome_creatore) > 0)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_creatori(tempi, temp3, i, pos_min, creatori);

		}

		//ordinamento per codice
		if (scelta_criterio == 4)
		{

			for (j = i + 1; j < (num_creatori); j++)
			{

				fseek(creatori, sizeof(creatore_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(creatore_t), 1, creatori);

				if (tempj.codice_creatore < temp3.codice_creatore)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_creatori(tempi, temp3, i, pos_min, creatori);

		}

	}
}


void menu_ordina_risorse()
{
	FILE *risorse = NULL;
	int scelta_criterio = 0;
	risorse = fopen("F_RISORSE.csv", "r+b");

	if (risorse == NULL)
	{
		puts(" **Errore nell'apertura dei file**");

	} else {
		printf(
				"\n Inserisci il criterio in base al quale vuoi effettuare l'ordinamento sulle risorse \n");

		puts("\t\t\t ____________________________");
		puts("\t\t\t|                            |");
		puts("\t\t\t| 1) Risorse piu' scaricate  |");
		puts("\t\t\t| 2) Titolo                  |");
		puts("\t\t\t| 3) Parola chiave           |");
		puts("\t\t\t| 4) Codice Risorse          |");
		puts("\t\t\t| 0) Torna al menu'          |");
		puts("\t\t\t|____________________________|");

		puts("\n");
		scelta_criterio = controllo_scelta(0, 4);
		ordina_risorse(risorse, scelta_criterio);
		if (scelta_criterio == 0)
		{
			menu();
		}
		system("pause");
		fclose(risorse);
	}
}


void scambia_risorse(risorsa_t tempi,
		risorsa_t temp3,
		int i,
		int p,
		FILE *risorse)
{
	fseek(risorse, sizeof(risorsa_t) * (p),SEEK_SET);
	fwrite(&tempi, sizeof(risorsa_t), 1, risorse);

	fseek(risorse, sizeof(risorsa_t) * (i),SEEK_SET);
	fwrite(&temp3, sizeof(risorsa_t), 1, risorse);

}


void ordina_risorse(FILE *risorse, int scelta_criterio)
{
	int num_risorse = 0;
	int i = 0, j = 0;		//indici per il Selection Sort
	int pos_min = 0;		//per salvare la posizione del min

	risorsa_t tempi = { 0, 0, 0, 0, 0, "", "", 0 };		//struct per effettuare lo scambio quando il min è in posizione i
	risorsa_t tempj = { 0, 0, 0, 0, 0, "", "", 0 };		//struct per effettuare lo scambio quando il min è in posizione j
	risorsa_t temp3 = { 0, 0, 0, 0, 0, "", "", 0 };		// struct per conservare il record del valore min quando viene trovato

	fseek(risorse, 0, SEEK_END);
	num_risorse = ftell(risorse) / sizeof(risorsa_t); // conta il numero di record presenti nel file
	rewind(risorse);

	for (i = 0; i < num_risorse - 1; i++)
	{

		fseek(risorse, sizeof(risorsa_t) * (i), SEEK_SET);
		fread(&tempi, sizeof(risorsa_t), 1, risorse);
		temp3 = tempi;
		pos_min = i;

		//ordina risorse dalla meno scaricata alla piu scaricata
		if (scelta_criterio == 1)
		{

			for (j = i + 1; j < (num_risorse); j++)
			{

				fseek(risorse, sizeof(risorsa_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(risorsa_t), 1, risorse);

				if (tempj.conta_scar < temp3.conta_scar)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_risorse(tempi, temp3, i, pos_min, risorse);

		}

		//ordina per nome del titolo
		if (scelta_criterio == 2)
		{

			for (j = i + 1; j < (num_risorse); j++)
			{

				fseek(risorse, sizeof(risorsa_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(risorsa_t), 1, risorse);

				if (strcmp(temp3.titolo, tempj.titolo) > 0)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_risorse(tempi, temp3, i, pos_min, risorse);

		}

		//ordinamento per parola chiave
		if (scelta_criterio == 3)
		{

			for (j = i + 1; j < (num_risorse); j++)
			{

				fseek(risorse, sizeof(risorsa_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(risorsa_t), 1, risorse);
				if (strcmp(temp3.parola_chiave, tempj.parola_chiave) > 0)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_risorse(tempi, temp3, i, pos_min, risorse);

		}

		//ordinamento per codice risorsa
		if (scelta_criterio == 4)
		{

			for (j = i + 1; j < (num_risorse); j++)
			{

				fseek(risorse, sizeof(risorsa_t) * (j), SEEK_SET);
				fread(&tempj, sizeof(risorsa_t), 1, risorse);

				if (tempj.codice_risorsa < temp3.codice_risorsa)
				{

					temp3 = tempj;
					pos_min = j;

				}
			}
			scambia_risorse(tempi, temp3, i, pos_min, risorse);

		}

	}
}
