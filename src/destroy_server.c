/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** destroy_server.c
*/

#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include "http_server.h"

void destroy_server(http_server_t *server)
{
    int i = 0;

    for (; i < FD_SETSIZE; ++i)
        if (1 == server->clients[i]) {
            shutdown(i, SHUT_RDWR);
            close(i);
            server->clients[i] = -1;
            memset(server->requests[i].buffer, 0, sizeof(http_request_t));
            server->requests[i].length = 0;
            memset(server->responses[i].buffer, 0, sizeof(http_response_t));
            server->responses[i].length = 0;
        }
    close(server->socket);
    server->socket = -1;
}
