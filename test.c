#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

#define WIDTH 22
#define HEIGHT 12
#define START_LENGTH 5

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position head;
    Position body[WIDTH * HEIGHT];
    int length;
    int direction;
} Snake;

typedef struct {
    int x, y;
} Fruit;

void initializeGame(Snake *snake, Fruit *fruit) {
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    snake->head.x = WIDTH / 2;
    snake->head.y = HEIGHT / 2;
    snake->length = START_LENGTH;
    snake->direction = KEY_RIGHT;

    for (int i = 0; i < START_LENGTH; i++) {
        snake->body[i].x = snake->head.x - i;
        snake->body[i].y = snake->head.y;
    }

    fruit->x = rand() % WIDTH;
    fruit->y = rand() % HEIGHT;

    refresh();
}

void draw(Snake *snake, Fruit *fruit) {
    clear();

    // Enable colors
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));

    // Draw the field boundaries
    for (int i = 0; i < WIDTH; i++) {
        mvprintw(0, i * 2, "-");
        mvprintw(HEIGHT, i * 2, "-");
    }

    for (int i = 0; i < HEIGHT; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, (WIDTH - 1) * 2, "|");
    }

    mvprintw(fruit->y, fruit->x * 2, "F");

    for (int i = 0; i < snake->length; i++) {
        mvprintw(snake->body[i].y, snake->body[i].x * 2, "O");
    }

    mvprintw(snake->head.y, snake->head.x * 2, "H");

    // Disable color
    attroff(COLOR_PAIR(1));

    refresh();
}

void getInput(Snake *snake) {
    int key = getch();

    switch (key) {
        case KEY_UP:
            if (snake->direction != KEY_DOWN)
                snake->direction = KEY_UP;
            break;
        case KEY_DOWN:
            if (snake->direction != KEY_UP)
                snake->direction = KEY_DOWN;
            break;
        case KEY_LEFT:
            if (snake->direction != KEY_RIGHT)
                snake->direction = KEY_LEFT;
            break;
        case KEY_RIGHT:
            if (snake->direction != KEY_LEFT)
                snake->direction = KEY_RIGHT;
            break;
    }
}

void moveSnake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    snake->body[0] = snake->head;

    switch (snake->direction) {
        case KEY_UP:
            snake->head.y--;
            break;
        case KEY_DOWN:
            snake->head.y++;
            break;
        case KEY_LEFT:
            snake->head.x--;
            break;
        case KEY_RIGHT:
            snake->head.x++;
            break;
    }
}

int checkCollision(Snake *snake, Fruit *fruit) {
    if (snake->head.x < 0 || snake->head.x >= WIDTH || snake->head.y < 0 || snake->head.y >= HEIGHT) {
        return 1;  // Collision with walls
    }

    for (int i = 0; i < snake->length; i++) {
        if (snake->head.x == snake->body[i].x && snake->head.y == snake->body[i].y) {
            return 1;  // Collision with itself
        }
    }

    if (snake->head.x == fruit->x && snake->head.y == fruit->y) {
        snake->length++;
        return 2;  // Collision with fruit
    }

    return 0;  // No collision
}

int main() {
    Snake snake;
    Fruit fruit;

    initializeGame(&snake, &fruit);

    while (1) {
        getInput(&snake);
        moveSnake(&snake);

        int collision = checkCollision(&snake, &fruit);

        if (collision == 1) {
            endwin();
            printf("Game Over!\n");
            break;
        } else if (collision == 2) {
            fruit.x = rand() % WIDTH;
            fruit.y = rand() % HEIGHT;
        }

        draw(&snake, &fruit);
        usleep(100000);  // Adjust the speed of the game
    }

    return 0;
}
