/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "compat.h"
#include "http_server.h"

static http_server_t server = { 0 };

static void handle_signal(int signal)
{
    (void)(signal);
    server.running = 0;
}

static void prepare_config(http_config_t *config,
    const char *root_path, const char *index_path)
{
    char tmp[PATH_MAX] = { 0 };

    realpath(root_path, tmp);
    config->root_path_len = strlen(tmp);
    strncpy(config->root_path, tmp, config->root_path_len);
    memset(tmp, 0, sizeof(char) * config->root_path_len);
    strncat(tmp, config->root_path, sizeof(char) * config->root_path_len);
    tmp[config->root_path_len] = '/';
    strncat(tmp, index_path, sizeof(char) * strlen(index_path));
    realpath(tmp, config->index_path);
    config->index_path_len = strlen(config->index_path);
}

int main(void)
{
    http_config_t config = { .port = HTTP_PORT, .host = "0.0.0.0" };

    signal(SIGINT, handle_signal);
    prepare_config(&config, "./app", "/index.html");
    if (-1 == init_server(&server, &config))
        return 84;
    if (-1 == run_server(&server))
        return 84;
    destroy_server(&server);
    return 0;
}
