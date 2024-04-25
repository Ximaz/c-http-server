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
        if (CLIENT_CONNECTED == server->clients[i])
            close_client(server, i);
    close(server->socket);
    server->socket = -1;
}
