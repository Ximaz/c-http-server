/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** buffer.h
*/

#ifndef __BUFFER_H_
    #define __BUFFER_H_
    #define BUFFER_SIZE (2 << 16)
    #include <stddef.h>

typedef struct s_buffer {
    char buffer[BUFFER_SIZE];
    unsigned int length;
} buffer_t;

void write_lower_buffer(buffer_t *buffer, const char *string, size_t length);

void write_buffer(buffer_t *buffer, const char *string, size_t length);

void empty_buffer(buffer_t *buffer);

#endif /* !__BUFFER_H_ */
