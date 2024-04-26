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
#include "buffer.h"
#include "http.h"
#include "server.h"

void recv_request(http_server_t *server, int socket)
{
    http_client_t *client = &(server->clients[socket]);
    http_request_t *req = &(client->request);
    http_response_t *resp = &(client->response);
    ssize_t bytes = -1;

    empty_buffer(&(req->raw));
    empty_buffer(&(resp->raw));
    bytes = read(socket, req->raw.buffer, sizeof(char) * BUFFER_SIZE);
    if (-1 == bytes)
        return;
    if (0 == bytes) {
        close_client(server, socket);
        return;
    }
    req->raw.length = (unsigned int) bytes;
    handle_http_request(&(server->config), req, resp);
}
