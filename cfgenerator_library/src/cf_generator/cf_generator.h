/*
 * cf_generator.h
 *
 *  Created on: 21 ago 2017
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_CF_GENERATOR_CF_GENERATOR_H_
#define SRC_CF_GENERATOR_CF_GENERATOR_H_

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "read_birth_place/read_birth_place.h"

#define ZERO  		  0
#define ONE   		  1
#define TWO	  	      2
#define THREE 		  3
#define FOUR  		  4
#define FIVE  		  5
#define SIX  		  6
#define SEVEN   	  7
#define EIGHT   	  8
#define NINE   	      9
#define TEN   	     10
#define ELEVEN   	 11
#define TWELVE       12
#define THIRTEEN   	 13
#define FOURTEEN  	 14
#define FIFTEEN   	 15
#define SIXTEEN   	 16
#define SEVENTEEN    17
#define EIGHTEEN   	 18
#define NINETEEN   	 19
#define TWENTY   	 20
#define TWENTYONE    21
#define TWENTYTWO    22
#define TWENTYTHREE  23
#define TWENTYFOUR   24
#define TWENTYFIVE   25
#define TWENTYSIX    26
#define THIRTYONE    31
#define ASCII 	     46
#define MIN_YEAR   1900
#define MAX_YEAR   2017
#define ASCII 	     46
#define FILE_NAME  "comuni.csv"
#define FILE_MODE  "r"
#define ASCII 	     46
#define EOS   	   '\0';
#define SEX  	   '\F';
#define X      	    'X';

/**
 * Codifica il nome
 * @pre la stringa del nome non deve essere vuota
 * @post il nome codificato deve essere una stringa di tre lettere
 * @param name
 * @param code
 * @return
 */
void name_code(char name[], char* code);

/**
 * Codifica il cognome
 * @pre la stringa del cognome non deve essere vuota
 * @post il cognome codificato deve essere una stringa di tre
  @return
 */
void surname_code(char surname[], char* code);

/**
 * Codifica la data di nascita
 * La data deve essere una stringa avente formato GG/MM/AAAA
 * @post la data codificata deve essere una stringa di quattro caratteri
 * @param date
 * @param sex
 * @param code
 * @return
 */
void birth_date_code(char date[], char sex, char code[]);

/**
 * Genera il carattere di controllo
 * @param name
 * @param surname
 * @param town
 * @param date
 * @return
 */
char ctrl_code(char coded_name[], char coded_surname[], char coded_birth_date[], char coded_birth_place[]);

/**
 * Genera il codice fiscale
 * @param name
 * @param surname
 * @param birth_date
 * @param birth_town
 * @return
 */
void cf_generator(char name[], char surname[], char birth_date[], char birth_town[], char sex, char code[]);

#endif /* SRC_CF_GENERATOR_CF_GENERATOR_H_ */
