#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define PASSWORD_LENGTH 8
#define PASSWORD "secret"

char* my_strdup(const char* str) {
    size_t len = strlen(str) + 1;
    char* dup = malloc(len);
    if (dup) {
        strcpy(dup, str);
    }
    return dup;
}

char* upper(const char* text) {
    char* result = my_strdup(text); 
    int length = strlen(result);
    for (int i = 0; i < length; i++) {
        result[i] = toupper(result[i]);
    }
    return result;
}

int main() {
    bool pass = false;
    char password[PASSWORD_LENGTH + 1];

    printf("Please enter the password: ");
    fgets(password, sizeof(password), stdin);

    password[strcspn(password, "\n")] = '\0';

    char* uppercase_password = upper(password);
    char* uppercase_correct_password = upper(PASSWORD);

    if(strcmp(uppercase_password, uppercase_correct_password) == 0) {
        pass = true;
    }


    if(pass == false) {
        printf (">> Security breach detected. Calling police!\n");
    } else {
        printf (">> Welcome, access granted.\n");
    }

    free(uppercase_password);
    free(uppercase_correct_password);

    return 0;
}
