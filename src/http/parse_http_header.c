/*
** EPITECH PROJECT, 2024
** {Workshop} parse_header.c
** File description:
** parse_http_header.c
*/

#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "http.h"

http_header_t *parse_http_header(const buffer_t *raw)
{
    size_t i = 0;
    http_header_t *header = NULL;

    for (; i < raw->length; ++i) {
        if (0 != strncmp(&(raw->buffer[i]), ": ", 2))
            continue;
        if (0 == i)
            return NULL;
        header = calloc(1, sizeof(http_header_t));
        if (NULL == header)
            return NULL;
        write_buffer(&(header->key), raw->buffer, i);
        write_buffer(&(header->value), &(raw->buffer[i + 2]),
            strlen(&(raw->buffer[i + 2])));
        return header;
    }
    return NULL;
}
