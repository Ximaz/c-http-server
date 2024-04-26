/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** destroy_http_response.c
*/

#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "hashmap.h"
#include "http.h"

void destroy_http_response(http_response_t *resp)
{
    hashmap_destroy(&(resp->headers));
    empty_buffer(&(resp->content));
    empty_buffer(&(resp->raw));
}
