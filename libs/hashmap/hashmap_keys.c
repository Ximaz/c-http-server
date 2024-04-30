/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_keys.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "hashmap.h"

static void hashmap_fill_keys(const hashmap_t *hashmap, hashmap_keys_t *keys)
{
    size_t i = 0;
    size_t j = 0;
    hashmap_entry_t *entry = NULL;

    for (; i < HASHMAP_SIZE; ++i) {
        entry = hashmap->buckets[i].head;
        while (NULL != entry) {
            keys->keys[j] = entry->key;
            entry = entry->next;
            ++j;
        }
    }
}

hashmap_keys_t *hashmap_keys(const hashmap_t *hashmap)
{
    hashmap_keys_t *keys = calloc(1, sizeof(hashmap_keys_t));

    if (NULL != keys) {
        keys->count = hashmap_entries_count(hashmap);
        keys->keys = calloc(keys->count, sizeof(char *));
        if (NULL == keys->keys) {
            free(keys);
            return NULL;
        }
        hashmap_fill_keys(hashmap, keys);
    }
    return keys;
}

void hashmap_keys_destroy(hashmap_keys_t *keys)
{
    free(keys->keys);
    free(keys);
}
