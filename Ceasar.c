//
// Created by deddoghost on 11/8/24.
//
#include <stdio.h>
#include "Ceasar.h"
#include <ctype.h>
#include "Encryption_tables.h"
#include "encryption_options.h"
#include "Get_user_input.h"

void Ceasar(){
//abcdefghijklmnopqrstuvwxzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890<>?:"{}+_)(*&^%$#@!,./;'[]-=
  int upper_size = 26;
  int lower_size = 26;
  int special_size = 6;
  int shift;
/*
  char message[200];
  int option;
  int shift;
  int encryption_option_value;

  printf("\nEnter shift amount\n");
  scanf("%d", &shift);
  shift = shift % upper_size;


  printf("\nEnter message\n");
  while (getchar() != '\n');  // fgets does not work without this or in reverse order with fscan, idk why
  fgets(message, sizeof(message), stdin);

  printf("\nEncrypt or Decrypt (1/0)");
  scanf("%d", &option );
  if (option == 0) {
    encryption_option_value = -1;;
  } else {
  encryption_option_value = 1;
  }
*/
get_user_input_message();
get_user_input_key();
get_user_input_encryption_option();
shift = key;
  // Encrypt the message
shift = shift % upper_size;
  for (int i = 0; i < sizeof(message); i++) { // its three for loops in one for loop, which seems as a bad solution,
    if (message[i] == '\0'){break;}// however it works and I understand this since it is a cave men like solution
    if (isupper(message[i])) {
      for (int j = 0; j < upper_size; j++) {
        if (message[i] == alphabet_uppercase[j]) {
          message[i] = alphabet_uppercase[shift_value(shift,encryption_option_value,lower_size,j)];
          break;
        }
      }
    } else if (islower(message[i])) {
      for (int j = 0; j < lower_size; j++) {
        if (message[i] == alphabet_lowercase[j]) {

          message[i] = alphabet_lowercase[shift_value(shift,encryption_option_value,lower_size,j)];

          break;
        }
      }
    } else {
      for (int j = 0; j < special_size; j++) {
        if (message[i] == special_characters[j]) {
          message[i] = special_characters[shift_value(shift,encryption_option_value,lower_size,j)];
          // Special characters are changed in a custom predefiend order due to my laziness, it works so idc
          break;
        }
      }
    }
  }
  printf("Encrypted message = %s \n\n\n", message);
    }
