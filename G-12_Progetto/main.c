/**
 * esame.c
 *
 *  Created on: 1 mag 2020
 *      Author: Utente
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "strutture.h"
#include "funzioni_inserimenti.h"
#include "menu.h"
#include "visualizza.h"
#include "mod_canc.h"
#include "funzionalita.h"
#include "ordinamenti.h"
#include "funz_accessorie.h"




int main(){

	setvbuf(stdout , NULL, _IONBF, 0);
	setvbuf(stdin , NULL, _IONBF, 0);


	FILE* open;
	FILE* open1;
	FILE* open2;
	FILE* open3;
	FILE* open4;

	open = fopen("F_CONTATORE.csv" , "rb+");
	fclose(open);
	open1 = fopen("F_UTILIZZATORI.csv" , "rb+");
	fclose(open1);
	open2 = fopen("F_RISORSE.csv" , "rb+");
	fclose(open2);
	open3 = fopen("F_CREATORI.csv" , "rb+");
	fclose(open3);
	open4 = fopen("F_SCARICAMENTI.csv" , "rb+");
	fclose(open4);
	if(open == NULL && open1 == NULL && open2 == NULL && open3 == NULL && open4 == NULL)
	{
		puts(" **Errore nell'apertura dei file**");
	}


	puts("                     !! Benvenuti in oer_commons.com !!");


	int controllo_fine = 0;

	// utile per accertarsi che l'utente voglia effettivamente uscire dal programma
	int operazione=0;
	int x=0;

	//ciclo infinito col fine di effettuare potenzialmente infinite operazioni senza chiudere il programma
	do
	{

		operazione = menu();
		switch(operazione)
		{

		case(0): puts("\n");
		printf(" Premere 1 per confermare, un alro carattere per annullare: ");
		scanf("%d" , &controllo_fine);
		if(controllo_fine == 1)
		{
			puts("\n");
			puts("              !! Grazie per aver utilizzato il software !!");
			sleep(5);
			return 0;
		}else{
			menu();
		}
		break;

		case(11): ins_utilizzatore();
		system("cls");
		break;

		case(12): ins_risorsa();
		system("cls");
		break;

		case(21): stampa_utilizzatori(1);
		modifica_utilizzatore();
		system("cls");
		break;

		case(22): stampa_risorse(1);
		modifica_risorsa();
		system("cls");
		break;

		case(31): stampa_utilizzatori(1);
		elimina_utilizzatore();
		system("cls");
		break;

		case(32): stampa_risorse(1);
		elimina_risorsa();
		system("cls");
		break;

		case(41): stampa_utilizzatori(0);
		system("cls");
		break;

		case(42): stampa_risorse(0);
		system("cls");
		break;

		case(43): stampa_creatori(0);
		system("cls");
		break;

		case(5): stampa_creatori(1);
		statistiche_creatore();
		system("cls");
		break;

		case(61): menu_ordina_utilizzatori();
		stampa_utilizzatori(0);
		system("cls");
		break;

		case(62): menu_ordina_risorse(0);
		stampa_risorse(0);
		system("cls");
		break;

		case(63): menu_ordina_creatori();
		stampa_creatori(0);
		system("cls");
		break;

		case(7): menu_suggerimento_risorsa();
		system("cls");
		break;

		case(8): risorse_magg_scaricate();
		system("cls");
		break;

		case(9): registra_scaricamento();
		system("cls");
		break;


		}

		puliscinput();
	}while(x == 0);
}
