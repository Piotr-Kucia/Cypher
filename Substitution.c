//
// Created by deddoghost on 1/12/25.
//
#include <stdio.h>
#include <ctype.h>
#include "Encryption_tables.h"
#include "encryption_options.h"
#include "Get_user_input.h"
#include "Substitution.h"

void Substitution(char user_alphabet[]){
char encrypted_message[500];
    get_user_input_message();
    encrypt_substitution(alphabet_lowercase,user_alphabet,message,encrypted_message);
char temp_message[500];
    encrypt_substitution(user_alphabet,alphabet_lowercase,encrypted_message,temp_message);
}
void Substitution_decipher(char user_alphabet[]){


}
//Praise the machine spirit