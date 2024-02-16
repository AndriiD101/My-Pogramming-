#include <stdio.h>
#include <stdbool.h>

int check_start(char array[], int index);
int check_stop(char array[], int index);

int main(int argc, char* argv[]) {
    FILE* file = fopen(argv[1], "r");

    int file_size = 0;
    char character;
    while((character = fgetc(file)) != EOF) {
        file_size++;
    }
    fclose(file);

    char buffer[file_size];

    //check start word
    file = fopen(argv[1], "r");
    int b_index = 0;
    while((character = fgetc(file)) != EOF) {
        buffer[b_index] = character;
        if(check_start(buffer, b_index) == 1) {
            break;
        }
        b_index++;
    }
    //check stop word
    char content[file_size];
    int c_index = 0;
    while((character = fgetc(file)) != EOF) {
        content[c_index] = character;
        if(check_stop(content, c_index) == 1) {
            break;
        }
        c_index++;
    }
    content[c_index-5] = '\0';
    fclose(file);

    char result[file_size];
    int r_index = 0;
    bool SecondWord = false;
    bool FirstWord = true;
    for(int i = 0; i < c_index - 5; i++) {
        if(content[i] == ' ') {
            SecondWord = true;
            if(FirstWord) {
                i++;
                FirstWord = false;
            }
        }
        if(SecondWord) {
            result[r_index] = content[i];
            r_index++;
        }
    }
    result[r_index] = '\0';

    FILE *outputFile = fopen(argv[2], "w");
    for(int i = 0; i < r_index; i++) {
        fputc(result[i], outputFile);
    }
    fclose(outputFile);

    return 0;
}

int check_start(char array[], int index) {
    if(array[index-5] != 'S' || array[index-4] != 'T' || array[index-3] != 'A' || array[index-2] != 'R' || array[index-1] != 'T' || array[index] != ' ') {
        return 0;
    }
    return 1;
}

int check_stop(char array[], int index) {
    if(array[index-4] != 'S' || array[index-3] != 'T' || array[index-2] != 'O' || array[index-1] != 'P') {
        return 0;
    }
    return 1;
}
