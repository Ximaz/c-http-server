/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** recv_request.c
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "http_server.h"

void recv_request(http_server_t *server, int client)
{
    http_request_t *req = &(server->requests[client]);
    http_response_t *resp = &(server->responses[client]);
    ssize_t bytes = -1;

    empty_buffer(req);
    empty_buffer(resp);
    bytes = read(client, req->buffer, sizeof(char) * BUFFER_SIZE);
    if (-1 == bytes)
        return;
    if (0 == bytes) {
        close_client(server, client);
        return;
    }
    req->length = (unsigned int) bytes;
    handle_http_request(&(server->config), req, resp);
}
