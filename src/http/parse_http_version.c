/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** parse_http_version.c
*/

#include <string.h>
#include "http.h"

int parse_http_version(const char *version, http_request_t *output)
{
    http_version_t version_value = 0;

    for (; version_value < HTTP_VERSIONS_LIMIT; ++version_value)
        if (0 == strcmp(HTTP_VERSIONS[version_value].buffer, version)) {
            output->version = version_value;
            return 0;
        }
    return -1;
}
