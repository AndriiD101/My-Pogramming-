#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hof.h"

#define MAX_NAME_LENGTH 50


void swap(struct player *a, struct player *b) {
    struct player temp = *a;
    *a = *b;
    *b = temp;
}

int load(struct player list[]){
    int position=0;
    int score = 0;
    char name[MAX_NAME_LENGTH];
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) return -1;
    while (fscanf(file, "%s %d", name, &score) == 2 && position < 10) {
        strcpy(list[position].name, name);
        list[position].score = score;
        position++;
    }
    return position;
}

bool save(const struct player list[], const int size){
    struct player *temp_list = calloc((size_t)size, sizeof(struct player));
    for(int i = 0; i < size; i++){
        temp_list[i] = list[i];
    }
    FILE *file;
    file = fopen("scores.txt", "w+");
    if (file == NULL){
        return false;
    }
    bool swapped = false;
    for (int i = 0; i < size-1; i++){
        swapped = false;
        for(int j = 0; j<size-i-1; j++){
            if(temp_list[j].score < temp_list[j+1].score){
                swap(&temp_list[j], &temp_list[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
    for(int i = 0; i < size; i++){
        fprintf(file, "%s %d\n", temp_list[i].name, temp_list[i].score);
    }
    fclose(file);
    return true;
}

// int main() {
//     // Sample player list
//     struct player array[10];
//     printf("%d\n", load(array));
//     return 0;
// }