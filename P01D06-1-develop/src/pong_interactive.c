#include <ncurses.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
void map(int racket_l_pos_y, int racket_r_pos_y, int boll_x, int boll_y, int cost1, int cost2);
int main() {
    initscr();
    curs_set(0);
    noecho();
    halfdelay(1);
    int default_pos_y_racket = 13;

    int racket_r_pos_y = default_pos_y_racket;
    int racket_l_pos_y = default_pos_y_racket;

    int ball_x = 39;
    int ball_y = 13;

    int ball_status = 1;

    int cost1 = 0;
    int cost2 = 0;

    int win = 1;

    map(racket_l_pos_y, racket_r_pos_y, ball_x, ball_y, cost1, cost2);
    while (win != 0) {
        char command;
        command = getch();
        clear();

        if ((command == 'a' || command == 'A') && racket_l_pos_y > 2) {
            racket_l_pos_y--;
        } else if ((command == 'z' || command == 'Z') && racket_l_pos_y < 24) {
            racket_l_pos_y++;
        } else if ((command == 'm' || command == 'M') && racket_r_pos_y < 24) {
            racket_r_pos_y++;
        } else if ((command == 'k' || command == 'K') && racket_r_pos_y > 2) {
            racket_r_pos_y--;
        } else if (command == 'q') {
            return 0;
        }

        switch (ball_status) {
            case 0:
                if ((ball_y == racket_r_pos_y - 1) && ball_x == 78) {
                    ball_status = 2;
                    ball_x--;

                } else if ((ball_y == racket_r_pos_y) && ball_x == 78) {
                    ball_status = 1;
                    ball_x--;

                } else if ((ball_y == racket_r_pos_y + 1) && ball_x == 78) {
                    ball_status = 5;

                } else {
                    ball_x++;
                }

                break;

            case 1:

                if ((ball_y == racket_l_pos_y - 1) && ball_x == 3) {
                    ball_status = 4;
                    ball_x++;

                } else if ((ball_y == racket_l_pos_y) && ball_x == 3) {
                    ball_status = 0;
                    ball_x++;

                } else if ((ball_y == racket_l_pos_y + 1) && ball_x == 3) {
                    ball_status = 3;
                    ball_x++;

                }

                else {
                    ball_x--;
                }
                break;
            case 2:
                if (ball_y == 1) {
                    ball_status = 5;
                }

                if ((ball_y == racket_l_pos_y - 1) && ball_x == 3) {
                    ball_status = 4;
                    ball_x++;

                } else if ((ball_y == racket_l_pos_y) && ball_x == 3) {
                    ball_status = 0;
                    ball_x++;

                } else if ((ball_y == racket_l_pos_y + 1) && ball_x == 3) {
                    ball_status = 3;
                    ball_x++;

                }

                else {
                    ball_x--;
                    ball_y--;
                }

                break;
            case 3:
                if (ball_y == 25) {
                    ball_status = 4;

                } else if ((ball_y == racket_r_pos_y - 1) && ball_x == 78) {
                    ball_status = 2;
                    ball_x--;

                } else if ((ball_y == racket_r_pos_y) && ball_x == 78) {
                    ball_status = 1;
                    ball_x--;

                }

                else if ((ball_y == racket_r_pos_y + 1) && ball_x == 78) {
                    ball_status = 5;

                }

                else {
                    ball_x++;
                    ball_y++;
                }
                break;
            case 4:
                if (ball_y == 1) {
                    ball_status = 3;

                } else if ((ball_y == racket_r_pos_y - 1) && ball_x == 78) {
                    ball_status = 2;
                    ball_x--;

                } else if ((ball_y == racket_r_pos_y) && ball_x == 78) {
                    ball_status = 1;
                    ball_x--;

                }

                else if ((ball_y == racket_r_pos_y + 1) && ball_x == 78) {
                    ball_status = 5;

                } else {
                    ball_x++;
                    ball_y--;
                }
                break;

            case 5:

                if (ball_y == 25) {
                    ball_status = 2;
                }
                if ((ball_y == racket_l_pos_y - 1) && ball_x == 3) {
                    ball_status = 4;
                    ball_x++;

                } else if ((ball_y == racket_l_pos_y) && ball_x == 3) {
                    ball_status = 0;
                    ball_x++;

                } else if ((ball_y == racket_l_pos_y + 1) && ball_x == 3) {
                    ball_status = 3;
                    ball_x++;

                } else {
                    ball_x--;
                    ball_y++;
                }
                break;
        }

        if (ball_x == 79) {
            cost1++;
            ball_y = 13;
            ball_x = 77;
            racket_l_pos_y = default_pos_y_racket;

            racket_r_pos_y = default_pos_y_racket;

            ball_status = 1;

        } else if (ball_x == 2) {
            cost2++;
            ball_y = 13;
            ball_x = 3;

            racket_l_pos_y = default_pos_y_racket;

            racket_r_pos_y = default_pos_y_racket;

            ball_status = 0;
        }

        map(racket_l_pos_y, racket_r_pos_y, ball_x, ball_y, cost1, cost2);
        if (cost1 == 21) {
            clear();
            printw("PLAYER 1 WIN!");
            win = 0;
        } else if (cost2 == 21) {
            clear();
            printw("PLAYER 2 WIN!");
            win = 0;
        }
        refresh();
    }
    usleep(2000000);

    endwin();
    return 0;
}

void map(int racket_l_pos_y, int racket_r_pos_y, int boll_x, int boll_y, int cost1, int cost2) {
    printw(
        "_____________________________________________________________________"
        "_____________\n");
    for (int y = 1; y < 26; ++y) {
        for (int x = 0; x < 81; ++x) {
            if (x == 0) {
                printw("I");
            } else if (((x == 2 &&
                         (y == racket_l_pos_y - 1 || y == racket_l_pos_y || y == racket_l_pos_y + 1)))) {
                printw("|");
            } else if (((x == 79 &&
                         (y == racket_r_pos_y - 1 || y == racket_r_pos_y || y == racket_r_pos_y + 1)))) {
                printw("|");
            } else if (x == 39 && y != boll_y) {
                printw("|");
            } else if (x == boll_x && y == boll_y) {
                printw("*");
            } else if (x == 39 && y == boll_y) {
                printw("|");
            } else if (x == 80) {
                printw(" I\n");
            } else {
                printw(" ");
            }
        }
    }
    printw(
        "_____________________________________________________________________"
        "_____________\n");
    printw(
        "\nPLAYER 1: %d                                                             PLAYER 2:%d\n\n"
        "PRESS A/Z FOR PLAYER 1                                      PRESS K/M FOR PLAYER 2\n\n"
        "PRESS Q FOR STOP GAME\n\n",
        cost1, cost2);
    printw(
        "_____________________________________________________________________"
        "_____________\n");
}
