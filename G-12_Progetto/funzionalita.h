/*
 * funzionalita.h
 *
 *  Created on: 12 mag 2020
 *       Author: Giuseppe Monitillo
 *  	 Author: Rosa Vicenti
 */

#ifndef SRC_FUNZIONALITA_H_
#define SRC_FUNZIONALITA_H_


/**
 * @file funzionalita.h
 * @brief Libreria contenente tutte funzioni e procedure che consentono di eseguire determinate
 * 		  funzionalità del programma
 */

/**
 *
 * @pre esistenza di almeno un record di tipo creatore_t nel file
 * Questa procedura serve per contare le tipologie create da uno specifico creatore,
 * del quale viene richiesto, inserendo in input il suo codice univoco
 */
void statistiche_creatore();

/**
 *
 * @pre esistenza di almeno un record di tipo ris_scaricata_t nel file
 * Procedura che serve per visualizzare le risorse più frequentemente scaricate
 * dagli utilizzatori della piattaforma, in un periodo definito dall'utente
 */
void risorse_magg_scaricate();

/**
 * Procedura per la  visualizzazione di un istogramma,
 * il quale rappresenta  quante risorse di ciascuna tipologia,
 * sono state create da uno specifico creatore
 *
 * @pre il creatore in considerazione deve essere l'autore di almeno una risorsa
 * @param conta_tipologia e un array di interi, utilizzato per contare le occorrenze di ciascuna tipologia
 *
 */
void stampa_istogramma( int conta_tipologia[]);

/** Procedura utile per la visualizzazione di un menu relativo alla scelta
 * del suggerimento risorsa che si desidera effettuare
 *
 * @pre esistenza del file con record presenti
 */
void menu_suggerimento_risorsa();

/**
 * Procedura che permette di visualizzare le risorse affini alle scelte di uno specifico utilizzatore.
 * L'utente potra' scegliere secondo quale parametro vorrebbe ricevere il suggerimeto\n
 *
 * -I criteri tra cui scegliere sono: \n
 *  -Tipologia \n
 *  -Livello Educativo\n
 *	-Disciplina 	\n
 *	-Parola Chiave\n
 *
 * @pre esistenza del file risorse e scelta di un criterio
 * @param scelta_criterio serve ad indicare in base a quale criterio ricevere il suggerimeto
 */
void suggerisci_risorsa(int scelta_criterio);


/**
 * Procedura per contare la media delle valutazioni di ciascun creatore per tutte le risorse da lui realizzate
 *
 * @pre esistenza di almeno uno scaricamento riguardante la risorsa
 */
void medie_valutazioni(creatore_t creatore);
/**
 * Funzione per efftuare la media
 * @param numero_elemeti indica il numero di elementi sui quale fare la media
 * @param somma  somma di tutti i valori per calcolare la media
 * @return
 */
float media(short int numero_elementi, float somma );


#endif /* SRC_FUNZIONALITA_H_ */
