/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** init_server.c
*/

#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include "http.h"
#include "server.h"

static int bind_socket(int socket, const char *host, int port)
{
    struct sockaddr_in addr = { 0 };
    socklen_t socklen = sizeof(struct sockaddr);

    addr.sin_addr.s_addr = inet_addr(host);
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    return bind(socket, (const struct sockaddr *) &addr, socklen);
}

static void free_hashmap_item(void *e)
{
    hashmap_item_t *header = (hashmap_item_t *) e;

    free(header->value);
    free(e);
}

static void setup_clients(http_server_t *server)
{
    int j = 0;
    int i = 0;
    http_client_t *client = NULL;

    for (; i < FD_SETSIZE; ++i) {
        client = &(server->clients[i]);
        for (j = 0; j < HASHMAP_SIZE; ++j) {
            client->request.headers[j].destroy = free_hashmap_item;
            client->response.headers[j].destroy = free_hashmap_item;
        }
        client->connected = 0;
    }
}

static void setup_router(http_server_t *server)
{
    int i = 0;
    http_method_t method = 0;

    for (; method < HTTP_METHODS_LIMIT; ++method)
        for (i = 0; i < HASHMAP_SIZE; ++i)
            server->router[method][i].destroy = free;
}

static void setup_server(http_server_t *server, const server_config_t *config)
{
    memcpy(&(server->config), config, sizeof(server_config_t));
    setup_clients(server);
    setup_router(server);
}

int init_server(http_server_t *server, const server_config_t *config)
{
    int reuse_sock = 1;

    server->socket = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (-1 == server->socket)
        return -1;
    if (-1 == setsockopt(server->socket, SOL_SOCKET, SO_REUSEADDR, &reuse_sock,
        sizeof(int)) ||
        -1 == bind_socket(server->socket, config->host, config->port) ||
        -1 == listen(server->socket, SOMAXCONN)) {
        close(server->socket);
        server->socket = -1;
        return -1;
    }
    setup_server(server, config);
    return 0;
}
