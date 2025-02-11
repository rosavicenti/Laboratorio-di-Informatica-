/*
 * visualizza.h
 *
 *  Created on: 8 mag 2020
 *       Author: Giuseppe Monitillo
 *  	 Author: Rosa Vicenti
 */

#ifndef VISUALIZZA_H_
#define VISUALIZZA_H_

/**
 * @file visualizza.h
 * @brief Contiene tutte le procedure e funzioni utili per la
 * visualizzazione su schermo
 */

/**
 * procedura utilizzata per la stampa della disciplina
 * relativa alla risorsa mediante un itero inserito dall'utente
 *
 * @pre esistenza del file
 *
 * @param disciplina intero utile per selezionare la stringa di caratteri da stampare
 */
void stampa_disciplina (unsigned short int disciplina);

/**
 * procedura utilizzata per la stampa del livello educativo
 * relativo la risorsa mediante un itero inserito dall'utente
 *
 * @pre esistenza del file
 *
 * @param livello_ed intero utile per selezionare la stringa di caratteri da stampare
 */
void stampa_livello_ed (unsigned short int livello_ed);

/**
 * procedura utilizzata per la stampa della tipologia
 * relativa la risorsa mediante un itero inserito dall'utente
 *
 * @pre esistenza del file
 *
 * @param tipologia intero utile per selezionare la stringa di caratteri da stampare
 */
void stampa_tipologia(unsigned short int tipologia);

/**
 * procedura che effettua la stampa dell'elenco degli utilizzatori delle
 * risorse, il quale è presente nel file F_UTILIZZATORI.csv
 *
 *@pre esistenza del file
 * @param select intero utile al fine di implementare o meno la pausa nel codice
 */
void stampa_utilizzatori(int select);

/**
 *
 * procedura che effettua la stampa dell'elenco delle
 * risorse, il quale è presente nel file F_RISORSE.csv
 *
 * @pre esistenza del file
 *
 * @param select intero utile al fine di implementare o meno la pausa nel codice
 */
void stampa_risorse(int select);

/**
 * procedura che effettua la stampa dell'elenco dei creatori delle
 * risorse, il quale è presente nel file F_CREATORI.csv
 *
 *@pre esistenza del file
 * @param select intero utile al fine di implementare o meno la pausa nel codice
 */
void stampa_creatori(int select);


#endif /* VISUALIZZA_H_ */
