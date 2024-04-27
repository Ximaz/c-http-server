/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** render_resource.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "compat.h"
#include "http.h"
#include "server.h"
#include "string_utils.h"

static int remote_file_inclusion(const server_config_t *config,
    char const *path)
{
    return 0 != strncmp(config->root_path.buffer, path,
        config->root_path.length);
}

static int file_exists(const char *path)
{
    struct stat stats = { 0 };

    return -1 != stat(path, &stats);
}

static int secured_get_uri_full_path(const server_config_t *config,
    const char *uri, buffer_t *output)
{
    size_t real_path_length = 0;
    char real_path[PATH_MAX] = { 0 };
    char tmp[PATH_MAX] = { 0 };

    empty_buffer(output);
    strncpy(tmp, config->root_path.buffer, config->root_path.length);
    strcat(tmp, uri);
    realpath(tmp, real_path);
    real_path_length = strlen(real_path);
    if (PATH_MAX < real_path_length ||
        1 == remote_file_inclusion(config, real_path) ||
        0 == file_exists(real_path))
        return -1;
    write_buffer(output, real_path, real_path_length);
    return 0;
}

static int get_uri_full_path(const server_config_t *config,
    const char *uri, buffer_t *output)
{
    size_t real_path_length = 0;
    char real_path[PATH_MAX] = { 0 };
    char tmp[PATH_MAX] = { 0 };

    empty_buffer(output);
    strncpy(tmp, config->root_path.buffer, config->root_path.length);
    strcat(tmp, uri);
    realpath(tmp, real_path);
    real_path_length = strlen(real_path);
    if (PATH_MAX < real_path_length ||
        0 == file_exists(real_path))
        return -1;
    write_buffer(output, real_path, real_path_length);
    return 0;
}

int render_resource(http_server_t *server, http_response_t *resp,
    const char *path)
{
    buffer_t full_uri = { 0 };

    if (-1 == get_uri_full_path(&(server->config), path, &full_uri))
        return -1;
    resp->status = HTTP_200;
    read_file(full_uri.buffer, &(resp->content));
    return 0;
}

int render_asset(http_server_t *server, http_response_t *resp,
    const char *path)
{
    buffer_t full_uri = { 0 };

    if (-1 == secured_get_uri_full_path(&(server->config), path, &full_uri))
        return -1;
    if (0 != strncmp(server->config.asset_path.buffer, full_uri.buffer,
        server->config.asset_path.length))
        return -1;
    resp->status = HTTP_200;
    read_file(full_uri.buffer, &(resp->content));
    return 0;
}
