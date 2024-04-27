/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** headers_builder.c
*/

#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "http.h"

int set_http_header(http_headers_t *headers, const char *key,
    http_header_t *header)
{
    return hashmap_set(headers, key, header);
}

int set_raw_http_header(http_headers_t *headers, const char *key,
    const char *value)
{
    http_header_t *header = calloc(1, sizeof(http_header_t));

    if (NULL == header)
        return -1;
    write_lower_buffer(&(header->key), key, strlen(key));
    write_buffer(&(header->value), value, strlen(value));
    if (-1 == set_http_header(headers, key, header)) {
        free(header);
        return -1;
    }
    return 0;
}
