/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** parse_uri.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "http_server.h"

static int remote_file_inclusion(const http_config_t *config, char const *path)
{
    return 0 != strncmp(path, config->root_path, config->root_path_len);
}

static int file_exists(const char *path)
{
    struct stat stats = { 0 };

    return -1 != stat(path, &stats);
}

char *parse_uri(const http_config_t *config, const char *uri, int *http_status)
{
    char *full_path = NULL;
    size_t full_path_len = 0;
    char real_path[PATH_MAX] = { 0 };
    char tmp[PATH_MAX] = { 0 };

    strncpy(tmp, config->root_path, config->root_path_len);
    strcat(tmp, uri);
    realpath(tmp, real_path);
    if (1 == remote_file_inclusion(config, tmp) || 0 == file_exists(tmp)) {
        *http_status = 404;
        return NULL;
    }
    *http_status = 200;
    full_path_len = strlen(tmp);
    full_path = strndup(tmp, full_path_len);
    return full_path;
}
