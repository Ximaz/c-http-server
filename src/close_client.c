/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** close_client.c
*/

#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include "buffer.h"
#include "http_server.h"

void close_client(http_server_t *server, int client)
{
    http_request_t *req = &(server->requests[client]);
    http_response_t *resp = &(server->responses[client]);

    empty_buffer(req);
    empty_buffer(resp);
    shutdown(client, SHUT_RDWR);
    close(client);
    server->clients[client] = -1;
}
