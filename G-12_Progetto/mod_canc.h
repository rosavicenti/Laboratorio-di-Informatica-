/*
 * mod_canc.h
 *
 *  Created on: 11 mag 2020
 *       Author: Giuseppe Monitillo
 * 		 Author: Rosa Vicenti
 */

#ifndef MOD_CANC_H_
#define MOD_CANC_H_

/**
 * @file funzionalita.h
 * @brief Libreria contenente tutte funzioni e procedure che consentono di eseguire determinate
 * 		  funzionalità del programma
 */

/**
 * @file mod_canc.h
 * @brief Libreria contenente tutte funzioni e procedure che consentono modificare e cancellare
 * 		  determinati record sui file
 */

/**
 *  Consente di modificare le informazioni di una risorsa gia' presente nel FILE RISORSE \n
 *
 * @warning  Non e possibile modificare il codice della risorsa
 */
void modifica_risorsa();
/**
 *   Consente di rimuovere dal file RISORSE una risorsa il cui codice e' inserito dall'utente \n
 *
 */
void elimina_risorsa();
/**
 *   Consente di rimuovere dal file UTILIZZATORI un utilizzatore il cui codice e' inserito dall'utente \n
 *
 */

void elimina_utilizzatore();
/**
 *  Consente di modificare le informazioni di un utilizzatore  gia' presente nel file UTILIZZATORI \n
 * @warning  Non e possibile modificare il codice dell'utilizzatore
 */
void modifica_utilizzatore();

#endif /* MOD_CANC_H_ */
