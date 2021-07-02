/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** lists
*/

#include "duck_hunt.h"

void add_shoted(shoted_l **head, shoted_t *shoted)
{
    shoted_l *node = malloc(sizeof(shoted_l));

    if (*head == NULL) {
        node->shoted = shoted;
        node->next = NULL;
        (*head) = node;
        return;
    }
    node->shoted = shoted;
    node->next = (*head);
    (*head) = node;
    return;
}

int delete_shoted(shoted_l **start, int branch)
{
    shoted_l *actual = *start;
    shoted_l *to_link = *start;

    if (branch == 0) {
        *start = (*start)->next;
        free_death(actual);
        return (0);
    }
    to_link = to_link->next;
    if (to_link != NULL)
        to_link = to_link->next;
    while (branch > 1 && to_link != NULL) {
        to_link = to_link->next;
        actual = actual->next;
        branch--;
    }
    free_death(actual->next);
    actual->next = to_link;
    return (0);
}