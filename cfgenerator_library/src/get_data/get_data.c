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
		fgets(name,MAX_LENGTH_NAME,stdin);
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
		fgets(surname,MAX_LENGTH_SURNAME,stdin);
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
		fgets(date,LENGTH_DATE,stdin);
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
		fgets(town,MAX_LENGTH_TOWN,stdin);
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
