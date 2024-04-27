/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** my_strlowercase.c
*/

#include <stddef.h>

void my_strlowercase(char *string, size_t length)
{
    size_t i = 0;

    for (; i < length; ++i)
        if ('A' <= string[i] && 'Z' >= string[i])
            string[i] += 32;
}
