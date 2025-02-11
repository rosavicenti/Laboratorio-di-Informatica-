/*
 * strutture.h
 *
 *  Created on: 2 mag 2020
 *       Author: Giuseppe Monitillo
 * 		 Author: Rosa Vicenti
 */

#ifndef STRUTTURE_H_
#define STRUTTURE_H_
/**
 * @file strutture.h
 * @brief Libreria contenente tutte le struct utili alla gestione dei dati
 */

/// Lunghezza massima della stringa Nome
#define LUNGH_NOME 20
/// Lunghezza massima della stringa Cognome
#define LUNGH_COGNOME 20
/// Lunghezza massima del Titolo
#define LUNGH_TITOLO 20
///  Lunghezza massima della Parola chiave
#define LUNGH_PAROLA_CHIAVE 10
/// Numero massimo di scaricamenti necessario per la funzione visualizza le risorse più scaricate
#define MAX_SCARICAMENTI 4
///età minima dell'utilizzatore
#define MIN_ETA_UTILIZZATORE 3
///età minima dell'utilizzatore
#define MAX_ETA_UTILIZZATORE 130
///età minima delcreatore
#define MIN_ETA_CREATORE 18
///età massima del creatore
#define MAX_ETA_CREATORE 130
///numero di tipologie delle risorse
#define NUM_TIPOLOGIE 3
///numero di discipline delle risorse
#define NUM_DISCIPLINE 5
///numero di livelli educativi
#define NUM_LIVELLO_ED 4
///valutazione minima della risorsa
#define MIN_VALUTAZIONE 0
///valutazione massima della risorsa
#define MAX_VALUTAZIONE 5

/**
 * Tipo data
 * Utile per memorizzare una data in formato GG/MM/AA
 */
typedef struct{
/// variabile che indica il giorno
	unsigned short int giorno;
	/// variabile che indica il mese
	unsigned short int mese;
	/// variabile che indica l'anno
	unsigned short int anno;

}data_t;
/**
 * Tipo Risorse scaricate
 * Utile per tracciare le abitudini degli utilizzatori.
 * Ad ogni scaricamento effettuato tengo traccia della valutazione fatta dall'utilizzatore
 *  e della data in cui � stata scaricata
 */
typedef struct {
///codice univoco dello scaricamento
 short int codice_scaricamento;
 /// codice univoco della risorsa
 short int codice_risorsa;
 /// codice univoco dell'utilizzatore
 short int codice_utilizzatore;
 /// Valutazione fatta dall'utilizzatore sulla risorsa
 short int valutazione; // da 0 a 5
/// Data in cui � stato effettuato lo scaricamento
 data_t data_sacricamento;

	}risorsa_scaricata_t;

	/**
	 * Tipo Risorsa
	 * Contiente tutte le informazioni relative alla risorsa
	 */
typedef struct {
	///Codice univoco della risorsa
     short int codice_risorsa;
     /// codice univoco del creatore
     short int codice_creatore;
/// Indica la tipologia della risorsa
	 unsigned short int livello_ed_risorsa;
	 /// indica la disciplina della risorsa
	 unsigned short int disciplina;
	 /// indica la tipologia della risorsa
	 unsigned short int tipologia;
	 ///Indica il Titolo della risorsa
     char titolo[LUNGH_TITOLO];
     /// Indica la parola chiave della risorsa
	 char parola_chiave[15];
	 /// Conta il numero di volte che una risorsa viene scaricata da un utilizzatore
	 short int conta_scar;


	} risorsa_t;
/**
 * Tipo creatore
 * Contiente tutte le informazioni relative al creatore della risorsa
 */
typedef struct {
	/// codice univoco del creatore
	short int codice_creatore; // 3 caratteri
	/// indica il nome del creatore
    char nome_creatore[LUNGH_NOME];
    /// indica il cognome del creatore
    char cognome_creatore[LUNGH_COGNOME];
    /// Indica l'et� del creatore
    unsigned short int eta_creatore;
    /// Indica la disciplina del creatore
    unsigned short int disciplina_creatore;
    /// Indica il livello educativo del creatore
    unsigned short int livello_ed_creatore;

	} creatore_t;


	/**
	 * Tipo utilizzatore
	 * Contiente tutte le informazioni relative all'utilizzatore della piattaforma
	 */
typedef struct {
	/// codice univoco dell'utilizzatore
    short int codice_utilizzatore;
    /// Nome dell'utilizzatore
    char nome_utilizzatore[LUNGH_NOME];
    /// Cognome dell'utilizzatore
    char cognome_utilizzatore [LUNGH_COGNOME];
    /// Eta dell'utilizzatore
    unsigned short int eta_utilizzatore;
    /// Disciplina dell'utilizzatore
    unsigned short int disciplina_utilizzatore;
    /// Livello educativo dell'utilizzatore
    unsigned short int livello_ed_utilizzatore;

	} utilizzatore_t;



#endif /* STRUTTURE_H_ */
