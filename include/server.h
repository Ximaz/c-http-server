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
    #include "http.h"

/* todo: mettre root_path et index_path en buffer_t */
typedef struct s_http_config {
    int port;
    char const *host;
    buffer_t root_path;
    buffer_t index_path;
    http_version_t http_version;
} server_config_t;

typedef struct s_http_client {
    http_request_t request;
    http_response_t response;
    int connected;
} http_client_t;

typedef struct s_http_server {
    int socket;
    int running;
    http_client_t clients[FD_SETSIZE];
    server_config_t config;
} http_server_t;

int init_server(http_server_t *server, const server_config_t *config);

int run_server(http_server_t *server);

void recv_request(http_server_t *server, int client);

void send_response(http_server_t *server, int client);

void handle_http_request(const server_config_t *config, http_request_t *req,
    http_response_t *resp);

void close_client(http_server_t *server, int client);

void destroy_server(http_server_t *server);

char *get_uri_full_path(const server_config_t *config, const char *uri,
    http_status_t *http_status);

void render_response(const server_config_t *config, http_response_t *resp);

#endif /* !__http_server_H_ */
