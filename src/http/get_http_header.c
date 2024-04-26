/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** get_http_header.c
*/

#include <stddef.h>
#include <string.h>
#include "buffer.h"
#include "http.h"

buffer_t *get_http_header(const http_headers_t *headers, const char *key)
{
    http_header_t *header = hashmap_find(headers, key);

    return &(header->value);
}
