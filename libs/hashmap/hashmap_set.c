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
#include "list.h"

static int hashmap_replace(hashmap_t *hashmap, const char *key, void *value)
{
    hashmap_entry_t *entry = hashmap_get_entry(hashmap, key);

    if (NULL == entry)
        return -1;
    if (NULL != hashmap->destroy)
        hashmap->destroy(entry->value);
    entry->value = value;
    return 0;
}

int hashmap_set(hashmap_t *hashmap, const char *key, void *value)
{
    hashmap_entry_t *entry = NULL;
    int hash = hashmap_hash(key, strlen(key));
    list_t *bucket = &(hashmap->buckets[hash]);

    if (0 == hashmap_replace(hashmap, key, value))
        return 0;
    entry = calloc(1, sizeof(hashmap_entry_t));
    if (NULL == entry)
        return -1;
    entry->key = key;
    entry->value = value;
    if (-1 == list_push_back(bucket, entry)) {
        free(entry);
        return -1;
    }
    return 0;
}
