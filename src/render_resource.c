/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** render_resource.c
*/

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
    return 0 != strncmp(path, config->root_path.buffer,
        config->root_path.length);
}

static int file_exists(const char *path)
{
    struct stat stats = { 0 };

    return -1 != stat(path, &stats);
}

UNUSED static char *secured_get_uri_full_path(const server_config_t *config,
    const char *uri, http_status_t *http_status)
{
    char *full_path = NULL;
    size_t full_path_len = 0;
    char real_path[PATH_MAX] = { 0 };
    char tmp[PATH_MAX] = { 0 };

    strncpy(tmp, config->root_path.buffer, config->root_path.length);
    strcat(tmp, uri);
    realpath(tmp, real_path);
    if (1 == remote_file_inclusion(config, tmp) || 0 == file_exists(tmp)) {
        *http_status = HTTP_404;
        return NULL;
    }
    *http_status = HTTP_200;
    full_path_len = strlen(tmp);
    full_path = my_strndup(tmp, full_path_len);
    if (NULL == full_path)
        *http_status = HTTP_500;
    return full_path;
}

static void get_uri_full_path(const server_config_t *config,
    const char *uri, buffer_t *output)
{
    char real_path[PATH_MAX] = { 0 };
    char tmp[PATH_MAX] = { 0 };

    strncpy(tmp, config->root_path.buffer, config->root_path.length);
    strcat(tmp, uri);
    realpath(tmp, real_path);
    write_buffer(output, tmp, strlen(tmp));
}

void render_resource(http_server_t *server, http_response_t *resp,
    const char *path)
{
    buffer_t full_uri = { 0 };

    get_uri_full_path(&(server->config), path, &full_uri);
    read_file(full_uri.buffer, &(resp->content));
}
