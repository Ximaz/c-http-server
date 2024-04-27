/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** get_index.c
*/

#include <stdlib.h>
#include "http.h"
#include "server.h"

void get_index(http_server_t *server, UNUSED http_client_t *client,
    UNUSED http_request_t *req, http_response_t *resp)
{
    char *full_uri_path = NULL;

    full_uri_path = get_uri_full_path(&(server->config), "/index.html",
        &(resp->status));
    get_http_uri_resource(full_uri_path, resp);
    free(full_uri_path);
    set_raw_http_header(&(resp->headers), "content-type",
        "text/html;charset=utf-8");
}
