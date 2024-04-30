/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_entries_count.c
*/

#include <stddef.h>
#include "hashmap.h"

size_t hashmap_entries_count(const hashmap_t *hashmap)
{
    size_t i = 0;
    size_t count = 0;
    hashmap_entry_t *entry = NULL;

    for (; i < HASHMAP_SIZE; ++i) {
        entry = hashmap->buckets[i].head;
        while (NULL != entry) {
            ++count;
            entry = entry->next;
        }
    }
    return count;
}
