/*
 * mod_canc.c
 *
 *  Created on: 11 mag 2020
 *       Author: Giuseppe Monitillo
 *        Author: Rosa Vicenti
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutture.h"
#include "funzioni_inserimenti.h"
#include "menu.h"
#include "visualizza.h"
#include "funzionalita.h"
#include "funz_accessorie.h"
#include "ordinamenti.h"


/**
 * @file mod_canc.h
 * @brief Libreria contenente tutte le funzioni utili alla modifica e cancellazione degli
 * 		  elementi dei file\n
 */



void modifica_risorsa()
{

	FILE *risorse_create;
	risorsa_t risorsa = { 0, 0, 0, 0, 0, "", "" };



	risorse_create = fopen("F_RISORSE.csv", "rb+");

	if (risorse_create == NULL)
	{
		puts("\n");
		puts(" Errore nell'apertura del file F_RISORSE.csv ");
	} else {
		ordina_risorse(risorse_create, 4);

		printf("\n Inserisci il codice della risorsa che vuoi modificare\n");


		risorsa.codice_risorsa = controllo_ins();

		fseek(risorse_create, (risorsa.codice_risorsa - 1) * sizeof(risorsa_t),SEEK_SET);

		fread(&risorsa, sizeof(risorsa_t), 1, risorse_create);

		if (!feof(risorse_create) && risorsa.codice_risorsa != 0)
		{

			puts("\n");
			puts("\n Inserisci i dati realativi la risorsa ");
			printf(" Titolo: ");



			puliscinput();
			fgets(risorsa.titolo, 20, stdin);



			elimina_new_line_terminale(&risorsa.titolo);

			formatta_stringa(risorsa.titolo);



			printf("\n Parola chiave : ");
			scanf("%s", risorsa.parola_chiave);
			formatta_stringa(risorsa.parola_chiave);

			puts("\n");


			puts(
					" Inserisci il codice indentificativo della disciplina che riguarda la risorsa");
			puts(" 1) Matematica");
			puts(" 2) Storia");
			puts(" 3) Italiano");
			puts(" 4) Inglese");
			puts(" 5) Fisica");


			risorsa.disciplina = controllo_scelta(1, 5);

			puts("\n");
			puts(" Inserisci il livello educativo che riguarda la risorsa");
			puts(" 1) Scuola primaria");
			puts(" 2) Scuola secondaria di primo grado");
			puts(" 3) Scuola secondaria di secondo grado");
			puts(" 4) Istruzione Universitaria");


			risorsa.livello_ed_risorsa = controllo_scelta(1, 4);

			puts("\n");
			puts(" Inserisci la tipologia della risorsa");
			puts(" 1) Testuale");
			puts(" 2) Video lezione");
			puts(" 3) Gioco didattico");


			risorsa.tipologia = controllo_scelta(1, 3);

			fseek(risorse_create,
					(risorsa.codice_risorsa - 1) * sizeof(risorsa_t), SEEK_SET);
			fwrite(&risorsa, sizeof(risorsa_t), 1, risorse_create);
			puts(" RISORSA MODIFICATA!");
		} else {

			puts("CODICE NON TROVATO!");
		}

	}
	fclose(risorse_create);
	system(" PAUSE");

}


void elimina_risorsa()
{

	FILE *risorse_create;
	risorsa_t risorsa = { 0, 0, 0, 0, 0, "", "" };
	risorsa_t risorsa_reset = { 0, 0, 0, 0, 0, "", "" };

	short int codice = 0;

	risorse_create = fopen("F_RISORSE.csv", "rb+");

	if (risorse_create == NULL)
	{
		puts("\n");
		puts(" Errore nell'apertura del file F_RISORSE.csv ");
	} else {

		ordina_risorse(risorse_create , 4);
		printf("\n Inserisci il codice della risorsa che vuoi eliminare\n");

		risorsa.codice_risorsa = controllo_ins();

		fseek(risorse_create, (risorsa.codice_risorsa - 1) * sizeof(risorsa_t),
				SEEK_SET);
		fread(&risorsa, sizeof(risorsa_t), 1, risorse_create);

		if (!feof(risorse_create) && risorsa.codice_risorsa != 0)
		{
			codice = risorsa.codice_risorsa;	 // conservo il codice prima di sovrascriverlo
			risorsa = risorsa_reset;

			fseek(risorse_create, (codice - 1) * sizeof(risorsa_t), SEEK_SET);
			fwrite(&risorsa_reset, sizeof(risorsa_t), 1, risorse_create);
			puts(" RISORSA CANCELLATA!");
		} else {

			puts("CODICE NON TROVATO!");
		}

	}
	fclose(risorse_create);
	system(" PAUSE");

}

