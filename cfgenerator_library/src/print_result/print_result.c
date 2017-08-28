/*
 * print_result.c
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "print_result.h"

void print_result(char* name, char* surname, char* date, char* code_town, char sex){
	char code[17];
	cf_generator(name,surname,date,code_town,sex,code);
	printf(
			"\n"
			"================================\n"
			"Codice fiscale: %s\n"
			"================================\n"
			,code);
}
