/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** hashmap_destroy.c
*/

#include <stdlib.h>
#include "hashmap.h"
#include "list.h"

void hashmap_destroy(hashmap_t *hashmap)
{
    int i = 0;

    for (; i < HASHMAP_SIZE; ++i)
        list_clear(&((*hashmap)[i]));
}
