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

void hashmap_delete(hashmap_t *hashmap, const char *key)
{
    hashmap_entry_t *new_entry = NULL;
    hash_t hash = hashmap_hash(key);
    hashmap_entry_t **head = &(hashmap->buckets[hash].head);

    while (NULL != (*head)) {
        if (0 != strcmp(key, (*head)->key)) {
            (*head) = (*head)->next;
            continue;
        }
        new_entry = (*head)->prev ? (*head)->prev : (*head)->next;
        if (NULL != (*head)->prev)
            (*head)->prev->next = (*head)->next;
        if (NULL != (*head)->next)
            (*head)->next->prev = (*head)->prev;
        if (NULL != hashmap->destroy)
            hashmap->destroy((*head)->value);
        free((*head));
        (*head) = new_entry;
        return;
    }
}
