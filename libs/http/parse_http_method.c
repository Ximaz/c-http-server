/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** parse_http_method.c
*/

#include <string.h>
#include "http.h"

int parse_http_method(const char *method, http_request_t *output)
{
    http_method_t method_value = 0;

    for (; method_value < HTTP_METHODS_LIMIT; ++method_value)
        if (0 == strcmp(HTTP_METHODS[method_value], method)) {
            output->method = method_value;
            return 0;
        }
    return -1;
}
