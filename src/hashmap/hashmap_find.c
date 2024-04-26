/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** hashmap_find.c
*/

#include <stddef.h>
#include <string.h>
#include "hashmap.h"
#include "list.h"

void *hashmap_find(const hashmap_t *hashmap, const char *key)
{
    long i = 0;
    hashmap_item_t *tmp = NULL;
    bucket_t bucket = hash(key, strlen(key)) % HASHMAP_SIZE;
    list_t *list = (list_t *) &(hashmap[bucket]);
    long count = list_count(list);

    for (; i < count; ++i) {
        tmp = list_value_at(list, i);
        if (0 == strcmp(key, tmp->key))
            return tmp->value;
    }
    return NULL;
}
