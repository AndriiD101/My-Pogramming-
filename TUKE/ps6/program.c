#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define WIDTH 80
#define HEIGHT 24

int snakeX, snakeY, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
int speed;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;
bool isLevelCompleted = false;
int currentLevel = 1;
void MainMenu();
int main();
void WriteToFile(int score) {
    FILE *file = fopen("game_results.txt", "a"); // Открыть файл для добавления данных

    if (file != NULL) {
        fprintf(file, "Score: %d\n", score); // Записать результат в файл
        fclose(file); // Закрыть файл
    } else {
        printf("Error: Unable to open the file.\n"); // Вывести сообщение об ошибке, если файл не удалось открыть
    }
}

void InitColors() {
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK); // Snake
    init_pair(2, COLOR_RED, COLOR_BLACK);     // Fruit
}

void Setup() {
    clear();
    curs_set(0);
    srand(time(0));

    dir = RIGHT;
    snakeX = WIDTH / 4;
    snakeY = HEIGHT / 2;
    fruitX = (rand() % (WIDTH - 2)) + 1;
    fruitY = (rand() % (HEIGHT - 2)) + 1;
    score = 0;
    nTail = 0;
    speed = 150000;
    isLevelCompleted = false;
    InitColors();
}

void InitLevelThree() {
    int midWidth = WIDTH / 2;
    int midHeight = HEIGHT / 2;

    for (int i = 2; i <= midHeight; i++) {
        mvprintw(midHeight - i, midWidth - i, "#");
        mvprintw(midHeight + i, midWidth + i, "#");
        mvprintw(midHeight - i, midWidth + i, "#");
        mvprintw(midHeight + i, midWidth - i, "#");
    }
}


void Draw() {
    clear();
    for (int i = 0; i < WIDTH + 2; i++)
        mvprintw(0, i, "+");
    for (int i = 1; i < HEIGHT + 1; i++) {
        for (int j = 0; j < WIDTH + 2; j++) {
            if (j == 0 || j == WIDTH + 1)
                mvprintw(i, j, "+");
            else if (i == snakeY && j == snakeX) {
                attron(COLOR_PAIR(1));
                mvprintw(i, j, "O");
                attroff(COLOR_PAIR(1));
            }
            else if (i == fruitY && j == fruitX) {
                attron(COLOR_PAIR(2));
                mvprintw(i, j, "*");
                attroff(COLOR_PAIR(2));
            }
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        attron(COLOR_PAIR(1));
                        mvprintw(i, j, "o");
                        attroff(COLOR_PAIR(1));
                        print = true;
                    }
                }
                if (!print) mvprintw(i, j, " ");
            }
        }
    }
    for (int i = 0; i < WIDTH + 2; i++)
        mvprintw(HEIGHT + 1, i, "+");
    if (currentLevel == 2) {
        // Рисование препятствий для второго уровня с увеличенными проходами
        for (int i = 4; i < HEIGHT / 2 - 2; i++) {
            mvprintw(i, WIDTH / 4, "|");
            mvprintw(i, (3 * WIDTH) / 4, "|");
        }

        for (int i = 2; i < WIDTH - 2; i++) {
            if (i < WIDTH / 3 || i > 2 * WIDTH / 3) {
                mvprintw(HEIGHT / 4, i, "-");
                mvprintw((3 * HEIGHT) / 4, i, "-");
            }
        }
    }
        if (currentLevel == 3) {
        // Отрисовка препятствий третьего уровня
        InitLevelThree();
    }

    mvprintw(HEIGHT + 3, 0, "Score: %d", score);
    mvprintw(HEIGHT + 4, 0, "Use arrow keys to move the snake. 'n' for next level, 'x' to quit, 'q' to pause.");

    refresh();
}

void InitLevelTwo() {
    // Уменьшаем количество вертикальных препятствий
    for (int i = 4; i < HEIGHT / 2 - 2; i++) {
        mvprintw(i, WIDTH / 4, "|");
        mvprintw(i, (3 * WIDTH) / 4, "|");
    }

    // Уменьшаем количество горизонтальных препятствий
    for (int i = 2; i < WIDTH - 2; i++) {
        if (i < WIDTH / 3 || i > 2 * WIDTH / 3) {
            mvprintw(HEIGHT / 4, i, "-");
            mvprintw((3 * HEIGHT) / 4, i, "-");
        }
    }
}


void ResetGame() {
    clear();
    nTail = 0;
    //score = 0;
    snakeX = WIDTH / 4;
    snakeY = HEIGHT / 2;
    fruitX = (rand() % (WIDTH - 2)) + 1;
    fruitY = (rand() % (HEIGHT - 2)) + 1;
    dir = RIGHT;
    isLevelCompleted = false;

    if (currentLevel == 1) {
        speed = 150000;
    } else if (currentLevel == 2) {
        speed = 100000;
        InitLevelTwo(); // Правильный вызов для инициализации второго уровня
    }

    if (currentLevel == 3) {
        speed = 100000; // или другая скорость для третьего уровня
        InitLevelThree();
    }
}



