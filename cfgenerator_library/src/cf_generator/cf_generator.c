/*
 * cf_generator.c
 *
 *  Created on: 21 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "cf_generator.h"

static bool is_vowel(char a){
	return (
			a=='A'||a=='E'||a=='I'||a=='O'||a=='U'
	);
}

static bool is_consonant(char a){
	return !is_vowel(a)&&isalpha(a);
}

static void get_consonants(char* string, char* consonants){
	int k = ZERO;
	for (int i=ZERO;i<strlen(string);i++){
		if (is_consonant(string[i])){
			consonants[k] = string[i];
			k++;
		}
	}
	consonants[k] = EOS;
}

static void get_vowels(char* string, char* vowels){
	int k = ZERO;
	for (int i=ZERO;i<strlen(string);i++){
		if (is_vowel(string[i])){
			vowels[k] = string[i];
			k++;
		}
	}
	vowels[k] = EOS;
}

static bool is_valid_coded_surname_name(char* code){
	bool result = true;
	if (strlen(code)!=THREE){
		result = false;
	} else {
		for (int i = ZERO;i<strlen(code);i++){
			if (!isupper(code[i])){
				result = false;
			}
		}
	}
	return result;
}

void name_code(char surname[], char code[]){
	assert(surname!=NULL);
	int length = strlen(surname);
	char consonants[length];
	get_consonants(surname,consonants);
	char vowels[length];
	get_vowels(surname,vowels);
	if (strlen(consonants) > THREE){
		code[ZERO] = consonants[ZERO];
		code[ONE] = consonants[TWO];
		code[TWO] = consonants[THREE];
	} else if (strlen(consonants) == THREE){
		code[ZERO] = consonants[ZERO];
		code[ONE] = consonants[ONE];
		code[TWO] = consonants[TWO];
	} else if (strlen(consonants) == TWO){
		if (strlen(vowels)>=ONE){
			code[ZERO] = consonants[ZERO];
			code[ONE] = consonants[ONE];
			code[TWO] = vowels[ZERO];
		} else {
			code[ZERO] = consonants[ZERO];
			code[ONE] = consonants[ONE];
			code[TWO] = X;
		}
	} else if (strlen(consonants) == ONE){
		if (strlen(vowels)>ONE){
			code[ZERO] = consonants[ZERO];
			code[ONE] = vowels[ZERO];
			code[TWO] = vowels[ONE];
		} else if (strlen(vowels)==ONE){
			code[ZERO] = consonants[ZERO];
			code[ONE] = vowels[ZERO];
			code[TWO] = X;
		} else {
			code[ZERO] = consonants[ZERO];
			code[ONE] = X;
			code[TWO] = X;
		}
	} else {
		if (strlen(vowels)>=THREE){
			code[ZERO] = vowels[ZERO];
			code[ONE] = vowels[ONE];
			code[TWO] = vowels[TWO];
		} else if (strlen(vowels)==TWO){
			code[ZERO] = vowels[ZERO];
			code[ONE] = vowels[ONE];
			code[TWO] = X;
		} else if (strlen(vowels)==ONE){
			code[ZERO] = vowels[ZERO];
			code[ONE] = X;
			code[TWO] = X;
		} else {
			code[ZERO] = X;
			code[ONE] = X;
			code[TWO] = X;
		}
	}
	code[THREE] = EOS;
	assert(is_valid_coded_surname_name(code));
}

void surname_code(char surname[], char code[]){
	assert(surname!=NULL);
	char consonants[strlen(surname)];
	get_consonants(surname,consonants);
	char vowels[strlen(surname)];
	get_vowels(surname,vowels);
	if (strlen(consonants) >= THREE){
		code[ZERO] = consonants[ZERO];
		code[ONE] = consonants[ONE];
		code[TWO] = consonants[TWO];
	} else if (strlen(consonants) == TWO){
		if (strlen(vowels)>=ONE){
			code[ZERO] = consonants[ZERO];
			code[ONE] = consonants[ONE];
			code[TWO] = vowels[ZERO];
		} else {
			code[ZERO] = consonants[ZERO];
			code[ONE] = consonants[ONE];
			code[TWO] = X;
		}
	} else if (strlen(consonants) == ONE){
		if (strlen(vowels)>ONE){
			code[ZERO] = consonants[ZERO];
			code[ONE] = vowels[ZERO];
			code[TWO] = vowels[ONE];
		} else if (strlen(vowels)==ONE){
			code[ZERO] = consonants[ZERO];
			code[ONE] = vowels[ZERO];
			code[TWO] = X;
		} else {
			code[ZERO] = consonants[ZERO];
			code[ONE] = X;
			code[TWO] = X;
		}
	} else {
		if (strlen(vowels)>=THREE){
			code[ZERO] = vowels[ZERO];
			code[ONE] = vowels[ONE];
			code[TWO] = vowels[TWO];
		} else if (strlen(vowels)==TWO){
			code[ZERO] = vowels[ZERO];
			code[ONE] = vowels[ONE];
			code[TWO] = X;
		} else if (strlen(vowels)==ONE){
			code[ZERO] = vowels[ZERO];
			code[ONE] = X;
			code[TWO] = X;
		} else {
			code[ZERO] = X;
			code[ONE] = X;
			code[TWO] = X;
		}
	}
	code[THREE] = EOS;
	assert(is_valid_coded_surname_name(code));
}

static int number(char a, char b){
	return TEN*(a-ASCII)+(b-ASCII);
}

static int number_a(char a, char b, char c, char d){
	return TEN*TEN*TEN*(a-ASCII)+TEN*TEN*(b-ASCII)+TEN*(c-ASCII)+(d-ASCII);
}

static bool is_valid_date(char* date){
	bool result = true;
	if (strlen(date) != TEN) {
		result = false;
	} else {
		for (int i = ZERO; i<strlen(date); i++){
			if (i==TWO ||i==FIVE){
				if (date[i]!='/'){
					result = false;
				}
			} else if (!isdigit(date[i])){
				result = false;
			}
		}
	}
	if (number(date[ZERO],date[ONE])==ZERO&&number(date[ZERO],date[ONE])>THIRTYONE){
		result = false;
	}
	if (number(date[THREE],date[FOUR])==ZERO&&number(date[THREE],date[FOUR])>TWELVE){
		result = false;
	}
	if (number(date[THREE],date[FOUR])==ZERO&&number(date[THREE],date[FOUR])>TWELVE){
		result = false;
	}
	if (
			number_a(date[SEVEN],date[EIGHT],date[NINE],date[TEN])<MIN_YEAR&&
			number_a(date[SEVEN],date[EIGHT],date[NINE],date[TEN])>MAX_YEAR
	){
		result = false;
	}
	return result;
}

static bool is_valid_sex(char sex){
	return (sex=='M'||sex=='F');
}

static char month(char a, char b){
	char result;
	if (a=='0'){
		if (b == '1'){
			result = 'A';
		} else if (b == '2'){
			result = 'B';
		} else if (b == '3'){
			result = 'C';
		} else if (b == '4'){
			result = 'D';
		} else if (b == '5'){
			result = 'E';
		} else if (b == '6'){
			result = 'H';
		} else if (b == '7'){
			result = 'L';
		} else if (b == '8'){
			result = 'M';
		} else if (b == '9'){
			result = 'P';
		}
	} else {
		if (b == '0'){
			result = 'R';
		} else if (b == '1'){
			result = 'S';
		} else {
			result = 'T';
		}
	}
	return result;
}

void birth_date_code(char date[], char sex, char code[]){
	assert(is_valid_date(date));
	assert(is_valid_sex(sex));
	code[ZERO] = date[EIGHT];
	code[ONE] = date[NINE];
	code[TWO] = month(date[THREE],date[FOUR]);
	code[THREE] = date[ZERO];
	if (sex == 'F'){
		code[THREE] = code[THREE] + FOUR;
	}
	code[FOUR] = date[ONE];
	code[FIVE] = EOS;
	assert(strlen(code)==FIVE);
}

static int even_character(char a){
	int result=EOS;
	switch(a){
	case '0': result = 1; break;
	case '1': result = 0; break;
	case '2': result = 5; break;
	case '3': result = 7; break;
	case '4': result = 9; break;
	case '5': result = 13; break;
	case '6': result = 15; break;
	case '7': result = 17; break;
	case '8': result = 19; break;
	case '9': result = 21; break;
	case 'A': result = 1; break;
	case 'B': result = 0; break;
	case 'C': result = 5; break;
	case 'D': result = 7; break;
	case 'E': result = 9; break;
	case 'F': result = 13; break;
	case 'G': result = 15; break;
	case 'H': result = 17; break;
	case 'I': result = 19; break;
	case 'J': result = 21; break;
	case 'K': result = 2; break;
	case 'L': result = 4; break;
	case 'M': result = 18; break;
	case 'N': result = 20; break;
	case 'O': result = 11; break;
	case 'P': result = 3; break;
	case 'Q': result = 6; break;
	case 'R': result = 8; break;
	case 'S': result = 12; break;
	case 'T': result = 14; break;
	case 'U': result = 16; break;
	case 'V': result = 10; break;
	case 'W': result = 22; break;
	case 'X': result = 25; break;
	case 'Y': result = 24; break;
	case 'Z': result = 23; break;
	}
	return result;
}

static int odd_character(char a){
	int result=EOS;
	switch(a){
	case '0': result = 0; break;
	case '1': result = 1; break;
	case '2': result = 2; break;
	case '3': result = 3; break;
	case '4': result = 4; break;
	case '5': result = 5; break;
	case '6': result = 6; break;
	case '7': result = 7; break;
	case '8': result = 8; break;
	case '9': result = 9; break;
	case 'A': result = 0; break;
	case 'B': result = 1; break;
	case 'C': result = 2; break;
	case 'D': result = 3; break;
	case 'E': result = 4; break;
	case 'F': result = 5; break;
	case 'G': result = 6; break;
	case 'H': result = 7; break;
	case 'I': result = 8; break;
	case 'J': result = 9; break;
	case 'K': result = 10; break;
	case 'L': result = 11; break;
	case 'M': result = 12; break;
	case 'N': result = 13; break;
	case 'O': result = 14; break;
	case 'P': result = 15; break;
	case 'Q': result = 16; break;
	case 'R': result = 17; break;
	case 'S': result = 18; break;
	case 'T': result = 19; break;
	case 'U': result = 20; break;
	case 'V': result = 21; break;
	case 'W': result = 22; break;
	case 'X': result = 23; break;
	case 'Y': result = 24; break;
	case 'Z': result = 25; break;
	}
	return result;
}

static char result(int number){
	int result=EOS;
	switch(number){
	case 0:  result = 'A'; break;
	case 1:  result = 'B'; break;
	case 2:  result = 'C'; break;
	case 3:  result = 'D'; break;
	case 4:  result = 'E'; break;
	case 5:  result = 'F'; break;
	case 6:  result = 'G'; break;
	case 7:  result = 'H'; break;
	case 8:  result = 'I'; break;
	case 9:  result = 'J'; break;
	case 10: result = 'K'; break;
	case 11: result = 'L'; break;
	case 12: result = 'M'; break;
	case 13: result = 'N'; break;
	case 14: result = 'O'; break;
	case 15: result = 'P'; break;
	case 16: result = 'Q'; break;
	case 17: result = 'R'; break;
	case 18: result = 'S'; break;
	case 19: result = 'T'; break;
	case 20: result = 'U'; break;
	case 21: result = 'V'; break;
	case 22: result = 'W'; break;
	case 23: result = 'X'; break;
	case 24: result = 'Y'; break;
	case 25: result = 'Z'; break;
	}
	return result;
}

char ctrl_code(char coded_name[], char coded_surname[], char coded_birth_date[], char coded_birth_place[]){
	int number = ZERO;
	char code[15];
	code[0]=coded_surname[0];
	code[1]=coded_surname[1];
	code[2]=coded_surname[2];
	code[3]=coded_name[0];
	code[4]=coded_name[1];
	code[5]=coded_name[2];
	code[6]=coded_birth_date[0];
	code[7]=coded_birth_date[1];
	code[8]=coded_birth_date[2];
	code[9]=coded_birth_date[3];
	code[10]=coded_birth_date[4];
	code[11]=coded_birth_place[0];
	code[12]=coded_birth_place[1];
	code[13]=coded_birth_place[2];
	code[14]=coded_birth_place[3];
	code[15]=EOS;
	for (int i=ZERO;i<strlen(code)-ONE;i++){
		if (i%TWO==ZERO){
			number += even_character(code[i]);
		} else {
			number += odd_character(code[i]);
		}
	}
	return result(number%26);
}

void cf_generator(
		char name[], char surname[], char birth_date[], char coded_town[], char sex, char code[]
		){
	char coded_surname[4];
	char coded_name[4];
	char coded_birth_date[6];
	surname_code(surname,coded_surname);
	code[0] = coded_surname[0];
	code[1] = coded_surname[1];
	code[2] = coded_surname[2];
	name_code(name,coded_name);
	code[3] = coded_name[0];
	code[4] = coded_name[1];
	code[5] = coded_name[2];
	birth_date_code(birth_date,sex,coded_birth_date);
	code[6] = coded_birth_date[0];
	code[7] = coded_birth_date[1];
	code[8] = coded_birth_date[2];
	code[9] = coded_birth_date[3];
	code[10] = coded_birth_date[4];
	code[11] = coded_town[0];
	code[12] = coded_town[1];
	code[13] = coded_town[2];
	code[14] = coded_town[3];
	code[15] = ctrl_code(coded_name,coded_surname,coded_birth_date,coded_town);
	code[16] = EOS;
}
