/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** handle_http_request.c
*/

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "http_server.h"
#include "string_utils.h"

static void read_resource(const char *path, http_response_t *resp)
{
    ssize_t bytes = -1;
    int fd = open(path, O_RDONLY);

    if (-1 == fd)
        return;
    bytes = read(fd, resp->buffer, sizeof(char) * BUFFER_SIZE);
    close(fd);
    if (0 < bytes) {
        resp->buffer[bytes] = 0;
        resp->length = bytes;
    }
}

void handle_http_request(const http_config_t *config,
    const http_request_t *req, http_response_t *resp)
{
    int http_status = 0;
    char *full_path = NULL;
    char **words = my_str_to_word_array(req->buffer, " ");

    if (NULL == words)
        return;
    full_path = parse_uri(config, words[1], &http_status);
    if (NULL == full_path) {
        destroy_word_array(words);
        return;
    }
    read_resource(full_path, resp);
    free(full_path);
    destroy_word_array(words);
    build_headers(config, resp, http_status);
}
