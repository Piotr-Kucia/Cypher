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
    get_user_input_message();
    encrypt_substitution(alphabet_lowercase,user_alphabet,message);
}
//Praise the machine spirit