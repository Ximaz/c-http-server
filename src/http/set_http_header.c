/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** headers_builder.c
*/

#include <stdlib.h>
#include <string.h>
#include "http.h"
#include "list.h"

void set_http_header(http_headers_t *headers, const char *key,
    const char *value)
{
    http_header_t *header = calloc(1, sizeof(http_header_t));

    if (NULL != header) {
        write_buffer(&(header->key), key, strlen(key));
        write_buffer(&(header->value), value, strlen(value));
        if (-1 == list_push_back(headers, (void *) header))
            free(header);
    }
}
