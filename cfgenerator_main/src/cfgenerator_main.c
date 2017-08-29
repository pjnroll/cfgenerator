/*
 ============================================================================
 Name        : cfgenerator_main.c
 Author      : Gabriele Fortunato
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "intro/intro.h"
#include "get_data/get_data.h"
#include "print_result/print_result.h"
#include "repeat/repeat.h"

int main(void) {
	do{
		intro();
		char* name = get_name();
		char* surname = get_surname();
		char* birth_date= get_birth_date();
		char* birth_town = get_birth_town();
		char sex = get_sex();
		print_result(name,surname,birth_date,birth_town,sex);
	} while (repeat());
	return EXIT_SUCCESS;
}
