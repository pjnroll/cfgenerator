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
	gets(name);
	name = to_upper(name);
}

void get_surname(char* surname){
	fflush(stdin);
	printf(INSERT_SURNAME);
	gets(surname);
	surname = to_upper(surname);
}

void get_birth_date(char* date){
	fflush(stdin);
	printf(INSERT_DATE);
	gets(date);
}

void get_birth_town(char* town){
	fflush(stdin);
	printf(INSERT_TOWN);
	gets(town);
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
