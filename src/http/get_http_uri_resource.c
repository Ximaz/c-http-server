/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** get_http_uri_resource.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "buffer.h"
#include "http.h"

static int error_handling(http_response_t *resp)
{
    int i = 0;

    for (; NULL != HTTP_ERRORS[i].handler; ++i)
        if (HTTP_ERRORS[i].error_code == resp->status) {
            HTTP_ERRORS[i].handler(resp);
            return 1;
        }
    return 0;
}

void get_http_uri_resource(const char *path, http_response_t *resp)
{
    ssize_t bytes = -1;
    int fd = -1;

    if (1 == error_handling(resp))
        return;
    fd = open(path, O_RDONLY);
    if (-1 != fd) {
        bytes = read(fd, resp->content.buffer, sizeof(char) * BUFFER_SIZE);
        close(fd);
        if (0 < bytes)
            resp->content.length = bytes;
    }
}
