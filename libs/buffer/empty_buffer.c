/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** empty_buffer.c
*/

#include "buffer.h"
#include <string.h>

void empty_buffer(buffer_t *buffer)
{
    memset(buffer->buffer, 0, sizeof(char) * buffer->length);
    buffer->length = 0;
}
