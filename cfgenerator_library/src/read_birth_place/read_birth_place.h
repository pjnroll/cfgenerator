/*
 * read_birth_place.h
 *
 *  Created on: 21 ago 2017
 *      Author: gabriele
 */

#ifndef SRC_READ_BIRTH_PLACE_READ_BIRTH_PLACE_H_
#define SRC_READ_BIRTH_PLACE_READ_BIRTH_PLACE_H_

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME  "comuni.csv"
#define FILE_MODE  "r"
#define ZERO       0
#define FOUR       4
#define STRLEN     50

/**
 * Legge da file il codice catastale del comune di nascita
 * @pre il file deve essere aperto
 * @post il codice risultante deve essere una stringa di 4 caratteri
 *       di cui la prima una lettera e gli altri cifre
 * @param places_file
 * @param birth_place
 * @return
 */
char* read_birth_place_code(FILE* places_file,char* birth_place);

#endif /* SRC_READ_BIRTH_PLACE_READ_BIRTH_PLACE_H_ */
