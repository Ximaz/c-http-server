/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** destroy_http_response.c
*/

#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "http.h"
#include "list.h"

void destroy_http_response(http_response_t *resp)
{
    list_clear(&(resp->headers));
    empty_buffer(&(resp->content));
    empty_buffer(&(resp->raw));
}
