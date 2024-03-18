#include <stdio.h>
#include <stdbool.h>

struct player {
    char name[50];
    int score;
};

void swap(struct player *a, struct player *b) {
    struct player temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct player list[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j].score < list[j + 1].score) {
                swap(&list[j], &list[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped in the inner loop, then the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    // Sample player list
    struct player players[] = {
        {"Player1", 100},
        {"Player2", 85},
        {"Player3", 95},
        {"Player4", 70},
        {"Player5", 110}
    };

    int size = sizeof(players) / sizeof(players[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %d\n", players[i].name, players[i].score);
    }

    bubbleSort(players, size);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - %d\n", players[i].name, players[i].score);
    }

    return 0;
}
