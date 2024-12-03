//
// Created by deddoghost on 11/6/24.
//
#include "Ceasar.h"
#include <stdio.h>
#include "encryption_options.h"

#include <stdlib.h>

int get_user_input(){

  // show user all optrions for encryption and decryption
	char user_input;
	printf("Choose one of the options below: \n");
	printf("1. Transposition Cipher\n2.Substitution Cipher\n0. For Exit");
	scanf("%c",&user_input);
        // check what option user has choosen and excute code based on user input
	switch(user_input){
		case '0':
			exit(0);
			break;
		case '1':
			printf("User choose 1\n");
            Ceasar();
			break;
		case '2':
			printf("User choose 2\n");
			break;
		default:
			printf("User entered unaveilable option\n");
			break;

	}




    return 0;
}
