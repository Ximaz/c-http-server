/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** render_http_response.c
*/

#include <string.h>
#include "buffer.h"
#include "hashmap.h"
#include "http.h"
#include "list.h"
#include "server.h"

static void write_metadata(const server_config_t *config,
    http_response_t *resp)
{
    const buffer_t http_version = HTTP_VERSIONS[config->http_version];

    write_buffer(&(resp->raw), http_version.buffer, http_version.length);
    write_buffer(&(resp->raw), " ", 1);
    write_buffer(&(resp->raw), HTTP_STATUS[resp->status], 3);
    write_buffer(&(resp->raw), HTTP_LINE_SEP, HTTP_LINE_SEP_LEN);
}

static void write_header(http_response_t *resp, const http_header_t *header)
{
    write_buffer(&(resp->raw), header->key.buffer, header->key.length);
    write_buffer(&(resp->raw), ": ", 2);
    write_buffer(&(resp->raw), header->value.buffer, header->value.length);
    write_buffer(&(resp->raw), HTTP_LINE_SEP, HTTP_LINE_SEP_LEN);
}

static void write_headers_list(http_response_t *resp,
    const list_t *headers)
{
    long i = 0;
    hashmap_entry_t *entry = NULL;
    http_header_t *header = NULL;
    long headers_count = list_count(headers);

    for (; i < headers_count; ++i) {
        entry = list_value_at(headers, i);
        if (NULL == entry)
            continue;
        header = entry->value;
        write_header(resp, header);
    }
}

static void write_headers(http_response_t *resp)
{
    int i = 0;

    for (; i < HASHMAP_SIZE; ++i)
        write_headers_list(resp, &(resp->headers.buckets[i]));
}

void render_response(const server_config_t *config, http_response_t *resp)
{
    write_metadata(config, resp);
    write_headers(resp);
    write_buffer(&(resp->raw), HTTP_LINE_SEP, HTTP_LINE_SEP_LEN);
    write_buffer(&resp->raw, resp->content.buffer, resp->content.length);
}
