/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** run_server.c
*/

#include <arpa/inet.h>
#include <stddef.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include "http_server.h"

static void accept_client(http_server_t *server)
{
    struct sockaddr_in addr = { 0 };
    socklen_t socklen = sizeof(struct sockaddr_in);
    int client = accept(server->socket, (struct sockaddr *) &addr, &socklen);

    if (-1 != client) {
        server->clients[client] = 1;
        memset(server->requests[client].buffer, 0, sizeof(http_request_t));
        server->requests[client].length = 0;
        memset(server->responses[client].buffer, 0, sizeof(http_response_t));
        server->responses[client].length = 0;
    }
}

static void recv_requests(http_server_t *server, fd_set *rd)
{
    int i = 0;

    for (; i < FD_SETSIZE; ++i) {
        if (0 == FD_ISSET(i, rd))
            continue;
        if (i == server->socket)
            accept_client(server);
        else
            recv_request(server, i);
    }
}

static void send_responses(http_server_t *server, fd_set *wr)
{
    int i = 0;

    for (; i < FD_SETSIZE; ++i) {
        if (0 == FD_ISSET(i, wr))
            continue;
        send_response(server, i);
    }
}

static void prepare_fd_sets(fd_set rdwr[2], const http_server_t *server)
{
    int i = 0;

    FD_ZERO(&(rdwr[0]));
    FD_ZERO(&(rdwr[1]));
    FD_SET(server->socket, &(rdwr[0]));
    for (; i < FD_SETSIZE; ++i)
        if (1 == server->clients[i]) {
            FD_SET(i, &(rdwr[0]));
            FD_SET(i, &(rdwr[1]));
        }
}

int run_server(http_server_t *server)
{
    int status = -1;
    fd_set rdwr[2] = { 0 };
    struct timeval timeout = { 0, 0 };

    server->running = 1;
    while (1 == server->running) {
        prepare_fd_sets(rdwr, server);
        status = select(FD_SETSIZE, &(rdwr[0]), &(rdwr[1]), NULL, &timeout);
        if (-1 == status) {
            server->running = 0;
            return -1;
        }
        memset(&timeout, 0, sizeof(struct timeval));
        recv_requests(server, &(rdwr[0]));
        send_responses(server, &(rdwr[1]));
    }
    server->running = 0;
    return 0;
}
