/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** get_index.c
*/

#include <stdlib.h>
#include "http.h"
#include "server.h"

static void set_header(http_response_t *resp, const char *key,
    const char *value)
{
    http_header_t *header = calloc(1, sizeof(http_header_t));

    if (NULL != header) {
        make_http_header(header, key, value);
        if (-1 == set_http_header(&(resp->headers), header))
            free(header);
    }
}

void get_index(http_server_t *server, UNUSED http_client_t *client,
    UNUSED http_request_t *req, http_response_t *resp)
{
    char *full_uri_path = NULL;

    full_uri_path = get_uri_full_path(&(server->config), "/index.html",
        &(resp->status));
    get_http_uri_resource(full_uri_path, resp);
    free(full_uri_path);
    set_header(resp, "content-type", "text/html;charset=utf-8");
}
