//
// Created by deddoghost on 12/3/24.
//

#ifndef ENCRYPTION_TABLES_H
#define ENCRYPTION_TABLES_H

extern char alphabet_lowercase[];
extern char alphabet_uppercase[];
extern char special_characters[];
int shift_value(int uncheck_shift, int user_option, int modulo, int alphabet_position);
#endif //ENCRYPTION_TABLES_H
