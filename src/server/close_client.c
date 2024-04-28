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
#include "http.h"
#include "server.h"

void close_client(http_server_t *server, int socket)
{
    http_client_t *client = &(server->clients[socket]);

    shutdown(socket, SHUT_RDWR);
    close(socket);
    client->connected = 0;
    destroy_http_request(&(client->request));
    destroy_http_response(&(client->response));
}
