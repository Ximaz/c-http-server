/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** write_buffer.c
*/

#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "string_utils.h"

void write_lower_buffer(buffer_t *buffer, const char *string, size_t length)
{
    char *tmp = NULL;

    if (BUFFER_SIZE < (buffer->length + length))
        return;
    tmp = my_strndup(string, length);
    if (NULL == tmp)
        return;
    my_strlowercase(tmp, length);
    strncat(buffer->buffer, tmp, sizeof(char) * length);
    free(tmp);
    buffer->length += length;
}

void write_buffer(buffer_t *buffer, const char *string, size_t length)
{
    if (BUFFER_SIZE >= (buffer->length + length)) {
        strncat(buffer->buffer, string, sizeof(char) * length);
        buffer->length += length;
    }
}
