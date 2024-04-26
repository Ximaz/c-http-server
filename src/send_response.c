/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** send_response.c
*/

#include <sys/socket.h>
#include <unistd.h>
#include "http.h"
#include "server.h"

void send_response(http_server_t *server, int socket)
{
    http_client_t *client = &(server->clients[socket]);
    http_response_t *resp = &(client->response);

    write(socket, resp->raw.buffer, sizeof(char) * resp->raw.length);
    close_client(server, socket);
    destroy_http_response(resp);
}
