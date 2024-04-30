/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_entry.c
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

hashmap_entry_t *hashmap_entry_new(const char *key, void *value)
{
    hashmap_entry_t *entry = calloc(1, sizeof(hashmap_entry_t));

    if (NULL != entry) {
        entry->hash = hashmap_hash(key);
        entry->key = key;
        entry->value = value;
        entry->prev = NULL;
        entry->next = NULL;
    }
    return entry;
}

void hashmap_entry_set(hashmap_t *hashmap, hashmap_entry_t *entry)
{
    hashmap_entries_t *bucket = &(hashmap->buckets[entry->hash]);

    if (NULL == bucket->head) {
        bucket->head = entry;
        bucket->tail = bucket->head;
    } else {
        entry->prev = bucket->tail;
        bucket->tail->next = entry;
        bucket->tail = bucket->tail->next;
    }
}

const hashmap_entry_t *hashmap_entry_get(const hashmap_t *hashmap,
    const char *key)
{
    hash_t hash = hashmap_hash(key);
    const hashmap_entry_t *head = hashmap->buckets[hash].head;

    while (NULL != head) {
        if (0 == strcmp(key, head->key))
            return head;
        head = head->next;
    }
    return NULL;
}

void hashmap_entries_destroy(hashmap_entries_t *entries,
    hashmap_value_destroy_t destroy)
{
    void *value = NULL;
    hashmap_entry_t *next = NULL;
    hashmap_entry_t *head = entries->head;

    while (NULL != destroy && NULL != head) {
        next = head->next;
        value = head->value;
        free(head);
        destroy(value);
        head = next;
    }
    while (NULL == destroy && NULL != head) {
        next = head->next;
        value = head->value;
        free(head);
        head = next;
    }
    memset(entries, 0, sizeof(hashmap_entries_t));
}
