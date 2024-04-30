/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_set.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

int hashmap_set(hashmap_t *hashmap, const char *key, void *value)
{
    hashmap_entry_t *entry = (hashmap_entry_t *)
        hashmap_entry_get(hashmap, key);

    if (NULL != entry) {
        if (NULL != hashmap->destroy)
            hashmap->destroy(entry->value);
        entry->value = value;
        return 0;
    }
    entry = hashmap_entry_new(key, value);
    if (NULL == entry)
        return -1;
    hashmap_entry_set(hashmap, entry);
    return 0;
}
