/*
 * get_data.c
 *
 *  Created on: 20 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "get_data.h"

static char* to_upper(char* string){
	for (int i=ZERO;i<strlen(string);i++){
		if (isalpha(string[i])){
			string[i] = toupper(string[i]);
		}
	}
	return string;
}

char* get_name(){
	fflush(stdin);
	char* name=malloc(MAX_LENGTH_NAME*sizeof(char));
	if (name==NULL){
		printf("Impossibile inserire il nome");
	} else {
		name = to_upper(name);
		printf(INSERT_NAME);
		gets(name);
		name = to_upper(name);
	}
	return name;
}

char* get_surname(){
	fflush(stdin);
	char* surname=malloc(MAX_LENGTH_SURNAME*sizeof(char));
	if (surname==NULL){
		printf("Impossibile inserire il cognome");
	} else {
		printf(INSERT_SURNAME);
		gets(surname);
		surname = to_upper(surname);
	}
	return surname;
}

char* get_birth_date(){
	fflush(stdin);
	char* date=malloc(LENGTH_DATE*sizeof(char));
	if (date==NULL){
		printf("Impossibile inserire la data di nascita");
	} else {
		printf(INSERT_DATE);
		gets(date);
	}
	return date;
}

char* get_birth_town(){
	fflush(stdin);
	char* town=malloc(MAX_LENGTH_TOWN*sizeof(char));
	if (town==NULL){
		printf("Impossibile inserire il comune di nascita");
	} else {
		printf(INSERT_TOWN);
		gets(town);
		town = to_upper(town);
	}
	return town;
}

char get_sex(){
	fflush(stdin);
	char sex='\0';
	printf(INSERT_SEX);
	scanf("%c",&sex);
	sex = toupper(sex);
	return sex;
}
