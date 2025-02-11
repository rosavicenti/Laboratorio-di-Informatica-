
/*
 *  Author: Giuseppe Monitillo
 *  Author: Rosa Vicenti
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strutture.h"
#include "menu.h"
#include "visualizza.h"
#include "mod_canc.h"
#include "funzionalita.h"
#include "funz_accessorie.h"



int conta_elementi(FILE* file , const char* nome , int num)
{

	int conta_elementi=0;
	file = fopen(nome , "rb+");

	if(file == NULL)
	{
		puts("**Errore nell'apertura del file CONTATORE**");
	}else{

		switch(num)
		{


		//contatore per codice utilizzatore
		case(1):
 	 					  fseek(file , 0 , SEEK_SET);
		fread(&conta_elementi , sizeof(conta_elementi) , 1 , file);

		conta_elementi = conta_elementi + 1;

		fseek(file , 0 , SEEK_SET);
		fwrite(&conta_elementi , sizeof(conta_elementi) , 1 , file);
		break;

		//contatore per codice risorsa
		case(2):
						 fseek(file , 0 , SEEK_SET);
		fseek(file , 1 * sizeof(conta_elementi) , SEEK_CUR);

		fread(&conta_elementi ,  sizeof(conta_elementi) , 1 , file);

		conta_elementi = conta_elementi + 1;

		fseek(file , 0 , SEEK_SET);
		fseek(file , 1 * sizeof(conta_elementi) , SEEK_CUR);
		fwrite(&conta_elementi , 1 * sizeof(conta_elementi) , 1 , file);
		break;

		//contatore per codice creatore
		case(3):
 	 					  fseek(file , 0 , SEEK_SET);
		fseek(file , 2 * sizeof(conta_elementi) , SEEK_CUR);
		fread(&conta_elementi ,  sizeof(conta_elementi) , 1 , file);

		conta_elementi = conta_elementi + 1;

		fseek(file , 0 , SEEK_SET);
		fseek(file , 2 * sizeof(conta_elementi) , SEEK_CUR);
		fwrite(&conta_elementi ,  sizeof(conta_elementi) , 1 , file);
		break;

		//contatore per codice scaricamento / risorsa scaricata
		case(4):
	            		   fseek(file , 0 , SEEK_SET);
		fseek(file , 3 * sizeof(conta_elementi) , SEEK_CUR);
		fread(&conta_elementi ,  sizeof(conta_elementi) , 1 , file);

		conta_elementi = conta_elementi + 1;

		fseek(file , 0 , SEEK_SET);
		fseek(file , 3 * sizeof(conta_elementi) , SEEK_CUR);
		fwrite(&conta_elementi ,  sizeof(conta_elementi) , 1 , file);
		break;

		}



		fclose(file);
	}

	return conta_elementi;
}


void ins_utilizzatore()
{

	FILE* utilizzatori;
	FILE* fp_count = NULL;
	utilizzatore_t utilizzatore = {0 , "" , "" ,  0 , 0 , 0};// struttura d'appoggio per scorrrere il file




	utilizzatori = fopen("F_UTILIZZATORI.csv" , "rb+");

	if(utilizzatori == NULL){
		puts("\n");
		puts(" **Errore nell'apertura del file F_UTILIZZATORI.csv** ");
	}else{

		puts("\n");
		puts(" Inserisci i dati relativi l'utilizzatore ");
		printf(" Nome: ");
		scanf("%s" , utilizzatore.nome_utilizzatore);
		formatta_stringa(utilizzatore.nome_utilizzatore);

		printf(" Cognome: ");
		scanf("%s" , utilizzatore.cognome_utilizzatore);
		formatta_stringa(utilizzatore.cognome_utilizzatore);

		puliscinput();
		printf(" Eta\n");
		utilizzatore.eta_utilizzatore=controllo_scelta(MIN_ETA_UTILIZZATORE , MAX_ETA_UTILIZZATORE);

		puts("\n");
		puts(" Inserisci il codice indentificativo della disciplina");
		puts(" 1) Matematica");
		puts(" 2) Storia");
		puts(" 3) Italiano");
		puts(" 4) Inglese");
		puts(" 5) Fisica");

		utilizzatore.disciplina_utilizzatore= controllo_scelta(1, NUM_DISCIPLINE);


		puts("\n");
		puts(" Inserisci il livello educativo dell'utilizzatore");
		puts(" 1) Scuola primaria");
		puts(" 2) Scuola secondaria di primo grado");
		puts(" 3) Scuola secondaria di secondo grado");
		puts(" 4) Istruzione Universitaria");


		utilizzatore.livello_ed_utilizzatore=controllo_scelta(1,NUM_LIVELLO_ED);


		utilizzatore.codice_utilizzatore = conta_elementi(fp_count , "F_CONTATORE.csv" , 1);

		fseek(utilizzatori , 0 , SEEK_END);
		fwrite(&utilizzatore , sizeof(utilizzatore_t) , 1 , utilizzatori);

		fclose(utilizzatori);
		fclose(fp_count);

		puts("\n");
		puts(" Operazione andata a buon fine");
		system("PAUSE");


	}
}


void ins_creatore(short int* codice)
{

	FILE* creatori;
	FILE* fp_count = NULL;
	creatore_t creatore = {0 , "" , "" ,  0 , 0 , 0};

	creatori = fopen("F_CREATORI.csv" , "rb+");

	if(creatori == NULL){
		puts("\n");
		puts(" **Errore nell'apertura del file F_CREATORI.csv** ");
	}else{

		puts("\n");
		puts("\n Inserisci i dati del creatore ");
		printf(" Nome: ");
		scanf("%s" ,creatore.nome_creatore);
		formatta_stringa(creatore.nome_creatore);

		printf(" Cognome: ");
		scanf("%s" , creatore.cognome_creatore);
		formatta_stringa(creatore.cognome_creatore);

		printf(" Eta \n");

		creatore.eta_creatore= controllo_scelta(MIN_ETA_CREATORE , MAX_ETA_CREATORE);


		puts("\n");
		puts(" Inserisci il codice indentificativo della disciplina del creatore");
		puts(" 1) Matematica");
		puts(" 2) Storia");
		puts(" 3) Italiano");
		puts(" 4) Inglese");
		puts(" 5) Fisica");


		creatore.disciplina_creatore=controllo_scelta(1,NUM_DISCIPLINE);


		puts("\n");
		puts(" Inserisci il livello educativo del creatore");
		puts(" 1) Scuola primaria");
		puts(" 2) Scuola secondaria di primo grado");
		puts(" 3) Scuola secondaria di secondo grado");
		puts(" 4) Istruzione Universitaria");


		creatore.livello_ed_creatore=controllo_scelta(1,NUM_LIVELLO_ED);



		creatore.codice_creatore = conta_elementi(fp_count , "F_CONTATORE.csv" , 3);
		*codice= creatore.codice_creatore;
		fseek(creatori , 0 , SEEK_END);
		fwrite(&creatore , sizeof(creatore_t) , 1 , creatori);

		fclose(creatori);
		fclose(fp_count);


	}
}

int ricerca_creatore(short int* codice)
{
	short int flag = 0;		 // per controllare che esista un creatore corrispondete al nome inserito
	FILE* creatori = NULL;

	char nome_creatore[LUNGH_NOME] = {""};
	char cognome_creatore[LUNGH_COGNOME] = {""};

	creatore_t creatore_temp;		 //struct d'appoggio per scorrere il file creatori




	creatori = fopen("F_CREATORI.csv" , "rb+");

	if(creatori == NULL){
		puts(" **Errore nell'apertura del file F_CREATORI.csv**");
	}else{

		puts(" Inserisci l'anagrafica del creatore della risorsa");
		printf(" Nome: ");
		scanf("%20s" , nome_creatore);
		formatta_stringa(nome_creatore);


		printf(" Cognome: ");
		scanf("%20s" , cognome_creatore);
		formatta_stringa(cognome_creatore);

		rewind(creatori);
		while(!feof(creatori)){

			fread(&creatore_temp , sizeof(creatore_t) , 1 , creatori);

			if(strcmp(nome_creatore , creatore_temp.nome_creatore) == 0)
			{
				if(strcmp(cognome_creatore , creatore_temp.cognome_creatore) == 0)
				{

					*codice = creatore_temp.codice_creatore;       // utile per registare il codice creatore nella nuova  risorsa caricata
					flag = 1;
				}

			}

		}

	}
	fclose(creatori);
	return flag;
}



void ins_risorsa()
{

	FILE *risorse_create = NULL;
	FILE *fp_count = NULL;

	risorsa_t risorsa = { 0, 0, 0, 0, 0, "", "" };               // struct d'appoggio per scorrere file risorse

	short int codice_creatore = 0;
	short int codice_creatore_presente = 0;
	risorse_create = fopen("F_RISORSE.csv", "rb+");

	if (risorse_create == NULL)
	{
		puts("\n");
		puts(" **Errore nell'apertura del file F_RISORSE.csv** ");
	} else {

		puts("\n");
		puts("\n Inserisci i dati realativi la risorsa ");
		printf(" Titolo: ");

		puliscinput();
		fgets(risorsa.titolo, LUNGH_TITOLO, stdin);

		elimina_new_line_terminale(&risorsa.titolo);

		formatta_stringa(risorsa.titolo);

		printf("\n Parola chiave: ");
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

		risorsa.disciplina = controllo_scelta(1, NUM_DISCIPLINE);

		puts("\n");
		puts(" Inserisci il livello educativo che riguarda la risorsa");
		puts(" 1) Scuola primaria");
		puts(" 2) Scuola secondaria di primo grado");
		puts(" 3) Scuola secondaria di secondo grado");
		puts(" 4) Istruzione Universitaria");


		risorsa.livello_ed_risorsa = controllo_scelta(1, NUM_LIVELLO_ED);

		puts("\n");
		puts(" Inserisci la tipologia della risorsa");
		puts(" 1) Testuale");
		puts(" 2) Video lezione");
		puts(" 3) Gioco didattico");


		risorsa.tipologia = controllo_scelta(1, NUM_TIPOLOGIE);

		risorsa.codice_risorsa = conta_elementi(fp_count, "F_CONTATORE.csv", 2);

		// la funzione restituisce 1 se il creatore e' gia presente
		if (ricerca_creatore(&codice_creatore_presente) == 1)
		{
			puts(" Creatore presente nel file F_CREATORI.csv");
			risorsa.codice_creatore = codice_creatore_presente;
		} else {

			puts(" Creatore non presente nel file F_CREATORI.csv");
			puts(" procedere con l'inserimento");
			puts("\n");
			ins_creatore(&codice_creatore);
			risorsa.codice_creatore = codice_creatore;
		}

		fseek(risorse_create, 0, SEEK_END);
		fwrite(&risorsa, sizeof(risorsa_t), 1, risorse_create);

		fclose(risorse_create);
		fclose(fp_count);

		puts("\n");
		puts(" Operazione andata a buon fine");
		system("PAUSE");

	}
}


void registra_scaricamento()
{

	FILE* risorse = NULL;
	FILE* scaricamenti = NULL;
	FILE* fp_count = NULL;

	risorsa_scaricata_t risorsa_s = {0 , 0 , 0 , 0}; 		// struct d'appoggio per scorrere file scaricamenti
	risorsa_t risorsa = {0 , 0 , 0 , 0 , 0 , "" , "" ,  0};		// // struct d'appoggio per scorrere file risorse

	scaricamenti = fopen("F_SCARICAMENTI.csv" , "rb+");
	risorse = fopen("F_RISORSE.csv" , "rb+");



	if(scaricamenti == NULL || risorse == NULL)
	{
		puts(" **Errore nell'apertura del file**");
	}else{

		puts("\n\n");
		puts(" Inserisci i dati relativi lo scaricamento da registrare");

		stampa_risorse(1);
		printf(" Codice risorsa \n");
		risorsa_s.codice_risorsa = controllo_ins();

		stampa_utilizzatori(1);
		printf(" Codice utilizzatore \n");
		risorsa_s.codice_utilizzatore = controllo_ins();

		printf(" Inserisci la valutazione data alla risorsa da %d a %d \n" , MIN_VALUTAZIONE , MAX_VALUTAZIONE);

		risorsa_s.valutazione = controllo_scelta(MIN_VALUTAZIONE,MAX_VALUTAZIONE);

		risorsa_s.codice_scaricamento = conta_elementi(fp_count , "F_CONTATORE.csv" , 4);

		puts("\n");
		puts(" Inserisci la data di scaricamento");

		acquisisci_data(&risorsa_s.data_sacricamento); // controllo che la data inserita sia corretta

		fseek(scaricamenti , 0 , SEEK_END);
		fwrite( &risorsa_s , sizeof(risorsa_scaricata_t) , 1 , scaricamenti );



		fseek(risorse , (risorsa_s.codice_risorsa - 1)* sizeof(risorsa_t) , SEEK_SET);
		fread(&risorsa , sizeof(risorsa_t) , 1 , risorse);

		risorsa.conta_scar++; // incremento il numero di scarimenti nel file RISORSE

		fseek(risorse , (risorsa_s.codice_risorsa - 1)* sizeof(risorsa_t) , SEEK_SET);
		fwrite(&risorsa , sizeof(risorsa_t) , 1 , risorse);



	}
	fclose(scaricamenti);
	fclose(risorse);
	system("pause");

}



