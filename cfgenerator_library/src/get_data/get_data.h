/*
 * get_data.h
 *
 *  Created on: 20 ago 2017
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_GET_DATA_GET_DATA_H_
#define SRC_GET_DATA_GET_DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ZERO  				0
#define MAX_LENGTH_NAME     60
#define MAX_LENGTH_SURNAME  MAX_LENGTH_NAME
#define MAX_LENGTH_TOWN     MAX_LENGTH_NAME
#define LENGTH_DATE			10
#define INSERT_NAME 		"Nome>"
#define INSERT_SURNAME 		"Cognome>"
#define INSERT_DATE 		"Data di nascita (formato GG/MM/AAAA)>"
#define INSERT_TOWN 		"Comune di nascita>"
#define INSERT_SEX 			"Sesso (M-F)>"

/**
 * Acquisisce il nome
 * @return
 */
char* get_name();

/**
 * Acquisisce il cognome
 * @return
 */
char* get_surname();

/**
 * Acquisisce la data di nascita
 * @return
 */
char* get_birth_date();

/**
 * Acquisisce il comune di nascita
 * @return
 */
char* get_birth_town();

/**
 * Acquisisce il sesso
 * @return
 */
char get_sex();

#endif /* SRC_GET_DATA_GET_DATA_H_ */
