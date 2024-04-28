/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_clear.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "hashmap.h"

void hashmap_clear(hashmap_t *hashmap)
{
    size_t i = 0;

    for (; i < HASHMAP_SIZE; ++i)
        hashmap_entries_destroy(&(hashmap->buckets[i]), hashmap->destroy);
}
