/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_get_entry.c
*/

#include <stddef.h>
#include <string.h>
#include "hashmap.h"
#include "list.h"

hashmap_entry_t *hashmap_get_entry(const hashmap_t *hashmap, const char *key)
{
    size_t i = 0;
    hashmap_entry_t *entry = NULL;
    int hash = hashmap_hash(key, strlen(key));
    const list_t *bucket = &(hashmap->buckets[hash]);
    size_t bucket_count = list_count(bucket);

    for (; i < bucket_count; ++i) {
        entry = list_value_at(bucket, i);
        if (0 == strcmp(key, entry->key))
            return entry;
    }
    return NULL;
}
