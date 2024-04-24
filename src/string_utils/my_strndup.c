/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** my_strndup.c
*/

#include <stdlib.h>
#include <string.h>

char *strndup(char const *string, size_t length)
{
    char *block = NULL;

    if (1 == (length >> 63))
        return NULL;
    block = (char *) calloc(length + 1, sizeof(char));
    if (NULL == block)
        return NULL;
    strncpy(block, string, length);
    return block;
}
