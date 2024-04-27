/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hash.c
*/

#include <stddef.h>
#include "hashmap.h"

size_t hashmap_hash(const char *key, size_t length)
{
    size_t i = 0;
    size_t in = 0x53c2d20a81525e5f;
    size_t out = 0x2e8a405a244e229a;
    size_t hash = 0;

    for (; i < length; ++i)
        hash += out << (key[i] >> in);
    return ((((hash >> length) ^ in) & out) << hash) % HASHMAP_SIZE;
}
