/*
** EPITECH PROJECT, 2020
** my hunter
** File description:
** set up scoreboard
*/

#include "scoreboard.h"

static int set_score(char *score, char *dest, score_int *ints)
{
    for (int j = 0; score[j] != '\0'; j++) {
        dest[ints->k] = score[j];
        ints->k++;
    }
    dest[ints->k] = '\n';
    ints->k++;
    ints->i++;
}

static char *set_scoreboard(char *str, char *score)
{
    char *dest = malloc(my_strlen(str) + my_strlen(score));
    score_int *ints = malloc(sizeof(score_int));
    int a = 1;
    int l = 0;

    for (ints->i = 0; ints->i < 5; ints->i++) {
        if (my_getnbr(score) > my_getnbr(str + l) && a) {
            set_score(score, dest, ints);
            a = 0;
        }
        for (; str[l] != '\n'; l++) {
            dest[ints->k] = str[l];
            ints->k++;
        }
        dest[ints->k] = '\n';
        ints->k++;
        l++;
    }
    return dest;
}

int write_scoreboard(char *str, char *score)
{
    int fd = open("scoreboard/score.txt", O_WRONLY);
    char *dest;

    if (fd == -1)
        return 84;
    dest = set_scoreboard(str, score);
    write(fd, dest, my_strlen(dest));
}

char *get_score(void)
{
    int fd = open("scoreboard/score.txt", O_RDONLY);
    char *buf = malloc(sizeof(char) * 160);
    int len = 0;

    if (fd == -1)
        return NULL;
    len = read(fd, buf, 160);
    buf[len + 1] = '\0';
    return buf;
}