void Input() {
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    int c = getch();
    switch(c) {
        case KEY_LEFT:
            if (dir != RIGHT) dir = LEFT;
            break;
        case KEY_RIGHT:
            if (dir != LEFT) dir = RIGHT;
            break;
        case KEY_UP:
            if (dir != DOWN) dir = UP;
            break;
        case KEY_DOWN:
            if (dir != UP) dir = DOWN;
            break;
        case 'q':
            nodelay(stdscr, FALSE);
            getch();
            nodelay(stdscr, TRUE);
            break;
        case 'x':
            dir = STOP;
            break;
        case 'n':
            if (isLevelCompleted) {
                ResetGame();
                nodelay(stdscr, TRUE);
            }
            break;

    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snakeX;
    tailY[0] = snakeY;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch(dir) {
        case LEFT:
            snakeX--;
            break;
        case RIGHT:
            snakeX++;
            break;
        case UP:
            snakeY--;
            break;
        case DOWN:
            snakeY++;
            break;
        default:
            break;
    }

    if (snakeX == 0 || snakeX == WIDTH || snakeY == 0 || snakeY == HEIGHT) {
        dir = STOP;
    }

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == snakeX && tailY[i] == snakeY) {
            dir = STOP;
        }
    }
   if ((currentLevel == 1 && score >= 10) || 
        (currentLevel == 2 && score >= 20) || 
        (currentLevel == 3 && score >= 30)) {
        isLevelCompleted = true;
        if (currentLevel == 2) {
            mvprintw(HEIGHT + 6, 0, "Level 2 complete! Press 'n' to go to next level or 'x' to exit.");
        } else if (currentLevel == 3) {
            clear();
            const char* winMsg = "YOU WON";
            int msgLength = strlen(winMsg);
            int startX = (WIDTH - msgLength) / 2;
            mvprintw(HEIGHT / 2, startX, "%s", winMsg);
            mvprintw(HEIGHT / 2 + 1, (WIDTH / 2) - 20, "Press 'x' to continue.");
        }
        refresh();
        nodelay(stdscr, FALSE);
    }
    if (snakeX == fruitX && snakeY == fruitY) {
        score += 10;
        fruitX = (rand() % (WIDTH - 2)) + 1;
        fruitY = (rand() % (HEIGHT - 2)) + 1;
        nTail++;
        speed -= 5000;
        if (speed < 20000) {
            speed = 20000;
        }

       if (score >= 10 && !isLevelCompleted && currentLevel == 1) {
        isLevelCompleted = true;
        nodelay(stdscr, FALSE);
        mvprintw(HEIGHT + 6, 0, "Level 1 complete! Press 'n' to go to next level or 'x' to exit.");
        refresh();
        
    }
 int ch;
    while(isLevelCompleted) {
        ch = getch();
        if (ch == 'n' && currentLevel != 3) {
            currentLevel++;
            ResetGame();
            break;
        } else if (ch == 'x') {
            dir = STOP; // Устанавливаем флаг завершения игры
            break;
        }
    }

    }
    

    if (isLevelCompleted) {
        if (snakeY == HEIGHT / 4 || snakeY == (3 * HEIGHT) / 4) {
            if (snakeX > 1 && snakeX < WIDTH) {
                dir = STOP;
            }
        }
        if (snakeX == WIDTH / 4 || snakeX == (3 * WIDTH) / 4) {
            if (snakeY > 0 && snakeY < HEIGHT) {
                dir = STOP;
            }
        }
    }
    if (currentLevel == 2) {
        // Проверка столкновения с вертикальными препятствиями
        if ((snakeX == WIDTH / 4 || snakeX == (3 * WIDTH) / 4) && (snakeY >= 4 && snakeY <= HEIGHT / 2 - 2)) {
            dir = STOP;
        }

        // Проверка столкновения с горизонтальными препятствиями
        if ((snakeY == HEIGHT / 4 || snakeY == (3 * HEIGHT) / 4) && (snakeX > 1 && snakeX < WIDTH - 1)) {
            if (!(snakeX >= WIDTH / 3 && snakeX <= 2 * WIDTH / 3)) {
                dir = STOP;
            }
        }
    }
    if (currentLevel == 3) {
        int midWidth = WIDTH / 2;
        int midHeight = HEIGHT / 2;

        // Проверка столкновений с каждым препятствием
        for (int i = 2; i <= midHeight; i++) {
            if ((snakeX == midWidth - i && snakeY == midHeight - i) ||
                (snakeX == midWidth + i && snakeY == midHeight + i) ||
                (snakeX == midWidth + i && snakeY == midHeight - i) ||
                (snakeX == midWidth - i && snakeY == midHeight + i)) {
                dir = STOP;
                break;
            }
        }
    }


