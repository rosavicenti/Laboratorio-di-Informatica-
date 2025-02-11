/*
 * funz_accessorie.h
 *
 *  Created on: 20 mag 2020
 *       Author: Giuseppe Monitillo
 *  	 Author: Rosa Vicenti
 */

#ifndef FUNZ_ACCESSORIE_H_
#define FUNZ_ACCESSORIE_H_
#include "strutture.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @file funz_accessorie.h
 * @brief Contiene tutte le procedure e funzioni, necessarie
 * 		  al fine di migliorare la leggibilità e comprensione del codice
 */

/**
 * funzione che effettua il controllo degli interi inseriti dall'utente
 * i quali prevedono un minimo numero ed un massimo numero, escludendo
 * anche valori diversi da numeri
 *
 * @param min minimo numero accettato in input
 * @param max massimo numero accettato in input
 * @return short int che definisce in numero corretto inserito dall'utente
 */
unsigned short int controllo_scelta(unsigned short int min, unsigned short int max);

/**
 * procedura utile a rendere maiuscolo il primo carattere e minuscoli gli altri
 *
 * @pre inserimento di una stringa
 * @param s stringa da formattare
 */
void formatta_stringa(char* s);

/**
 * funzione che effettua il controllo degli interi inseriti dall'utente
 * i quali prevedono non un minimo numero ed un massimo numero, escludendo
 * anche valori diversi da numeri
 *
 * @pre inserimento intero da utente
 * @return short int che definisce in numero corretto inserito dall'utente
 */
int controllo_ins();

/**
 * procedura che consente di acquisire la data tramite inserimento da tastiera
 * mediante la distinzione di anno, mese, giorno
 *
 * @param data utile al fine di modificare direttamente la struct
 */
void acquisisci_data(data_t *data);

/**
 * funzione che ricerca il massimo scaricamento tra i dati presenti all'interno di un array
 *
 * @pre presenza di un array di tipo risorsa_t
 * @param risorsa array sul quale ricercare il massimo
 * @param dim intero che definisce la dimensione dell'array
 * @return massimo scaricamento
 */
short int ricerca_max_scaricamenti(risorsa_t risorsa[], int dim);

/**
 * procedura che consente la pulizia del buffer
 *
 */
void puliscinput();

/**
 * procedura che elimina la new line presente all'intermo di una stringa di caratteri
 *
 * @esistenza di una stringa con carattere new line
 * @param s puntatore alla stringa di tipo char
 */
void elimina_new_line_terminale( char *s );

#endif /* FUNZ_ACCESSORIE_H_ */
