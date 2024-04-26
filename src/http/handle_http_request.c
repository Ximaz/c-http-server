/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** handle_http_request.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include "http.h"
#include "server.h"

void handle_http_request(const server_config_t *config, http_request_t *req,
    http_response_t *resp)
{
    char *full_uri_path = NULL;

    parse_http_request(&(req->raw), req);
    full_uri_path = get_uri_full_path(config, req->uri, &(resp->status));
    get_http_uri_resource(full_uri_path, resp);
    free(full_uri_path);
    set_http_header(&(resp->headers), "Content-Type",
        "text/html;charset=utf-8");
    render_response(config, resp);
}
