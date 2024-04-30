/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_new.c
*/

#include <string.h>
#include "hashmap.h"

void hashmap_new(hashmap_t *hashmap, hashmap_value_destroy_t destroy)
{
    hashmap->destroy = destroy;
    memset(&(hashmap->buckets), 0, sizeof(hashmap_entries_t) * HASHMAP_SIZE);
}
