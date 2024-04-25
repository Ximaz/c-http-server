/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** headers_builder.c
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "http_server.h"

static void http_status_to_str(char *buffer, int http_status, int i)
{
    if (10 > http_status) {
        *buffer = (http_status + '0');
        return;
    }
    ++i;
    http_status_to_str(buffer, http_status / 10, i);
    http_status_to_str(buffer + i, http_status % 10, i);
}

static void headers_to_response(http_response_t *resp, const char *headers,
    size_t headers_len)
{
    http_response_t tmp = { 0 };

    write_buffer(&tmp, headers, headers_len);
    write_buffer(&tmp, resp->buffer, resp->length);
    empty_buffer(resp);
    write_buffer(resp, tmp.buffer, tmp.length);
}

static void set_header_response(buffer_t *buffer, int http_status)
{
    char http_status_str[3] = { 0 };

    write_buffer(buffer, "HTTP/1.1 ", 9);
    http_status_to_str(http_status_str, http_status, 0);
    write_buffer(buffer, http_status_str, 3);
    write_buffer(buffer, "\r\n", 2);
}

static void set_header(buffer_t *headers, const char *key, const char *value)
{
    write_buffer(headers, key, strlen(key));
    write_buffer(headers, ": ", 2);
    write_buffer(headers, value, strlen(value));
    write_buffer(headers, "\r\n", 2);
}

void build_headers(const http_config_t *config, http_response_t *resp,
    int http_status)
{
    buffer_t headers = { 0 };

    (void)(config);
    set_header_response(&headers, http_status);
    set_header(&headers, "Content-Type", "charset=utf-8");
    write_buffer(&headers, "\r\n", 2);
    headers_to_response(resp, headers.buffer, headers.length);
}
