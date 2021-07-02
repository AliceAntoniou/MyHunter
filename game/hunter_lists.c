/*
** EPITECH PROJECT, 2020
** duck hunt
** File description:
** lists
*/

#include "duck_hunt.h"

void add_duck(duck_l **head, duck_t *duck)
{
    duck_l *node = malloc(sizeof(duck_l));

    if (*head == NULL) {
        node->duck = duck;
        node->next = NULL;
        (*head) = node;
        return;
    }
    node->duck = duck;
    if (rand() % 30 == 29)
        node->duck->color = 1;
    node->next = (*head);
    (*head) = node;
    return;
}

int delete_duck(duck_l **start, int branch)
{
    duck_l *actual = *start;
    duck_l *to_link = *start;

    if (branch == 0) {
        *start = (*start)->next;
        free_duck(actual);
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
    free_duck(actual->next);
    actual->next = to_link;
    return (0);
}

void add_child(child_l **head, child_t *child)
{
    child_l *node = malloc(sizeof(child_l));

    if (*head == NULL) {
        node->child = child;
        node->next = NULL;
        (*head) = node;
        return;
    }
    node->child = child;
    node->next = (*head);
    (*head) = node;
    return;
}

int delete_child(child_l **start, int branch)
{
    child_l *actual = *start;
    child_l *to_link = *start;

    if (branch == 0) {
        *start = (*start)->next;
        free_child(actual);
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
    free_child(actual->next);
    actual->next = to_link;
    return (0);
}