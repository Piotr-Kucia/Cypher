#include <stdio.h>
#include <ctype.h>

// Function to find alphabet position of each character in the string
void printAlphabetPositions(const char* str) {
    int i = 0;

    while (str[i] != '\0') {
        char ch = str[i];

        if (isalpha(ch)) { // Check if character is a letter
            // Convert uppercase and lowercase letters to their alphabet position
            int position = tolower(ch) - 'a' + 1;
            printf("'%c' is at position %d in the alphabet.\n", ch, position);
        } else {
            printf("'%c' is not a letter, so it has no position.\n", ch);
        }

        i++;
    }
}

int main() {
    char str[100];

    // Input the string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Print the alphabet position of each letter in the string
    printAlphabetPositions(str);

    return 0;
}
//
// Created by deddoghost on 11/9/24.
//
