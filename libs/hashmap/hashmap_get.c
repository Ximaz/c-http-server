/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_get.c
*/

#include <stddef.h>
#include "hashmap.h"
#include "list.h"

void *hashmap_get(const hashmap_t *hashmap, const char *key)
{
    hashmap_entry_t *entry = hashmap_get_entry(hashmap, key);

    if (NULL == entry)
        return NULL;
    return entry->value;
}
