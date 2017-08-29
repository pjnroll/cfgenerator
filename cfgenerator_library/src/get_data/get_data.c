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

void get_name(char* name){
	name = to_upper(name);
	printf(INSERT_NAME);
	fgets(name,MAX_LENGTH_NAME,stdin);
	name = to_upper(name);
}

void get_surname(char* surname){
	fflush(stdin);
	printf(INSERT_SURNAME);
	fgets(surname,MAX_LENGTH_SURNAME,stdin);
	surname = to_upper(surname);
}

void get_birth_date(char* date){
	fflush(stdin);
	printf(INSERT_DATE);
	fgets(date,LENGTH_DATE,stdin);
}

void get_birth_town(char* town){
	fflush(stdin);
	printf(INSERT_TOWN);
	fgets(town,MAX_LENGTH_TOWN,stdin);
	town = to_upper(town);
}

char get_sex(){
	fflush(stdin);
	char sex='\0';
	printf(INSERT_SEX);
	scanf("%c",&sex);
	sex = toupper(sex);
	return sex;
}
