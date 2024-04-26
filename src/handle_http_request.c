/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** handle_http_request.c
*/

#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "http.h"
#include "server.h"

void handle_http_request(http_server_t *server, http_client_t *client,
    http_request_t *req, http_response_t *resp)
{
    route_handler_t handler = NULL;

    parse_http_request(&(req->raw), req);
    resp->version = server->config.http_version;
    handler = (route_handler_t)
        router_find_route(&(server->router), req->method, req->uri);
    if (NULL != handler)
        handler(server, client, req, resp);
    else {
        resp->status = HTTP_404;
        http_error_file_not_found(resp);
    }
    render_response(&(server->config), resp);
    destroy_http_request(req);
}
