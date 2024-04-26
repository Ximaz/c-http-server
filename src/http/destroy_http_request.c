/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** destroy_http_request.c
*/

#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "http.h"
#include "list.h"

void destroy_http_request(http_request_t *req)
{
    memset(req->uri, 0, sizeof(char) * PATH_MAX);
    list_clear(&(req->headers));
    empty_buffer(&(req->body));
    empty_buffer(&(req->raw));
}
