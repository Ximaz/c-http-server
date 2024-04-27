/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** server.h
*/

#ifndef __http_server_H_
    #define __http_server_H_

    #define HTTP_PORT 8080
    #define CLIENT_CONNECTED 1
    #define CLIENT_DISCONNECTED -1

    #include <stddef.h>
    #include <sys/select.h>
    #include "buffer.h"
    #include "compat.h"
    #include "hashmap.h"
    #include "http.h"

typedef struct s_http_config {
    int port;
    char const *host;
    buffer_t root_path;
    buffer_t asset_path;
    http_version_t http_version;
} server_config_t;

typedef struct s_http_client {
    http_request_t request;
    http_response_t response;
    int connected;
} http_client_t;

struct s_http_server;

typedef void (*route_handler_t)(struct s_http_server *server,
    http_client_t *client, http_request_t *req, http_response_t *res);

typedef hashmap_t http_routes_t; /* { route: handler } */

typedef http_routes_t http_router_t[HTTP_METHODS_LIMIT];

typedef struct s_http_server {
    int socket;
    int running;
    http_client_t clients[FD_SETSIZE];
    server_config_t config;
    http_router_t router;
} http_server_t;

int init_server(http_server_t *server, const server_config_t *config);

int run_server(http_server_t *server);

void recv_request(http_server_t *server, int client);

void send_response(http_server_t *server, int client);

void handle_http_request(http_server_t *server, http_client_t *client,
    http_request_t *req, http_response_t *resp);

void close_client(http_server_t *server, int client);

void destroy_server(http_server_t *server);

void read_file(const char *path, buffer_t *buffer);

int render_resource(http_server_t *server, http_response_t *resp,
    const char *path);

int render_asset(http_server_t *server, http_response_t *resp,
    const char *path);

void render_response(const server_config_t *config, http_response_t *resp);

void router_new(http_router_t *router);

int router_register_route(http_router_t *router, http_method_t method,
    const char *route, route_handler_t handler);

route_handler_t *router_find_route(const http_router_t *router,
    http_method_t method, const char *route);

void router_destroy(http_router_t *router);

#endif /* !__http_server_H_ */
