/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** init_server.c
*/

#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "http_server.h"

static int bind_socket(int socket, const char *host, int port)
{
    struct sockaddr_in addr = { 0 };
    socklen_t socklen = sizeof(struct sockaddr);

    addr.sin_addr.s_addr = inet_addr(host);
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    return bind(socket, (const struct sockaddr *) &addr, socklen);
}

int init_server(http_server_t *server, const http_config_t *config)
{
    server->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (-1 == server->socket)
        return -1;
    if (-1 == bind_socket(server->socket, config->host, config->port) ||
        -1 == listen(server->socket, SOMAXCONN)) {
        close(server->socket);
        server->socket = -1;
        return -1;
    }
    memcpy(&(server->config), config, sizeof(http_config_t));
    return 0;
}
