/*
 * read_birth_place.c
 *
 *  Created on: 21 ago 2017
 *      Author: gabriele
 */

#include "read_birth_place.h"

static bool is_valid_code(char* code){
	bool result = true;
	if (strlen(code)!=4){
		result = false;
	} else {
		for (int i=0;i<strlen(code);i++){
			if (i==0){
				if (!isupper(code[i])){
					result = false;
				}
			} else {
				if (!isdigit(code[i])){
					result = false;
				}
			}
		}
	}
	return result;
}

char* read_birth_place_code(FILE* places_file,char* birth_place){
	assert(places_file!=NULL);
	char* string = (char*) malloc(sizeof(char)*STRLEN);
	int c;
	char* town = (char*) malloc(sizeof(char)*50);
	char* code = (char*) malloc(sizeof(char)*5);
	char* result = (char*) malloc(sizeof(char)*5);
	bool found = false;
	while((c = fgetc(places_file)) != EOF){
		ungetc(c, places_file);
		fgets(string, 100, places_file);
		town = strtok(string, ",");
			code = strtok(NULL, ",");

		if((strcmp(birth_place, town)) == 0){
			strcpy(result, code);
			found = true;
			break;
		}
	}
	if (found == false)
		result = NULL;
	strtok(result, "\n");
	assert(is_valid_code(result));
	return result;
}
