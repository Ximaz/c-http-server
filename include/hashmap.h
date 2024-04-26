/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** hashmap.h
*/

#ifndef __HASHMAP_H_
    #define __HASHMAP_H_
    #define HASHMAP_SIZE 16

    #include <stddef.h>
    #include "list.h"

typedef struct s_hashmap_item {
    char const *key;
    void *value;
} hashmap_item_t;

typedef size_t bucket_t;

typedef list_t hashmap_t[HASHMAP_SIZE];

void hashmap_new(hashmap_t *hashmap, list_elem_destroy_t destroy);

size_t hash(const char *string, size_t length);

int hashmap_insert(hashmap_t *hashmap, hashmap_item_t *item);

void *hashmap_find(const hashmap_t *hashmap, const char *key);

void hashmap_destroy(hashmap_t *hashmap);

#endif /* !__HASHMAP_H_ */
