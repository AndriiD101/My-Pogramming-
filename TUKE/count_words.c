#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    char sequence[] = "ananas";
    char sequence_upper[] = "ANANAS";
    int sequence_length = sizeof(sequence) - 1; // excluding null terminator

    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == sequence[count] || ch == sequence_upper[count]) {
            count++;
            if (count == sequence_length) {
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    fclose(file);

    file = fopen(argv[1], "w");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return 1;
    }

    fprintf(file, "%d", count);
    fclose(file);

    return 0;
}
