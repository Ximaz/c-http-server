/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** http_server.h
*/

#ifndef __http_server_H_
    #define __http_server_H_

    #define HTTP_PORT 8080
    #define BUFFER_SIZE (2 << 16)

    #include <limits.h>
    #include <stddef.h>
    #include <sys/select.h>

typedef struct s_buffer {
    char buffer[BUFFER_SIZE];
    unsigned int length;
} buffer_t;

typedef buffer_t http_request_t;
typedef buffer_t http_response_t;

typedef struct s_http_config {
    int port;
    char const *host;
    char root_path[PATH_MAX];
    size_t root_path_len;
    char index_path[PATH_MAX];
    size_t index_path_len;
} http_config_t;

typedef struct s_http_server {
    int socket;
    int running;
    int clients[FD_SETSIZE];
    http_request_t requests[FD_SETSIZE];
    http_response_t responses[FD_SETSIZE];
    http_config_t config;
} http_server_t;

int init_server(http_server_t *server, const http_config_t *config);

int run_server(http_server_t *server);

void recv_request(http_server_t *server, int client);

void send_response(http_server_t *server, int client);

void handle_http_request(const http_config_t *config,
    const http_request_t *req, http_response_t *resp);

void destroy_server(http_server_t *server);

char *parse_uri(const http_config_t *config, const char *uri, int *status);

void build_headers(const http_config_t *config, http_response_t *resp,
    int http_status);

#endif /* !__http_server_H_ */
