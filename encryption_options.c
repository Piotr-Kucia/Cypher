//
// Created by deddoghost on 11/6/24.
//
#include "Ceasar.h"
#include <stdio.h>
#include "encryption_options.h"
#include "Substitution.h"
#include <stdlib.h>
#include "Get_user_input.h"

int get_user_input(){

  // show user all optrions for encryption and decryption
	char user_input;
    char user_input2;
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
            char user_alphabet[26];
			printf("Create a new key?(1/0)\n");
            scanf(" %c", &user_input2);// did not work with scanf still unsure what is causing problems but getchar fixes it
            switch(user_input2){
              case '0':
                printf("Enter a valid alphabet with 26 unique letters:\n");

				get_user_ready_alphabet(user_alphabet);
				printf("User alphabet: %s\n",user_alphabet);
              break;
              case '1':
                printf("Enter 26 unique alphabet letters one by one:\n");
                get_user_custom_alphabet(user_alphabet);
                printf("User alphabet: %s\n",user_alphabet);
                break;
              default:
                printf("Wrong input\n");
                exit(0);
                break;
            }
            Substitution(user_alphabet);
			break;

		default:
			printf("User entered unaveilable option\n");
			break;

	}




    return 0;
}
// Praise the machine god