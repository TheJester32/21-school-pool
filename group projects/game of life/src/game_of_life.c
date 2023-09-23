#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>

#define X 80
#define Y 25
#define CELL '*'
#define EMPTY '-'
#define MIN_SPEED 30000
#define MAX_SPEED 300000
#define SPEED_STEP 10000
#define INITIAL_SPEED 150000

int initialize_generation(int generation[X][Y]);
void draw_generation(int generation[X][Y]);
void next_generation(int generation[X][Y]);
void handle_input(int *speed, int *game_over);
int mod(int, int);

int main() {
    int generation[X][Y];
    int init_status;
    int game_over = 0;
    int speed = INITIAL_SPEED;
    init_status = initialize_generation(generation);

    if (init_status != 0) {
        printf("Ошибка");
        return 1;
    } else {
        initscr();
        noecho();
        nodelay(stdscr, 1);
        draw_generation(generation);

        while (game_over != 1) {
            usleep(speed);
            clear();
            next_generation(generation);
            draw_generation(generation);
            handle_input(&speed, &game_over);
        }
    }
    return 0;
}

int initialize_generation(int generation[X][Y]) {
    int res = 0;
    int symbol;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (scanf("%d", &symbol) == 1) {
                generation[x][y] = symbol;
            }
        }
    }
    if (freopen("/dev/tty", "r", stdin) == NULL) res = 1;

    return res;
}

void next_generation(int generation[X][Y]) {
    int next_generation[X][Y];
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            int neighbors = 0;
            neighbors = generation[mod(x - 1, X)][mod(y - 1, Y)] + generation[mod(x - 1, X)][y] +
                        generation[mod(x - 1, X)][mod(y + 1, Y)] + generation[x][mod(y - 1, Y)] +
                        generation[x][mod(y + 1, Y)] + generation[mod(x + 1, X)][mod(y - 1, Y)] +
                        generation[mod(x + 1, X)][y] + generation[mod(x + 1, X)][mod(y + 1, Y)];
            if (generation[x][y] == 1) {
                if ((neighbors == 3) || (neighbors == 2)) {
                    next_generation[x][y] = 1;
                } else {
                    next_generation[x][y] = 0;
                }
            } else {
                if (neighbors == 3) {
                    next_generation[x][y] = 1;
                } else
                    next_generation[x][y] = 0;
            }
        }
    }

    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            generation[x][y] = next_generation[x][y];
        }
    }
}

void draw_generation(int generation[X][Y]) {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (generation[x][y] == 1) {
                printw("%c", CELL);
            } else {
                printw("%c", EMPTY);
            }
        }
        printw("\n");
    }
    printw("\nType Q to end game");
    printw("\nType + to speed up");
    printw("\nType - to slow down");
}

int mod(int a, int b) {
    int out = a;
    if (a < 0) out = b - 1;
    if (a == b) out = 0;
    return out;
}

void handle_input(int *speed, int *game_over) {
    char input = getch();
    switch (input) {
        case '=':
            if (*speed > MIN_SPEED) {
                *speed -= SPEED_STEP;
            }
            break;
        case '-':
            if (*speed < MAX_SPEED) *speed += SPEED_STEP;
            break;
        case 'q':
            *game_over = 1;
            endwin();
    }
}
