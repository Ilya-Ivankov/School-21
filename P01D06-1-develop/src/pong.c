#include <stdio.h>
void map(int racket_l_pos_y, int racket_r_pos_y, int boll_x, int boll_y, int cost1, int cost2);
void Clear(void) {
    printf("\033[2J");
    printf("\033[0;0f");
}

int main() {
    char command;
    int default_pos_y_racket = 13;

    int racket_r_pos_y = default_pos_y_racket;
    int racket_l_pos_y = default_pos_y_racket;

    int boll_x = 39;
    int ball_y = 13;

    int boll_status = 1;

    int cost1 = 0;
    int cost2 = 0;

    int win = 1;

    map(racket_l_pos_y, racket_r_pos_y, boll_x, ball_y, cost1, cost2);
    while (win != 0) {
        scanf("%c", &command);

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
        } else if (command != ' ') {
            continue;
        }

        switch (boll_status) {
            case 0:
                if ((ball_y == racket_r_pos_y - 1) && boll_x == 78) {
                    boll_status = 2;
                    boll_x--;

                } else if ((ball_y == racket_r_pos_y) && boll_x == 78) {
                    boll_status = 1;
                    boll_x--;

                }

                else if ((ball_y == racket_r_pos_y + 1) && boll_x == 78) {
                    boll_status = 5;

                } else {
                    boll_x++;
                }

                break;

            case 1:

                if ((ball_y == racket_l_pos_y - 1) && boll_x == 3) {
                    boll_status = 4;
                    boll_x++;

                } else if ((ball_y == racket_l_pos_y) && boll_x == 3) {
                    boll_status = 0;
                    boll_x++;

                } else if ((ball_y == racket_l_pos_y + 1) && boll_x == 3) {
                    boll_status = 3;
                    boll_x++;

                }

                else {
                    boll_x--;
                }
                break;
            case 2:
                if (ball_y == 1) {
                    boll_status = 5;
                }

                if ((ball_y == racket_l_pos_y - 1) && boll_x == 3) {
                    boll_status = 4;
                    boll_x++;

                } else if ((ball_y == racket_l_pos_y) && boll_x == 3) {
                    boll_status = 0;
                    boll_x++;

                } else if ((ball_y == racket_l_pos_y + 1) && boll_x == 3) {
                    boll_status = 3;
                    boll_x++;

                }

                else {
                    boll_x--;
                    ball_y--;
                }

                break;
            case 3:
                if (ball_y == 25) {
                    boll_status = 4;

                } else if ((ball_y == racket_r_pos_y - 1) && boll_x == 78) {
                    boll_status = 2;
                    boll_x--;

                } else if ((ball_y == racket_r_pos_y) && boll_x == 78) {
                    boll_status = 1;
                    boll_x--;

                }

                else if ((ball_y == racket_r_pos_y + 1) && boll_x == 78) {
                    boll_status = 5;

                }

                else {
                    boll_x++;
                    ball_y++;
                }
                break;
            case 4:
                if (ball_y == 1) {
                    boll_status = 3;

                } else if ((ball_y == racket_r_pos_y - 1) && boll_x == 78) {
                    boll_status = 2;
                    boll_x--;

                } else if ((ball_y == racket_r_pos_y) && boll_x == 78) {
                    boll_status = 1;
                    boll_x--;

                }

                else if ((ball_y == racket_r_pos_y + 1) && boll_x == 78) {
                    boll_status = 5;

                } else {
                    boll_x++;
                    ball_y--;
                }
                break;

            case 5:

                if (ball_y == 25) {
                    boll_status = 2;
                }
                if ((ball_y == racket_l_pos_y - 1) && boll_x == 3) {
                    boll_status = 4;
                    boll_x++;

                } else if ((ball_y == racket_l_pos_y) && boll_x == 3) {
                    boll_status = 0;
                    boll_x++;

                } else if ((ball_y == racket_l_pos_y + 1) && boll_x == 3) {
                    boll_status = 3;
                    boll_x++;

                } else {
                    boll_x--;
                    ball_y++;
                }
                break;
        }

        if (boll_x == 79) {
            cost1++;
            ball_y = 13;
            boll_x = 77;
            racket_l_pos_y = default_pos_y_racket;

            racket_r_pos_y = default_pos_y_racket;

            boll_status = 1;

        } else if (boll_x == 2) {
            cost2++;
            ball_y = 13;
            boll_x = 3;

            racket_l_pos_y = default_pos_y_racket;

            racket_r_pos_y = default_pos_y_racket;

            boll_status = 0;
        }
        Clear();
        map(racket_l_pos_y, racket_r_pos_y, boll_x, ball_y, cost1, cost2);
        if (cost1 == 21) {
            printf("PLAYER 1 WIN !");
            win = 0;
        } else if (cost2 == 21) {
            printf("PLAYER 2 WIN !");
            win = 0;
        }
    }

    return 0;
}

void map(int racket_l_pos_y, int racket_r_pos_y, int boll_x, int boll_y, int cost1, int cost2) {
    Clear();
    printf(
        "_____________________________________________________________________"
        "_____________\n");
    for (int y = 1; y < 26; ++y) {
        for (int x = 0; x < 81; ++x) {
            if (x == 0) {
                printf("/");
            } else if (((x == 2 &&
                         (y == racket_l_pos_y - 1 || y == racket_l_pos_y || y == racket_l_pos_y + 1)))) {
                printf("|");
            } else if (((x == 79 &&
                         (y == racket_r_pos_y - 1 || y == racket_r_pos_y || y == racket_r_pos_y + 1)))) {
                printf("|");
            } else if (x == 39 && y != boll_y) {
                printf("|");
            } else if (x == boll_x && y == boll_y) {
                printf("*");
            } else if (x == 39 && y == boll_y) {
                printf("|");
            } else if (x == 80) {
                printf(" \\\n");
            } else {
                printf(" ");
            }
        }
    }
    printf(
        "_____________________________________________________________________"
        "_____________\n");
    printf(
        "\nPLAYER 1: %d                                                             PLAYER 2:%d\n\n"
        "PRESS A/Z FOR PLAYER 1                                      PRESS K/M FOR PLAYER 2\n\n"
        "PRESS Q FOR STOP GAME\n\n"
        "PRESS SPACE FOR SKIP STEP\n\n",
        cost1, cost2);
    printf(
        "_____________________________________________________________________"
        "_____________\n");
}
