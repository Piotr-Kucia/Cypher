//
// Created by deddoghost on 12/9/24.
//

#ifndef USER_INPUT_H
#define USER_INPUT_H

extern char message[500];
extern int key;
extern int encryption_option_value;

void get_user_input_message();
void get_user_input_key();
void get_user_input_encryption_option();
void get_user_custom_alphabet(char user_alphabet[]);
void get_user_ready_alphabet(char user_alphabet[]);

#endif //USER_INPUT_H
