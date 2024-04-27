/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap_new.c
*/

#include <stdlib.h>
#include <stddef.h>
#include "hashmap.h"
#include "list.h"

void hashmap_new(hashmap_t *hashmap, hashmap_value_destroy_t destroy)
{
    size_t i = 0;
    list_t *bucket = NULL;

    hashmap->destroy = destroy;
    for (; i < HASHMAP_SIZE; ++i) {
        bucket = &(hashmap->buckets[i]);
        bucket->destroy = NULL;
    }
}