int ch;
while(isLevelCompleted) {
    ch = getch();
    if (ch == 'n') {
        currentLevel = (currentLevel == 2) ? 3 : 2; // Переход на следующий уровень
        ResetGame();
        break;
    } else if (ch == 'x') {
        dir = STOP; // Выход из игры
        break;
    }
}
}

void SelectMap() {
    int maps[] = {1, 2, 3};
    int choice;
    int highlight = 0;
    int num_options = 4; // 3 карты + 1 для возврата

    while (1) {
        clear();
        for (int i = 0; i < num_options; i++) {
            if (i == highlight) {
                attron(A_REVERSE); // Выделение текущего выбора
            }
            switch (i) {
                case 0: mvprintw(HEIGHT / 2 - 3, WIDTH / 2 - 10, "Map 1"); break;
                case 1: mvprintw(HEIGHT / 2 - 2, WIDTH / 2 - 10, "Map 2"); break;
                case 2: mvprintw(HEIGHT / 2 - 1, WIDTH / 2 - 10, "Map 3"); break;
                case 3: mvprintw(HEIGHT / 2, WIDTH / 2 - 10, "Back to Menu"); break;
            }
            attroff(A_REVERSE);
        }

        choice = getch();

        switch (choice) {
            case KEY_UP:
                if (highlight > 0) highlight--;
                break;
            case KEY_DOWN:
                if (highlight < num_options - 1) highlight++;
                break;
            case 10: // Enter key
                if (highlight < 3) {
                    currentLevel = maps[highlight];
                    ResetGame(); // Сброс игры при выборе карты
                    return; // Запуск игры
                } else if (highlight == 3) {
                    return; // Вернуться к главному меню
                }
                break;
            default:
                break;
        }
    }
}

void SelectSpeed() {
    int speeds[] = {150000, 100000, 50000};
    int choice;
    int highlight = 0;
    int num_options = 4; // 3 скорости + 1 для возврата

    keypad(stdscr, TRUE);

    while(1) {
        clear();
        for(int i = 0; i < num_options; i++) {
            if(i == highlight)
                attron(A_REVERSE);
            if(i < 3)
                mvprintw(HEIGHT / 2 - 1 + i, WIDTH / 2 - 10, "Speed %d", speeds[i]);
            else
                mvprintw(HEIGHT / 2 - 1 + i, WIDTH / 2 - 10, "Back to Menu");
            attroff(A_REVERSE);
        }

        choice = getch();

        switch(choice) {
            case KEY_UP:
                if(highlight > 0)
                    highlight--;
                break;
            case KEY_DOWN:
                if(highlight < num_options - 1)
                    highlight++;
                break;
            case 10:
            case KEY_ENTER:
                if(highlight < 3) {
                    speed = speeds[highlight];
                }
                clear();
                return;
            default:
                break;
        }
    }
}

void MainMenu() {
    int choice;
    int highlight = 0;
    int num_options = 4; // Теперь 4 опции: Select Level, Select Speed, Start Game, Exit Game

    while(1) {
        clear();
        for(int i = 0; i < num_options; i++) {
            if(i == highlight) {
                attron(A_REVERSE); // Выделение текущего выбора
            }
            switch(i) {
                case 0: mvprintw(HEIGHT / 2 - 3, WIDTH / 2 - 10, "Play on map"); break;
                case 1: mvprintw(HEIGHT / 2 - 2, WIDTH / 2 - 10, "Select Speed"); break;
                case 2: mvprintw(HEIGHT / 2 - 1, WIDTH / 2 - 10, "Start Game"); break;
                case 3: mvprintw(HEIGHT / 2, WIDTH / 2 - 10, "Exit Game"); break;
            }
            attroff(A_REVERSE);
        }

        choice = getch();

        switch(choice) {
            case KEY_UP:
                if(highlight > 0) highlight--;
                break;
            case KEY_DOWN:
                if(highlight < num_options - 1) highlight++;
                break;
            case 10: // Enter key
                if(highlight == 0) {
                    SelectMap();
                } else if(highlight == 1) {
                    SelectSpeed();
                } else if(highlight == 2) {
                    return; // Start the game
                } else if(highlight == 3) {
                    endwin(); // Закрыть ncurses
                    exit(0); // Выход из программы
                }
                break;
            break;
            default:
                break;
        }
    }
}


int main() {
    initscr(); // Инициализация ncurses
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    while (true) {
        MainMenu();
        Setup();
      while (dir != STOP) {
    Draw();
    Input();
    Logic();
    usleep(speed);
}

// Здесь игра завершена, добавьте вызов WriteToFile(score)
WriteToFile(score);

getch(); // Ждем нажатия клавиши перед выходом
endwin(); // Закрываем ncurses

printf("Final Score: %d\n", score);

// Предложение игроку сыграть еще раз или выйти
printf("Play again? (y/n): ");
int choice = getchar();
if (choice == 'n' || choice == 'N') {
    break; // Выход из цикла и завершение программы
}

// Повторная инициализация ncurses
initscr();
noecho();
cbreak();
keypad(stdscr, TRUE);


    return 0;
}
}
