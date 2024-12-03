//
// Created by deddoghost on 11/8/24.
//
#include <stdio.h>
#include "Ceasar.h"
#include <ctype.h>

#include "encryption_options.h"

int shift_value(int uncheck_shift, int user_option, int modulo, int alphabet_position) { // function code works, it took me way too long to write that to make it work
  //printf("Shift value before changes is %d\n", uncheck_shift);
  int adjusted_position = alphabet_position + (uncheck_shift * user_option);
  if (adjusted_position < 0) {
    adjusted_position = modulo + (adjusted_position % modulo);
  } else {
    adjusted_position = adjusted_position % modulo;
  }
  //printf("Shift value after changes is %d\n", adjusted_position);
  return adjusted_position;
}


int Ceasar(){
  char alphabet_uppercase[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
  char alphabet_lowercase[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
  char special_characters[] = {'.', ',', '?', '!', ':', ';'};
//abcdefghijklmnopqrstuvwxzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890<>?:"{}+_)(*&^%$#@!,./;'[]-=
  int upper_size = 26;
  int lower_size = 26;
  int special_size = 6;


  char message[200];
  int option;
  int shift;
  int encryption_option_value;
  printf("\nEncrypt or Decrypt (1/0)");
  scanf("%d", &option );
  printf("\nEnter shift amount\n");
  scanf("%d", &shift);
  shift = shift % upper_size;
  printf("\nEnter message\n");
  while (getchar() != '\n');  // fgets does not work without this or in reverse order with fscan, idk why
  fgets(message, sizeof(message), stdin);

  if (option == 0) {
    encryption_option_value = -1;;
  } else {
  encryption_option_value = 1;

  }

  // Encrypt the message
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
  get_user_input();
  return 0;
  }






