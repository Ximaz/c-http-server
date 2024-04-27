/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_clear.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "hashmap.h"
#include "list.h"

static void hashmap_destroy_bucket(list_t *bucket,
    hashmap_value_destroy_t destroy)
{
    hashmap_entry_t *entry = NULL;

    if (NULL != destroy) {
        entry = list_pop_front(bucket);
        while (NULL != entry) {
            destroy(entry->value);
            free(entry);
            entry = list_pop_front(bucket);
        }
    } else {
        entry = list_pop_front(bucket);
        while (NULL != entry) {
            free(entry);
            entry = list_pop_front(bucket);
        }
    }
}

void hashmap_clear(hashmap_t *hashmap)
{
    size_t i = 0;

    for (; i < HASHMAP_SIZE; ++i)
        hashmap_destroy_bucket(&(hashmap->buckets[i]), hashmap->destroy);
}
