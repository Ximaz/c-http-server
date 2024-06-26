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
    set_raw_http_header(&(resp->headers), "content-type",
        "text/html;charset=utf-8");
    set_raw_http_header(&(resp->headers), "connection", "close");
    render_page(server, resp, "/index.html");
}
