/*
 * get_data.c
 *
 *  Created on: 20 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "get_data.h"

static void to_upper(char* string){
	for (int i=ZERO;i<strlen(string);i++){
		if (isalpha(string[i])){
			string[i] = toupper(string[i]);
		}
	};
}

char* get_name(){
	char* name = malloc(MAX_LENGTH_NAME*sizeof(char));
	if (name==NULL){
		return NULL;
	} else {
		printf(INSERT_NAME);
		gets(name);
		to_upper(name);
		return name;
	}
}

char* get_surname(){
	fflush(stdin);
	char* surname = malloc(MAX_LENGTH_NAME*sizeof(char));
	if (surname==NULL){
		return NULL;
	} else {
		printf(INSERT_SURNAME);
		gets(surname);
		to_upper(surname);
		return surname;
	}
}

char* get_birth_date(){
	char* date = malloc(LENGTH_DATE*sizeof(char));
	fflush(stdin);
	if (date==NULL){
		return NULL;
	} else {
		printf(INSERT_DATE);
		gets(date);
		return date;
	}
}

char* get_birth_town(){
	fflush(stdin);
	char* town = malloc(MAX_LENGTH_NAME*sizeof(char));
	if (town == NULL){
		return NULL;
	} else {
		printf(INSERT_TOWN);
		gets(town);
		to_upper(town);
		return town;
	}
}

char get_sex(){
	fflush(stdin);
	char sex='\0';
	printf(INSERT_SEX);
	scanf("%c",&sex);
	sex = toupper(sex);
	return sex;
}
