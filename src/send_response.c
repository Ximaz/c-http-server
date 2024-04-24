/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** send_response.c
*/

#include <sys/socket.h>
#include <unistd.h>
#include "http_server.h"

void send_response(http_server_t *server, int client)
{
    http_response_t resp = server->responses[client];

    write(client, resp.buffer, sizeof(char) * resp.length);
    shutdown(client, SHUT_RDWR);
    close(client);
    server->clients[client] = -1;
}
