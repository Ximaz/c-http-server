/*
** EPITECH PROJECT, 2024
** Tests Hashmap in C
** File description:
** hashmap_new.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "hashmap.h"

static void my_free(void *elem)
{
    free(elem);
}

Test(hashmap_new, test_impl)
{
    size_t i = 0;
    hashmap_t hashmap = { 0 };

    hashmap_new(&hashmap, my_free);
    cr_assert(eq(ptr, my_free, hashmap.destroy));
    for (; i < HASHMAP_SIZE; ++i)
        cr_assert(eq(ptr, NULL, hashmap.buckets[i].destroy));
}
