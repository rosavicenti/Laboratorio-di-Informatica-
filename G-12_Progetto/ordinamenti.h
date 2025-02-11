/*
 * ordinamenti.h
 *
 *  Created on: 14 mag 2020
 *       Author: Giuseppe Monitillo
 *  	 Author: Rosa Vicenti
 */

#ifndef ORDINAMENTI_H_
#define ORDINAMENTI_H_

/**
 * @file ordinamenti.h
 * @brief Libreria contenente tutte funzioni e procedure che consentono di ordinare i file in base a determinati criteri
 */

/**
 * Permette la visualizzazione di un menu nel quale e' possibile  selezionare un criterio per l'ordinamento dell'utilizzatore. \n
 *  I possibili criteri sono: eta', cognome, nome e codice dell'utilizzatore.
 *
 */
void menu_ordina_utilizzatori();
/**
 *  Consente di effetture l'ordinamento degli utilizzatori mediante Selection Sort sul file Utilizzatori
 * @param utilizzatori puntatore del file utilizzatori, aperto in menu_ordina_utilizzatori()
 * @param scelta_criterio utile per capire quale criterio di ordinamento è stato scelto in menu_ordina_utilizzatori()
 */
void ordina_utilizzatori(FILE *utilizzatori,int scelta_criterio);

/**
 * Procedura utile nel Selection Sort per effettuare lo scambio degli utilizzatori
 *
 * @pre esistenza di almeno due utilizzatori
 *
 * @param tempi struct d'appoggio utilizzata per conservare il record in posizione i durante lo scambio
 * @param temp3 struct d'appoggio utilizzata per conservare il valore del minimo durante lo scambio
 * @param i  indice del Selection Sort, utile per conservare la posizione del minimo
 * @param p variabile di tipo intero utilizzata per conservare la posizione in cui si trovava il valore minimo
 * @param utilizzatori puntatore del file utilizzatori, aperto in menu_ordina_utilizzatori()
 *
 *  @pre esistenza di almeno due utilizzatori
 */
void scambia_utilizzatori(utilizzatore_t tempi, utilizzatore_t temp3, int i,int p, FILE *utilizzatori);
/**
 * Permette la visualizzazione di un menu nel quale e' possibile selezionare un criterio per l'ordinamento del creatore \n
 *  I possibili criteri sono: eta', cognome, nome e codice del creatore.
 *
 */
void menu_ordina_creatori();
/**
 *  Consente di effetture l'ordinamento dei creatori mediante Selection Sort sul file Creatori
 *
 * @param  creatori puntatore del file creatori, aperto in menu_ordina_creatori()
 * @param scelta_criterio utile per capire quale criterio  di ordinamento è stato scelto in menu_ordina_creatori()
 */

void ordina_creatori(FILE *creatori,int scelta_criterio);
/**
 *
 * Procedura utile nel Selection Sort per effettuare lo scambio dei creatori
 * @param tempi struct d'appoggio utilizzata per conservare il record in posizione i durante lo scambio
 * @param temp3 struct d'appoggio utilizzata per conservare il valore del minimo durante lo scambio
 * @param i  indice del Selection Sort, utile per conservare la posizione del minimo
 * @param p variabile di tipo intero utilizzata per conservare la posizione in cui si trovava il valore minimo
 * @param creatori  puntatore del file creatori, aperto in menu_ordina_creatori()
 *
 *
 *  @pre esistenza di almeno due creatori
 */
void scambia_creatori(creatore_t tempi, creatore_t temp3, int i,int p, FILE *creatori);

/**
 * Permette la visualizzazione di un menu nel quale e' possibile  selezionare un criterio
 * per l'ordinamento del file RISORSE.
 * I criteri possibili sono:  risorse piu' scaricate, Titolo, parola chiave e codice risorsa.
 *
 *  @pre esistenza di almeno due creatori
 */
void menu_ordina_risorse();
/**
 *  Consente di effetture l'ordinamento dei creatori mediante Selection Sort sul file RISORSE
 * @param risorse puntatore del file risorse, aperto in menu_ordina_risorse()
 * @param scelta_criterio utile per capire quale criterio  di ordinamento è stato scelto in menu_ordina_risorse()
 *  @pre esistenza di almeno due creatori
 */
void ordina_risorse(FILE *risorse, int scelta_criterio);
/**
 *  Procedura utile nel Selection Sort per effettuare lo scambio dei creatori
 * @param tempi struct d'appoggio utilizzata per conservare il record in posizione i durante lo scambio
 * @param temp3 struct d'appoggio utilizzata per conservare il valore del minimo durante lo scambio
 * @param i  indice del Selection Sort, utile per conservare la posizione del minimo
 * @param p variabile di tipo intero utilizzata per conservare la posizione in cui si trovava il valore minimo
 * @param risorse puntatore del file risorse, aperto in menu_ordina_risorse()
 *
 *  @pre esistenza di almeno due risorse
 */
void scambia_risorse(risorsa_t tempi, risorsa_t temp3, int i,int p, FILE *risorse) ;

#endif /* ORDINAMENTI_H_ */
