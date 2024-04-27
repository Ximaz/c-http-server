/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_delete.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"
#include "list.h"

void *hashmap_delete(hashmap_t *hashmap, const char *key)
{
    size_t i = 0;
    void *value = NULL;
    hashmap_entry_t *entry = NULL;
    int hash = hashmap_hash(key, strlen(key));
    list_t *bucket = &(hashmap->buckets[hash]);
    size_t bucket_count = list_count(bucket);

    for (; i < bucket_count; ++i) {
        entry = list_value_at(bucket, i);
        if (0 == strcmp(key, entry->key)) {
            entry = list_remove_at(bucket, i);
            value = entry->value;
            free(entry);
            return value;
        }
    }
    return NULL;
}
