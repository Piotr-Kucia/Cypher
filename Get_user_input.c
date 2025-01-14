//
// Created by deddoghost on 12/9/24.
//
#include <stdlib.h>
#include <stdio.h>
#include "Get_user_input.h"
#include <ctype.h>
#include <stdbool.h>
#include "Encryption_tables.h"
#include <string.h>
#include <ctype.h>

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

// I AM NOT FAILING MATH I AM NOT FAILING MATH I AM NOT FAILING MATH I AM NOT FAILING MATH I AM NOT FAILING MATH I AM NOT FAILING MATH
void get_user_custom_alphabet(char user_alphabet[]) {
  	char temp_alphabet[26] = {
      'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
       'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
  	};
    int seen[26] = {0}; // This is supposed to track if letter has been typed, SUPPOSED TO


    for (int i = 0; i < 26; i++) {
        char input;
		 // Show available letters before each user input since I cant remember the alphabet
        printf("\nAvailable letters: ");
        for (int j = 0; j < 26; j++) {
            if (seen[j] == 0) {
                printf("%c ", temp_alphabet[j]);
            }
        }
        printf("\n");
        printf("Enter 0 to abort\n");
        while (1) { // This will loop as long as the user alphabet is not full, might cause trouble later since if I made amistek it WILL loop forever
            printf("Enter letter %d: ", i + 1);
            scanf(" %c", &input);
            if (input == '0') {
              printf("Exiting\n");
              exit(0);
            }
            input = tolower(input); // Should convert to lowercase but fails sometimes idk why, it happend like twice?

            if (!isalpha(input)) {

                printf("Invalid input. Please enter a valid alphabet letter.\n");
                continue;
            }

            int index = input - 'a'; // ChatGpt helped with this, i dont understand why but it works
            if (seen[index] == 1) {
                printf("Duplicate letter '%c' detected. Please enter a different letter.\n", input);
            } else {
                seen[index] = 1;       // Marks the letter as seen in the seen table, ALWAYS double = in IF STATEMENTS this took way too long to notice
                user_alphabet[i] = input;
                break;
            }
        }
    }
}
// this takes whole aphabet from user
void get_user_ready_alphabet(char user_alphabet[26]) {

    char input[27]; // Data type has to be bigger cuz C adds some random stuff at the end and needs that one more slot
    int seen[26] = {0}; // Same as before, this one tracks if all letters are difrent in each position



    while (1) {
        scanf("%s", input);

        // Check if the input contains exactly 26 letters, cuz alphabet has 26 letters duh
        if (strlen(input) != 26) {
            printf("Error: Please enter exactly 26 letters.\n");
            continue;
        }

        int is_valid = 1;
        // This looks for doubles and maybe other problems
        for (int i = 0; i < 26; i++) {
            if (!isalpha(input[i])) {
                printf("Error: Input contains invalid characters. Only alphabet letters are allowed.\n");
                is_valid = 0;
                break;
            }

            input[i] = tolower(input[i]); // I am too lazy to implement uppercase

            int index = input[i] - 'a';
            if (seen[index] == 1) {
                printf("Error: Duplicate letter '%c' detected. Please enter a different alphabet.\n", input[i]);
                is_valid = 0;
                break;
            } else {
                seen[index] = 1; // Marks the letter as seen, please never break this too so long to figure out
            }
        }

        if (is_valid) {
            // If valid, copy the input to user_alphabet since we need to check if human error occured. Praise the machine spirit
            for (int i = 0; i < 26; i++) {
                user_alphabet[i] = input[i];
            }

            break;
        }
    }
}
// Praise the code