/*
 ============================================================================
 Name        : cfgenerator_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <CUnit/basic.h>
#include "read_birth_place/read_birth_place.h"
#include "cf_generator/cf_generator.h"

int init_suite_default(){
	return 0;
}

int clear_suite_default(){
	return 0;
}

void test_birth_date_code(){
	char code[4];
	birth_date_code("02/10/1978",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"78R42");
	birth_date_code("02/10/1978",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"78R02");
	birth_date_code("17/05/1975",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"75E57");
	birth_date_code("15/04/1951",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"51D15");
}

void test_ctrl_code(){
	CU_ASSERT_EQUAL(ctrl_code("FNC","FRT","51D15","A662"),'C');
	CU_ASSERT_EQUAL(ctrl_code("NNA","MNN","75E57","A662"),'H');
	CU_ASSERT_EQUAL(ctrl_code("GRL","FRT","78R02","F280"),'W');
}

void test_code_town(){
	FILE* file = fopen("comuni.csv","r");
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"ALBIANO D'IVREA"), "A157");
	fclose(file);
	file = fopen("comuni.csv","r");
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"MOLA DI BARI"), "F280");
	fclose(file);
	file = fopen("comuni.csv","r");
	CU_ASSERT_STRING_EQUAL(read_birth_place_code(file,"BARI"), "A662");
	fclose(file);
}

void test_name_code(){
	char code[4];
	name_code("GABRIELE",code);
	CU_ASSERT_STRING_EQUAL(code,"GRL");
}

void test_surname_code(){
	char code[4];
	surname_code("FORTUNATO",code);
	puts(code);
	CU_ASSERT_STRING_EQUAL(code,"FRT");
}

void test_cf_generator(){
	char code[17];
	cf_generator("ANNA","DIANA","21/11/1920","A662",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"DNINNA20S61A662R");
	cf_generator("GABRIELE","FORTUNATO","02/10/1978","F280",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"FRTGRL78R02F280W");
	cf_generator("ANNA","MONNO","17/05/1975","A662",'F',code);
	CU_ASSERT_STRING_EQUAL(code,"MNNNNA75E57A662H");
	cf_generator("FRANCESCO","FORTUNATO","15/04/1951","A662",'M',code);
	CU_ASSERT_STRING_EQUAL(code,"FRTFNC51D15A662C");
}

int main(void) {
	CU_initialize_registry();
	CU_pSuite pSuite_A = CU_add_suite("SUITE CODE TOWN",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_A,"test of get_ISTAT_code()",test_code_town);
	CU_pSuite pSuite_B = CU_add_suite("SUITE CF_GENERATOR_A",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_B,"test of name_code()",test_name_code);
	CU_add_test(pSuite_B,"test of surname_code()",test_surname_code);
	CU_add_test(pSuite_B,"test of birth_date_code()",test_birth_date_code);
	CU_add_test(pSuite_B,"test of ctrl_code()",test_ctrl_code);
	CU_pSuite pSuite_C = CU_add_suite("CF_GENERATOR_B",init_suite_default,clear_suite_default);
	CU_add_test(pSuite_C,"test of cf_generator()",test_cf_generator);
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
