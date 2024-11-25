//
// Created by deddoghost on 11/8/24.
//
#include <stdio.h>
#include "Ceasar.h"
#include <ctype.h>

int Ceasar(){
  char alphabet_uppercase[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
  char alphabet_lowercase[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
  char special_characters[] = {'.', ',', '?', '!', ':', ';',
  	};

  int upper_size = 26;
  int lower_size = 26;
  int special_size = 6;


  char message[100];
  int shift;

  printf("\nEnter shift amount\n");
  scanf("%d", &shift);
  printf("\nEnter message\n");
  while (getchar() != '\n');  // fgets does not work without this or in reverse order with fscan, idk why
  fgets(message, sizeof(message), stdin);


  // Encrypt the message
  for (int i = 0; i < sizeof(message); i++) { // its three for loops in one for loop, which seems as a bad solution,
    if (message[i] == '\0'){break;}// however it works and I understand this since it is a cave men like solution
    if (isupper(message[i])) {
      for (int j = 0; j < upper_size; j++) {
        if (message[i] == alphabet_uppercase[j]) {
          message[i] = alphabet_uppercase[(j) % upper_size];
          break;
        }
      }
    } else if (islower(message[i])) {
      for (int j = 0; j < lower_size; j++) {
        if (message[i] == alphabet_lowercase[j]) {
          message[i] = alphabet_lowercase[(j + shift) % lower_size];
          break;
        }
      }
    } else {
      for (int j = 0; j < special_size; j++) {
        if (message[i] == special_characters[j]) {
          message[i] = special_characters[(j + shift) % special_size];
          // Special characters are changed in a custom predefiend order due to my laziness, it works so idc
          break;
        }
      }
    }
  }
    printf("%s", message);
	return 0;
  }






