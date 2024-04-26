/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** hashmap_new.c
*/

#include "hashmap.h"
#include "list.h"

void hashmap_new(hashmap_t *hashmap, list_elem_destroy_t destroy)
{
    int i = 0;

    for (; i < HASHMAP_SIZE; ++i)
        hashmap[i]->destroy = destroy;
}
