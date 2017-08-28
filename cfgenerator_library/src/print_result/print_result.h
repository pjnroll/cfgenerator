/*
 * print_result.h
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_PRINT_RESULT_PRINT_RESULT_H_
#define SRC_PRINT_RESULT_PRINT_RESULT_H_

#include <stdio.h>
#include "cf_generator/cf_generator.h"

/**
 * Stampa a video il codice generato
 * @param name
 * @param surname
 * @param date
 * @param code_town
 * @param sex
 */
void print_result(char* name, char* surname, char* date, char* code_town, char sex);

#endif /* SRC_PRINT_RESULT_PRINT_RESULT_H_ */
