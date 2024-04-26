/*
** EPITECH PROJECT, 2024
** {Workshop} headers_parser.c
** File description:
** parse_http_request.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "compat.h"
#include "http.h"
#include "string_utils.h"

static int parse_http_metadata(const buffer_t *raw, http_request_t *output)
{
    int errors[3] = { -1, -1, -1 };
    char **values = my_str_to_word_array(raw->buffer, " ");

    if (NULL == values)
        return -1;
    if (NULL == values[0] || NULL == values[1] || NULL == values[2]) {
        destroy_word_array(values);
        return -1;
    }
    errors[0] = parse_http_method(values[0], output);
    errors[1] = parse_http_uri(values[1], output);
    errors[2] = parse_http_version(values[2], output);
    destroy_word_array(values);
    return (0 == errors[0] && 0 == errors[1] && 0 == errors[2]) - 1;
}

static int parse_line(const char *line, http_request_t *output, int is_meta)
{
    http_header_t *header = NULL;
    buffer_t buffer = { 0 };

    empty_buffer(&buffer);
    write_buffer(&buffer, line, strlen(line));
    if (1 == is_meta)
        return parse_http_metadata(&buffer, output);
    header = parse_http_header(&buffer);
    if (NULL == header)
        return -1;
    if (-1 == set_http_header(&(output->headers), header)) {
        free(header);
        return -1;
    }
    return 0;
}

static void parse_http_body(http_request_t *output, char **lines,
    size_t line_idx)
{
    for (; NULL != lines[line_idx]; ++line_idx) {
        write_buffer(&(output->body), lines[line_idx],
            strlen(lines[line_idx]));
        write_buffer(&(output->body), HTTP_LINE_SEP, 2);
    }
}

void parse_http_request(const buffer_t *raw, http_request_t *output)
{
    size_t line_idx = 1;
    char **lines = my_str_to_word_array(raw->buffer, HTTP_LINE_SEP);

    if (NULL == lines)
        return;
    if (-1 == parse_line(lines[0], output, 1)) {
        destroy_word_array(lines);
        return;
    }
    for (; NULL != lines[line_idx] && 0 != *(lines[line_idx]); ++line_idx)
        if (-1 == parse_line(lines[line_idx], output, 0)) {
            destroy_word_array(lines);
            return;
        }
    if (NULL != lines[line_idx])
        parse_http_body(output, lines, line_idx + 1);
    destroy_word_array(lines);
}
