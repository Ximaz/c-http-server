/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include <string.h>
#include "string_utils.h"

static size_t count_blocks(char const *string, char const *sep, size_t sep_len)
{
    size_t count = 1;
    char const *tmp = strstr(string, sep);

    while (NULL != tmp) {
        tmp = strstr(tmp + sep_len, sep);
        ++count;
    }
    return count;
}

static char *new_block(char const *string, char const *sep, size_t *len)
{
    char const *tmp = strstr(string, sep);

    if (NULL == tmp) {
        *len = 0;
        return NULL;
    }
    *len = tmp - string;
    return my_strndup(string, *len);
}

char **my_str_to_word_array(char const *string, char const *sep)
{
    size_t cursor = 0;
    size_t sep_len = strlen(sep);
    char *block = NULL;
    size_t block_idx = 0;
    size_t block_len = 0;
    size_t blocks_count = count_blocks(string, sep, sep_len);
    char **blocks = (char **) calloc(blocks_count + 1, sizeof(char *));

    if (NULL == blocks)
        return NULL;
    block = new_block(&string[cursor], sep, &block_len);
    while (NULL != block) {
        blocks[block_idx] = block;
        ++block_idx;
        cursor += block_len + sep_len;
        block = new_block(&string[cursor], sep, &block_len);
    }
    blocks[block_idx] = my_strndup(&string[cursor], strlen(&string[cursor]));
    return blocks;
}

void destroy_word_array(char **word_array)
{
    size_t i = 0;

    if (NULL == word_array)
        return;
    while (NULL != word_array[i]) {
        free(word_array[i]);
        ++i;
    }
    free(word_array);
}
