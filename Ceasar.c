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
  char special_characters[] = {'.', ',', '?', '!', ':', ';'};
  char message[100];
  int shift;
  printf("\nEnter message\n");
  scanf("%s", message);
  printf("\nEnter shift amount\n");
  scanf("%d", &shift);
  /*
  int i = 0;
  // switch all letters for encryoted counterpart
  while (message[i] != '\0'){
    char ch = message[i];
      if (isupper(ch)) {
            message[i] = ((ch - 'A' + shift) % 26) + 'A';
        }
        else if (islower(ch)) {
            message[i] = ((ch - 'a' + shift) % 26) + 'a';
        }
    i ++;

    }
*/
  int i =0;
  while (message[i] != '0'){
    char ch = message[i];


  }



	return 0;

	}
