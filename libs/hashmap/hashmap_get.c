/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_get.c
*/

#include <stddef.h>
#include "hashmap.h"

void *hashmap_get(const hashmap_t *hashmap, const char *key)
{
    const hashmap_entry_t *entry = hashmap_entry_get(hashmap, key);

    if (NULL == entry)
        return NULL;
    return entry->value;
}
