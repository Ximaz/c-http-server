/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** main.c
*/

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "compat.h"
#include "buffer.h"
#include "http.h"
#include "routes.h"
#include "server.h"

#ifndef CRITERION_NO_MAIN

static http_server_t server = { 0 };

static void handle_signal(int signal)
{
    (void)(signal);
    server.running = 0;
}

static void prepare_config(server_config_t *config,
    const char *root_path)
{
    char tmp[PATH_MAX] = { 0 };

    realpath(root_path, tmp);
    write_buffer(&(config->root_path), tmp, strlen(tmp));
    memset(tmp, 0, sizeof(char) * config->root_path.length);
    tmp[config->root_path.length] = '/';
}

static void setup_routes(http_server_t *server)
{
    router_register_route(&(server->router), HTTP_GET, "/", &get_index);
}

int main(void)
{
    server_config_t config = { 0 };

    config.port = HTTP_PORT;
    config.host = "0.0.0.0";
    config.http_version = HTTP_2_0;
    signal(SIGINT, handle_signal);
    prepare_config(&config, "./app");
    if (-1 == init_server(&server, &config))
        return 84;
    setup_routes(&server);
    if (-1 == run_server(&server))
        return 84;
    destroy_server(&server);
    return 0;
}

#endif /* !CRITERION_NO_MAIN */
