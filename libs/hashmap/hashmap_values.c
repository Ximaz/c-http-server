/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_value.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "hashmap.h"

static void hashmap_fill_values(const hashmap_t *hashmap,
    hashmap_values_t *values)
{
    size_t i = 0;
    size_t j = 0;
    hashmap_entry_t *entry = NULL;

    for (; i < HASHMAP_SIZE; ++i) {
        entry = hashmap->buckets[i].head;
        while (NULL != entry) {
            values->values[j] = entry->value;
            entry = entry->next;
            ++j;
        }
    }
}

hashmap_values_t *hashmap_values(const hashmap_t *hashmap)
{
    hashmap_values_t *values = calloc(1, sizeof(hashmap_values_t));

    if (NULL != values) {
        values->count = hashmap_entries_count(hashmap);
        values->values = calloc(values->count, sizeof(char *));
        if (NULL == values->values) {
            free(values);
            return NULL;
        }
        hashmap_fill_values(hashmap, values);
    }
    return values;
}

void hashmap_values_destroy(hashmap_values_t *values)
{
    free(values->values);
    free(values);
}
