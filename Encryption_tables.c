//
// Created by deddoghost on 12/3/24.
//

#include "Encryption_tables.h"
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