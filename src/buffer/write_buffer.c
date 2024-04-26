/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** write_buffer.c
*/

#include "buffer.h"
#include <string.h>

void write_buffer(buffer_t *buffer, const char *string, size_t length)
{
    if (BUFFER_SIZE >= (buffer->length + length)) {
        strncat(buffer->buffer, string, sizeof(char) * length);
        buffer->length += length;
    }
}