/// procedura che consente di eliminare un utilizzatore dal sistema, ossia un record nel file F_UTILIZZATORI.csv
/// la selezione è effettuata mediante la stampa dell'elenco utilizzatori e l'inserimento del codice identificativo
/// dell'utilizzatore
void elimina_utilizzatore()
{

	FILE *utilizzatori;
	utilizzatore_t utilizzatore, utilizzatore_reset = { 0, "", "", 0, 0, 0 };
	short int codice = 0;

	utilizzatori = fopen("F_UTILIZZATORI.csv", "rb+");

	if (utilizzatori == NULL)
	{
		puts("\n");
		puts(" Errore nell'apertura del file F_UTILIZZATORI.csv ");
	} else {

		ordina_utilizzatori(utilizzatori, 4);

		printf("\n Inserisci il codice dell'utilizzatore che vuoi eliminare\n");
		utilizzatore.codice_utilizzatore = controllo_ins();

		fseek(utilizzatori,
				(utilizzatore.codice_utilizzatore - 1) * sizeof(utilizzatore_t),
				SEEK_SET);
		fread(&utilizzatore, sizeof(utilizzatore_t), 1, utilizzatori); //questa fread è necessaria per controllare che il record esista e sia avvalorato

		if (!feof(utilizzatori) && utilizzatore.codice_utilizzatore != 0)
		{

			codice = utilizzatore.codice_utilizzatore; //mi conservo il codice prima di sovrascriverlo
			utilizzatore = utilizzatore_reset;

			fseek(utilizzatori, (codice - 1) * sizeof(utilizzatore_t),
					SEEK_SET); //questa fseek è necessaria perchè dopo la fread il puntatore si è spostato
			fwrite(&utilizzatore, sizeof(utilizzatore), 1, utilizzatori);
			puts(" UTILIZZATORE CANCELLATO!");
		} else
			puts("CODICE NON TROVATO!");

	}
	fclose(utilizzatori);
	system(" PAUSE");

}

/// procedura che consente di modificare un utilizzatore dal sistema, ossia un record nel file F_UTILIZZATORI.csv
/// la selezione è effettuata mediante la stampa dell'elenco utilizzatori e l'inserimento del codice identificativo
/// dell'utilizzatore
void modifica_utilizzatore()
{

	FILE *utilizzatori;
	utilizzatore_t utilizzatore = { 0, "", "", 0, 0, 0 };


	utilizzatori = fopen("F_UTILIZZATORI.csv", "rb+");

	if (utilizzatori == NULL)
	{
		puts("\n");
		puts(" Errore nell'apertura del file F_UTILIZZATORI.csv ");
	} else {

		ordina_utilizzatori(utilizzatori, 4);

		printf("\n Inserisci il codice dell'utilizzatore che vuoi eliminare\n");

		utilizzatore.codice_utilizzatore = controllo_ins();

		fseek(utilizzatori,
				(utilizzatore.codice_utilizzatore - 1) * sizeof(utilizzatore_t),
				SEEK_SET);
		fread(&utilizzatore, sizeof(utilizzatore_t), 1, utilizzatori); //questa fread è necessaria per controllare che il record esista e sia avvalorato

		if (!feof(utilizzatori) && utilizzatore.codice_utilizzatore != 0)
		{

			puts("\n");
			puts(" Inserisci i dati relativi l'utilizzatore ");
			printf(" Nome: ");
			scanf("%s", utilizzatore.nome_utilizzatore);
			formatta_stringa(utilizzatore.nome_utilizzatore);


			printf(" Cognome: ");
			scanf("%s", utilizzatore.cognome_utilizzatore);
			formatta_stringa(utilizzatore.cognome_utilizzatore);


			printf(" Eta \n");
			utilizzatore.eta_utilizzatore = controllo_scelta(6 , 115);


			puts("\n");
			puts(" Inserisci il codice indentificativo della disciplina");
			puts(" 1) Matematica");
			puts(" 2) Storia");
			puts(" 3) Italiano");
			puts(" 4) Inglese");
			puts(" 5) Fisica");

			utilizzatore.disciplina_utilizzatore = controllo_scelta(1, 5);

			puts("\n");
			puts(" Inserisci il livello educativo dell'utilizzatore");
			puts(" 1) Scuola primaria");
			puts(" 2) Scuola secondaria di primo grado");
			puts(" 3) Scuola secondaria di secondo grado");
			puts(" 4) Istruzione Universitaria");
			utilizzatore.livello_ed_utilizzatore = controllo_scelta(1, 4);

			fseek(utilizzatori,
					(utilizzatore.codice_utilizzatore - 1)* sizeof(utilizzatore_t), SEEK_SET); //questa fseek è necessaria perchè dopo la fread il puntatore si è spostato
			fwrite(&utilizzatore, sizeof(utilizzatore), 1, utilizzatori);
			puts(" UTILIZZATORE MODIFICATO!");
		} else
			puts("CODICE NON TROVATO!");

	}
	fclose(utilizzatori);
	system(" PAUSE");

}
