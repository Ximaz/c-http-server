/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** recv_request.c
*/

#include <string.h>
#include <unistd.h>
#include "http_server.h"

void recv_request(http_server_t *server, int client)
{
    http_request_t req = server->requests[client];
    ssize_t bytes = read(client, req.buffer, sizeof(char) * BUFFER_SIZE);

    if (-1 == bytes)
        return;
    if (0 == bytes) {
        close(client);
        server->clients[client] = -1;
    }
    req.length = (unsigned int) bytes;
    handle_http_request(&(server->config), &req, &(server->responses[client]));
}
