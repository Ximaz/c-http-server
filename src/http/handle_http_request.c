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

static void not_found(http_response_t *resp)
{
    write_buffer(resp, "<h1>404 - Not Found</h1>", 24);
}

static void internal_error(http_response_t *resp)
{
    write_buffer(resp, "<h1>500 - Internal Error</h1>", 29);
}

static void read_resource(const char *path, http_response_t *resp,
    int http_status)
{
    ssize_t bytes = -1;
    int fd = -1;

    if (404 == http_status) {
        not_found(resp);
        return;
    }
    if (500 == http_status) {
        internal_error(resp);
        return;
    }
    fd = open(path, O_RDONLY);
    if (-1 != fd) {
        bytes = read(fd, resp->buffer, sizeof(char) * BUFFER_SIZE);
        close(fd);
        if (0 < bytes)
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
    read_resource(full_path, resp, http_status);
    free(full_path);
    destroy_word_array(words);
    build_headers(config, resp, http_status);
}
