/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** read_file.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "buffer.h"

void read_file(const char *path, buffer_t *buffer)
{
    ssize_t bytes = -1;
    int fd = open(path, O_RDONLY);

    if (-1 != fd) {
        bytes = read(fd, buffer->buffer, sizeof(char) * BUFFER_SIZE);
        close(fd);
        if (0 < bytes)
            buffer->length = bytes;
    }
}
