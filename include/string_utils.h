/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** string_utils.h
*/

#ifndef __STRING_UTILS_H_
    #define __STRING_UTILS_H_

    #include <stddef.h>
    #include "compat.h"

char *strndup(char const *string, size_t length);

char **my_str_to_word_array(char const *string, char const *sep);

void destroy_word_array(char **word_array);

#endif /* !__STRING_UTILS_H_ */
