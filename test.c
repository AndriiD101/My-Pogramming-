#include <stdio.h>
#include <string.h>

#define MAX_MORSE_LENGTH 100  // Choose an appropriate maximum length

int is_morse_code_valid(const char morse[]) {
    char morse_code_copy[MAX_MORSE_LENGTH];
    strncpy(morse_code_copy, morse, sizeof(morse_code_copy) - 1);
    morse_code_copy[sizeof(morse_code_copy) - 1] = '\0';  // Ensure null-termination

    char *token = strtok(morse_code_copy, " "); // Tokenize the string

    // Morse code dictionary
    char *morse_code_dict[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",   // A to H
        "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",    // I to P
        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",   // Q to X
        "-.--", "--..", ".----", "..---", "...--", "....-", ".....", // 1 to 5
        "-....", "--...", "---..", "----.", "-----", "/"           // 6 to 0, space
    };

    while (token != NULL) {
        int is_valid = 0;
        for (int i = 0; i < sizeof(morse_code_dict) / sizeof(morse_code_dict[0]); ++i) {
            if (strcmp(token, morse_code_dict[i]) == 0) {
                is_valid = 1;
                break;
            }
        }

        if (!is_valid) {
            return 0;  // Not valid Morse code
        }

        token = strtok(NULL, " ");  // Move to the next token
    }

    return 1;  // Valid Morse code
}

int main() {
    const char *morse_code_input = "-.-.- .-.-.-.-. ---";
    if (is_morse_code_valid(morse_code_input)) {
        printf("The Morse code '%s' is valid.\n", morse_code_input);
    } else {
        printf("The Morse code '%s' is not valid.\n", morse_code_input);
    }

    return 0;
}
