/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** parse_http_method.c
*/

#include <string.h>
#include "http.h"

int parse_http_uri(const char *uri, http_request_t *output)
{
    size_t length = strlen(uri);

    memset(output->uri, 0, sizeof(char) * PATH_MAX);
    if (PATH_MAX < length)
        return -1;
    strncpy(output->uri, uri, sizeof(char) * PATH_MAX);
    return 0;
}
