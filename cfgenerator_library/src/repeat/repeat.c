/*
 * repeat.c
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "repeat.h"

static int get_repeat(){
	int repeat=0;
	do{
		printf(
				"\nCalcolare un altro codice fiscale?\n"
				"(1=si,2=no) "
		);
		scanf("%d",&repeat);
	} while(repeat!=1&&repeat!=2);
	return repeat;
}

bool repeat(){
	return get_repeat()==1;
}
