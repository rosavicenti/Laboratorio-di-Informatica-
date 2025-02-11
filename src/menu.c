/*
 * funz_proc.c
 *
 *  Created on: 2 mag 2020
 *      Author: Giuseppe Monitillo
 *      Author: Rosa Vicenti
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strutture.h"
#include "funzioni_inserimenti.h"
#include "visualizza.h"
#include "mod_canc.h"
#include "funzionalita.h"
#include "funz_accessorie.h"


FILE* risorse;
FILE* risorse_scaricate;
FILE* creatori;


int menu()
{

	unsigned short int operazione=0;
	unsigned short int operazione_principale=0;
	unsigned short int operazione_secondaria=0;



	puts("\n");
	puts("\t\t\t             MENU            ");
	puts("\t\t\t ___________________________");
	puts("\t\t\t|                           |");
	puts("\t\t\t| 1) Inserimenti            |");
	puts("\t\t\t| 2) Modifiche              |");
	puts("\t\t\t| 3) Eliminazione           |");
	puts("\t\t\t| 4) Visualizzione elenco   |");
	puts("\t\t\t| 5) Statistiche creatore   |");
	puts("\t\t\t| 6) Ordinamento elenco     |");
	puts("\t\t\t| 7) Suggerimento risorsa   |");
	puts("\t\t\t| 8) Stampa risorse piu     |");
	puts("\t\t\t|    scaricate              |");
	puts("\t\t\t| 9) Registra scaricamento  |");
	puts("\t\t\t| 0) Termina porgramma      |");
	puts("\t\t\t|___________________________|");

	puts("\n");
	puts(" Inserisci il codice dell'operazione che vuoi effettuare");
	operazione_principale=controllo_scelta(0,9);

	switch(operazione_principale)
	{

	case(1): puts("\t\t\t         Inserimenti         ");
	puts("\t\t\t ____________________________");
	puts("\t\t\t|                            |");
	puts("\t\t\t| 1) Utilizzatore            |");
	puts("\t\t\t| 2) Risorsa creata          |");
	puts("\t\t\t| 3) Torna al menu           |");
	puts("\t\t\t|____________________________|");

	puts("\n");
	puts("\n");
	puts(" Inserisci il codice dell'operazione che vuoi effettuare");

	operazione_secondaria=controllo_scelta(1,3);

	if(operazione_secondaria== 3)
	{
		menu();
	}
	if(operazione_secondaria == 1)
	{
		operazione = 11;
	}
	if(operazione_secondaria == 2)
	{
		operazione = 12;
	}

	break;

	case(2): puts("\t\t\t         Modifiche         ");
	puts("\t\t\t ____________________________");
	puts("\t\t\t|                            |");
	puts("\t\t\t| 1) Utilizzatore            |");
	puts("\t\t\t| 2) Risorsa                 |");
	puts("\t\t\t| 3) Torna al menu           |");
	puts("\t\t\t|____________________________|");

	puts("\n");
	puts("\n");
	puts(" Inserisci il codice dell'operazione che vuoi effettuare");
	operazione_secondaria= controllo_scelta(1,3);

	if(operazione_secondaria == 1)
	{
		operazione = 21;
	}
	if(operazione_secondaria == 2)
	{
		operazione = 22;
	}
	if(operazione_secondaria== 3)
	{
		menu();
	}
	break;

	case(3): puts("\t\t\t         Eliminazione         ");
	puts("\t\t\t ____________________________");
	puts("\t\t\t|                            |");
	puts("\t\t\t| 1) Utilizzatore            |");
	puts("\t\t\t| 2) Risorsa                 |");
	puts("\t\t\t| 3) Torna al menu           |");
	puts("\t\t\t|____________________________|");

	puts("\n");
	puts("\n");
	puts(" Inserisci il codice dell'operazione che vuoi effettuare");
	operazione_secondaria = controllo_scelta(1,3);

	if(operazione_secondaria == 1)
	{
		operazione = 31;
	}

	if(operazione_secondaria == 2)
	{
		operazione = 32;
	}

	if(operazione_secondaria== 3)
	{
		menu();
	}
	break;

	case(4): puts("\t\t\t     Visualizza elenco       ");
	puts("\t\t\t ____________________________");
	puts("\t\t\t|                            |");
	puts("\t\t\t| 1) Utilizzatore            |");
	puts("\t\t\t| 2) Risorsa                 |");
	puts("\t\t\t| 3) Creatore                |");
	puts("\t\t\t| 4) Torna al menu           |");
	puts("\t\t\t|____________________________|");

	puts("\n");
	operazione_secondaria =controllo_scelta(1,4);
	puts("\n");
	puts(" Inserisci il codice dell'operazione che vuoi effettuare");

	if(operazione_secondaria == 1)
	{
		operazione = 41;
	}

	if(operazione_secondaria == 2)
	{
		operazione = 42;
	}

	if(operazione_secondaria == 3)
	{
		operazione = 43;
	}

	if(operazione_secondaria== 4)
	{
		menu();
	}
	break;

	case(5): operazione = 5;
	break;

	case(6): puts("\t\t\t     Ordina elenco       ");
	puts("\t\t\t ____________________________");
	puts("\t\t\t|                            |");
	puts("\t\t\t| 1) Utilizzatore            |");
	puts("\t\t\t| 2) Risorsa                 |");
	puts("\t\t\t| 3) Creatore                |");
	puts("\t\t\t| 4) Torna al menu           |");
	puts("\t\t\t|____________________________|");

	puts("\n");
	puts("\n");
	puts(" Inserisci il codice dell'operazione che vuoi effettuare");
	operazione_secondaria = controllo_scelta(1,4);

	if(operazione_secondaria == 1)
	{
		operazione = 61;
	}

	if(operazione_secondaria == 2)
	{
		operazione = 62;
	}

	if(operazione_secondaria == 3)
	{
		operazione = 63;
	}

	if(operazione_secondaria== 4)
	{
		menu();
	}
	break;

	case(7): operazione = 7;
	break;

	case(8): operazione = 8;
	break;

	case(9): operazione = 9;
	break;

	case(0): operazione = 0;
	break;


	}

	return operazione;
}









