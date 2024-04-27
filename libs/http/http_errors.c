/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** http_errors.c
*/

#include "buffer.h"
#include "http.h"

void http_error_file_not_found(http_response_t *resp)
{
    write_buffer(&(resp->content), "<h1>404 - File Not Found</h1>", 29);
}

void http_error_internal_error(http_response_t *resp)
{
    write_buffer(&(resp->content), "<h1>500 - Internal Error</h1>", 29);
}
