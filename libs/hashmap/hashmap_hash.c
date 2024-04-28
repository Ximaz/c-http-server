/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hash.c
*/

#include <stddef.h>
#include "hashmap.h"

hash_t hashmap_hash(const char *key)
{
    size_t i = 0;
    size_t in = 0x53c2d20a81525e5f;
    size_t out = 0x2e8a405a244e229a;
    hash_t hash = 0;

    for (; 0 != key[i]; ++i)
        hash += out << (key[i] >> in);
    return ((((hash >> i) ^ in) & out) << hash) % HASHMAP_SIZE;
}
