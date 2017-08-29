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
#include "read_birth_place/read_birth_place.h"
#include "print_result/print_result.h"
#include "repeat/repeat.h"

int main(void) {
	do{
		intro();
		char name[MAX_LENGTH_NAME];
		get_name(name);
		char surname[MAX_LENGTH_SURNAME];
		get_surname(surname);
		char birth_date[LENGTH_DATE];
		get_birth_date(birth_date);
		char birth_town[MAX_LENGTH_TOWN];
		get_birth_town(birth_town);
		char sex = get_sex();
		FILE* file = fopen(FILE_NAME,FILE_MODE);
		print_result(name,surname,birth_date,read_birth_place_code(file,birth_town),sex);
		fclose(file);
	} while (repeat());
	return EXIT_SUCCESS;
}
