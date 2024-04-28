/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_items.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "hashmap.h"

static void hashmap_fill_items(const hashmap_t *hashmap,
    hashmap_items_t *items)
{
    size_t i = 0;
    size_t j = 0;
    hashmap_entry_t *entry = NULL;

    for (; i < HASHMAP_SIZE; ++i) {
        entry = hashmap->buckets[i].head;
        while (NULL != entry) {
            items->items[j].key = entry->key;
            items->items[j].value = entry->value;
            entry = entry->next;
            ++j;
        }
    }
}

hashmap_items_t *hashmap_items(const hashmap_t *hashmap)
{
    hashmap_items_t *items = calloc(1, sizeof(hashmap_items_t));

    if (NULL != items) {
        items->count = hashmap_entries_count(hashmap);
        items->items = calloc(items->count, sizeof(hashmap_item_t));
        if (NULL == items->items) {
            free(items);
            return NULL;
        }
        hashmap_fill_items(hashmap, items);
    }
    return items;
}

void hashmap_items_destroy(hashmap_items_t *items)
{
    free(items->items);
    free(items);
}
