/*
** EPITECH PROJECT, 2020
** criterion
** File description:
** test
*/

#include <criterion/criterion.h>

int set_scoreboard(char *str, char *score);

Test(test_1, set_scoreboard)
{
    char *rt = "132413\n7653\n973\n12\n2\n";
    char *str = "132413\n3498\n7653\n973\n12\n";
    char *score = "3498";

    set_scoreboard(str, score);
    cr_assert_str_eq(rt, "654");
}