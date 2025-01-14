//
// Created by deddoghost on 12/3/24.
//
#include <stdio.h>
#include "Encryption_tables.h"
#include <string.h>
char alphabet_uppercase[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
char alphabet_lowercase[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
char special_characters[] = {'.', ',', '?', '!', ':', ';'};

int shift_value(int uncheck_shift, int user_option, int modulo, int alphabet_position) {
  // function code works, it took me way too long to write that to make it work
  // This makes sure that code doesn't try to give negative value to the alphabet tables
  int adjusted_position = alphabet_position + (uncheck_shift * user_option);
  if (adjusted_position < 0) {
    adjusted_position = modulo + (adjusted_position % modulo);
  } else {
    adjusted_position = adjusted_position % modulo;
  }

  return adjusted_position;
}
void encrypt_substitution(char alphabet_to_take[], char alphabet_to_compare[], char message[],char encrypted_message[]) {

    for (int i = 0; message[i] != '\0'; i++) {
        int skibidi = 0;  // variable names show my mental state
        for (int j = 0; alphabet_to_take[j] != '\0'; j++) {
            if (message[i] == alphabet_to_take[j]) {
                encrypted_message[i] = alphabet_to_compare[j];  // replaces letters
                skibidi = 1;
                break;
            }
        }
        if (!skibidi) {
            encrypted_message[i] = message[i]; // made this for numbets, too lazy to implement them now and I have exam in 2h
        }
    }

    encrypted_message[strlen(message)] = '\0';
    encrypted_message[strlen(message)] = '\0';
    printf("\n\n\nYour message:\n");
    printf("%s\n", message);

    printf("Your encrypted message:\n");
    printf("%s\n", encrypted_message);

    printf("Your alphabet:\n");
    printf("%s\n", alphabet_to_compare);
}
// Praise the machine spirit