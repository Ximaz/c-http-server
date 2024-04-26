/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** hashmap_insert.c
*/

#include <stddef.h>
#include <string.h>
#include "hashmap.h"
#include "list.h"

int hashmap_insert(hashmap_t *hashmap, hashmap_item_t *item)
{
    long i = 0;
    void *elem = NULL;
    hashmap_item_t *tmp = NULL;
    bucket_t bucket = hash(item->key, strlen(item->key)) % HASHMAP_SIZE;
    list_t *list = (list_t *) &(hashmap[bucket]);
    long count = list_count(list);

    for (; i < count; ++i) {
        tmp = list_value_at(list, i);
        if (0 != strcmp(item->key, tmp->key))
            continue;
        elem = list_remove_at(list, i);
        if (NULL != elem)
            list->destroy(elem);
        break;
    }
    return list_push_back(list, (void *) item);
}
