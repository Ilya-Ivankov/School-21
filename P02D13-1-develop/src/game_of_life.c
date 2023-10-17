#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 25

void initialize(char grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }
}

void draw(char grid[HEIGHT][WIDTH]) {
    clear();
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            mvaddch(i, j, grid[i][j]);
        }
    }
    printw("\n______________________________________________________________________________");
    refresh();
}

void setCell(char grid[HEIGHT][WIDTH], int x, int y, char state) { grid[y][x] = state; }

char getCell(char grid[HEIGHT][WIDTH], int x, int y) { return grid[y][x]; }

int countNeighbors(char grid[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i == 0 && j == 0)) continue;
            int nx = (x + j + WIDTH) % WIDTH;
            int ny = (y + i + HEIGHT) % HEIGHT;

            if (grid[ny][nx] != ' ') count++;
        }
    }
    return count;
}

int update(char grid[HEIGHT][WIDTH]) {
    int error = 1;
    char newGrid[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(grid, j, i);
            if (grid[i][j] == '*') {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = ' ';
                } else {
                    newGrid[i][j] = '*';
                }
            } else {
                if (neighbors == 3)
                    newGrid[i][j] = '*';
                else
                    newGrid[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] != newGrid[i][j]) {
                error = 0;
            }
        }
    }
    return error;
}

void showStatus(int generation, int speed) {
    mvprintw(HEIGHT + 2, 0, "Generation: %d", generation);
    mvprintw(HEIGHT + 3, 0, "Speed: %d", speed);
    mvprintw(HEIGHT + 4, 0, "Press 'q' to quit.");
    mvprintw(HEIGHT + 5, 0, "Speed - : w  |  Speed + : e");
    mvprintw(HEIGHT + 6, 0, "Made by garbagei, rhaellaa and bastardn.");
    mvprintw(HEIGHT + 7, 0, "Please select an initial state:");
    mvprintw(HEIGHT + 8, 0, "1 - galactic; 2 - square; 3 - clock; 4 - glider; 5 - spaceship");
    printw("\n\n______________________________________________________________________________");
    refresh();
}

void delay(int milliseconds) { usleep(milliseconds * 1000); }

int main() {
    char grid[HEIGHT][WIDTH];
    int generation = 0;
    int speed = 100;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    curs_set(FALSE);
    halfdelay(1);
    initialize(grid);

    FILE *file;

    bool running = true;
    while (running) {
        draw(grid);
        if (update(grid) == 0) {
            running = false;
        }

        showStatus(generation, speed);
        delay(speed);
        int ch = getch();
        switch (ch) {
            case 'q':
                running = false;
                break;
            case 'w':
                if (speed > 0) speed += 10;
                break;
            case 'e':
                speed -= 10;
                break;
            case '1':
                clear();
                file = fopen("galactic.txt", "r");
                if (file != NULL) {
                    for (int i = 0; i < HEIGHT; i++) {
                        for (int j = 0; j < WIDTH; j++) {
                            char c = fgetc(file);
                            if (c != EOF) grid[i][j] = c;
                        }
                    }
                    fclose(file);
                }
                generation = 0;
                refresh();
                break;

            case '2':
                clear();
                file = fopen("square.txt", "r");
                if (file != NULL) {
                    for (int i = 0; i < HEIGHT; i++) {
                        for (int j = 0; j < WIDTH; j++) {
                            char c = fgetc(file);
                            if (c != EOF) grid[i][j] = c;
                        }
                    }
                    fclose(file);
                }
                generation = 0;
                refresh();
                break;

            case '3':
                clear();
                file = fopen("clock.txt", "r");
                if (file != NULL) {
                    for (int i = 0; i < HEIGHT; i++) {
                        for (int j = 0; j < WIDTH; j++) {
                            char c = fgetc(file);
                            if (c != EOF) grid[i][j] = c;
                        }
                    }
                    fclose(file);
                }
                generation = 0;
                refresh();
                break;

            case '4':
                clear();
                file = fopen("glider.txt", "r");
                if (file != NULL) {
                    for (int i = 0; i < HEIGHT; i++) {
                        for (int j = 0; j < WIDTH; j++) {
                            char c = fgetc(file);
                            if (c != EOF) grid[i][j] = c;
                        }
                    }
                    fclose(file);
                }
                generation = 0;
                refresh();
                break;
            case '5':
                clear();
                file = fopen("spaceship.txt", "r");
                if (file != NULL) {
                    for (int i = 0; i < HEIGHT; i++) {
                        for (int j = 0; j < WIDTH; j++) {
                            char c = fgetc(file);
                            if (c != EOF) grid[i][j] = c;
                        }
                    }
                    fclose(file);
                }
                generation = 0;
                refresh();
                break;
            default:
                break;
        }

        generation++;
    }

    endwin();

    return 0;
}
