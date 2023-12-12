#include <stdio.h>
#include <stdlib.h>

#define TARGET_WORD_LOWER "ananas"
#define TARGET_WORD_UPPER "ANANAS"
#define TARGET_LENGTH 6

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Incorrect filename\n");
        return 1;
    }

    int count = 0;
    int symbol = 0;
    char element;
    while ((element = fgetc(file)) != EOF) {
        if (element == TARGET_WORD_LOWER[symbol] || element == TARGET_WORD_UPPER[symbol]) {
            symbol++;
        } else {
            symbol = 0;
        }
        if (symbol == TARGET_LENGTH) {
            count++;
            symbol = 0;
        }
    }
    fclose(file);

    file = fopen(argv[1], "w");
    fputc('0' + count, file);
    fclose(file);

    return 0;
}
