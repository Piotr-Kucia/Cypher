//
// Created by deddoghost on 12/9/24.
//
#include <stdio.h>
#include "Get_user_input.h"

char message[500];
int key = 0;
int encryption_option_value = 0;
void get_user_input_message(){// get message from user

	printf("\nEnter message\n");
  	while (getchar() != '\n');  // fgets does not work without this or in reverse order with fscan, idk why
 	fgets(message, sizeof(message), stdin);
}

void get_user_input_encryption_option(){// helps with encriprion and decription
	printf("\nEncrypt or Decrypt (1/0)");
	int option;

 	scanf("%d", &option );
	if (option == 0) {
    	encryption_option_value = -1;;
  	} else {
  		encryption_option_value = 1;
  	}
}

void get_user_input_key(){

  	printf("\nEnter shift amount\n");
  	scanf("%d", &key);
}
