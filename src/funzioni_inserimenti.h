/*
 * funzioni_inserimenti.h
 *
 *  Created on: 8 mag 2020
 *      	 Author: Giuseppe Monitillo
 *  		 Author: Rosa Vicenti
 */

#ifndef FUNZIONI_INSERIMENTI_H_
#define FUNZIONI_INSERIMENTI_H_

#include <stdio.h>

/**
 * @file funzioni_inserimenti.h
 * @brief Libreria contenente tutte funzioni utili a caricare dati sui file
 */

/**
 * @pre esistenza del file
 * procedura necessaria al fine di inserire un utilizzatore nel sistema, ossia un record nel file F_UTILIZZATORI.csv
 */
void ins_utilizzatore();

/**
 * @pre esistenza del file
 * procedura necessaria al fine di inserire una risorsa nel sistema, ossia un record nel file F_RISORSE.csv
 */
void ins_risorsa();

/**
 * @pre esistenza del file
 * procedura necessaria al fine di inserire uno scaricamento nel sistema, ossia un record nel file F_SCARICAMENTI.csv
 */
void registra_scaricamento();


/**
 * procedura utile al fine di inserire un creatore, ossia un record nel file F_CREATORI.csv
 *
 * @pre esistenza del file
 * @param codice
 */
void ins_creatore(short int* codice);

/**
 * funzione utile per ricercare un determinato creatore mediante nome e cognome, impiegata per verificare se
 * al momento dell'inserimento di una risorsa il rispettivo creatore esiste o meno nel sistema
 *
 * @param codice intero che definisce il codice del creatore da ricercare
 * @return intero che determina se il creatore è presente o meno nel file
 * @return 1 se il creatore è presente nel file
 * @return 0 se non è presente
 */
void ricerca_creatore(short int* codice);

/**
 * funzione utile per tenere traccia del numero di record presenti nei file utili per il programma,
 * ossia (file creatori, risorse, utilizzatori, scaricamenti), utile in particolar modo per il codice
 * identificativo degli oggetti
 *
 * @param file puntatore al file
 * @param nome nome identificativo del file
 * @param num intero utile al fine di selezionare un particolare blocco del file puntato
 * @return intero che rappresenta il la posizione dell'ultimo elemento del file considerato
 */
int conta_elementi(FILE* file , const char* nome , int num);


#endif /* FUNZIONI_INSERIMENTI_H_ */
