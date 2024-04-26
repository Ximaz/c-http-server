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

void make_http_header(http_header_t *header, const char *key,
    const char *value)
{
    write_lower_buffer(&(header->key), key, strlen(key));
    write_buffer(&(header->value), value, strlen(value));
}

int set_http_header(http_headers_t *headers, http_header_t *header)
{
    hashmap_item_t *item = calloc(1, sizeof(hashmap_item_t));

    if (NULL == item)
        return -1;
    item->key = header->key.buffer;
    item->value = header;
    if (-1 == hashmap_insert(headers, item)) {
        free(header);
        return -1;
    }
    return 0;
}
