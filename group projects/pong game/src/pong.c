#include <stdio.h>

int score(int leftright) {
    if (leftright == 2) {
        return 2;
    }

    if (leftright == 78) {
        return 1;
    } else {
        return 0;
    }
}

int count_up_down_x(int x, int z1, int z2) {
    int flag = z1;
    if (z2 == 1) {
        x = 39;
        flag = 1;
    }
    if (z2 == 2) {
        x = 39;
        flag = 0;
    }
    if (flag == 0) {
        x++;
    } else {
        x--;
    }
    return x;
}

int count_left_right_y(int y, int z2, int z3) {
    int flag = z2;
    if (z3 == 1) {
        y = 12;
    }
    if (z3 == 2) {
        y = 12;
    } else if (flag == 0) {
        y++;
    } else {
        y--;
    }
    return y;
}

int make_playground(int leftright, int updown, int point_left, int point_right, int height_left,
                    int height_right) {
    int x = 80, y = 25;
    int width1 = 0, width2 = 0;

    printf("\033[0d\033[2j");

    while (width1 != x) {
        printf("-");
        width1++;
    }

    for (int j = 0; j < y; j++) {
        printf("%c", '\n');

        for (int i = 0; i < x; i++) {
            if (i == 0 || i == x - 1 || i == x / 2 - 1) {
                printf("|");
            } else if (i == 2 && j == (height_left - 1)) {
                printf("|");
            } else if (i == 2 && j == (height_left)) {
                printf("|");
            } else if (i == 2 && j == (height_left + 1)) {
                printf("|");
            } else if (j == (height_right - 1) && i == 80 - 3) {
                printf("|");
            } else if (j == (height_right) && i == 80 - 3) {
                printf("|");
            } else if (j == (height_right + 1) && i == 80 - 3) {
                printf("|");
            } else if (j == 0 && i == 37) {
                printf("|");
            } else if (j == 0 && i == 41) {
                printf("|");
            } else if (j == 0 && i == 40) {
                printf("%d", point_right);
            } else if (j == 0 && i == 38) {
                printf("%d", point_left);
            } else if (j == updown && i == leftright) {
                printf("*");
            } else {
                printf(" ");
            }
        }
    }
    printf("%c", '\n');
    while (width2 != x) {
        printf("-");
        width2++;
    }
    return 0;
}

int control_function() {
    char c;
    scanf("%c", &c);
    switch (c) {
        case 'a':
            return 1;
        case 'z':
            return 2;
        case 'k':
            return 3;
        case 'm':
            return 4;
        case ' ':
            return 0;
    }
    return 0;
}

int main() {
    int x = 39, y = 12, point_left = 0, point_right = 0, leftright = x, updown = y, flag1 = 0, flag2 = 0,
        flag3 = 0, height_left = 12, height_right = 12;
    char c;

    for (char i = 'a'; i != 'q';) {
        scanf("%c", &c);

        make_playground(leftright, updown, point_left, point_right, height_left, height_right);

        int movement = control_function();
        if (movement == 1 && height_left != 1) {
            height_left = height_left - 1;
        }
        if (movement == 2 && height_left != 23) {
            height_left = height_left + 1;
        }
        if (movement == 3 && height_right != 1) {
            height_right = height_right - 1;
        }
        if (movement == 4 && height_right != 23) {
            height_right = height_right + 1;
        }

        leftright = count_up_down_x(leftright, flag1, flag3);
        updown = count_left_right_y(updown, flag2, flag3);
        if (leftright == 76 &&
            (height_right == updown || height_right - 1 == updown || height_right + 1 == updown)) {
            flag1 = 1;
        }
        if (leftright == 3 &&
            (height_left == updown || height_left - 1 == updown || height_left + 1 == updown)) {
            flag1 = 0;
        }
        if (updown == 24) {
            flag2 = 1;
        }
        if (updown == 0) {
            flag2 = 0;
        }

        if (score(leftright) == 2) {
            point_right = point_right + 1;
            flag3 = 1;
        } else if (score(leftright) == 1) {
            point_left = point_left + 1;
            flag3 = 2;
        } else if (score(leftright) == 0) {
            flag3 = 0;
        }
        if (point_right == 21) {
            printf("\e[H\e[?251\e[2J");
            printf("Left player Won!\n");
            break;
        } else if (point_left == 21) {
            printf("\e[H\e[?251\e[2J");
            printf("Right player Won!");
            break;
        }
    }
    return 0;
}
