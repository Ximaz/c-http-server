/*
** EPITECH PROJECT, 2024
** Tests Hashmap in C
** File description:
** tests_hashmap_items.c
*/

#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "hashmap.h"

Test(hashmap_keys, test_impl)
{
    size_t i = 0;
    size_t j = 0;
    hashmap_t hashmap = { 0 };
    hashmap_keys_t *keys = NULL;
    char *found[4] = { NULL, NULL, NULL, NULL };
    char *expected[4] = { "KEY1", "KEY2", "KEY3", "KEY4" };

    hashmap_new(&hashmap, NULL);
    for (; i < 4; ++i)
        hashmap_set(&hashmap, expected[i], NULL);
    keys = hashmap_keys(&hashmap);
    hashmap_clear(&hashmap);
    cr_assert(ne(ptr, keys, NULL));
    cr_assert(eq(ptr, (void *) 4, (void *) keys->count));
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 4; ++j)
            if (0 == strcmp(keys->keys[i], expected[j]))
                found[j] = expected[j];
    hashmap_keys_destroy(keys);
    for (i = 0; i < 4; ++i)
        cr_assert(eq(str, expected[i], found[i]));
}

Test(hashmap_values, test_impl)
{
    size_t i = 0;
    size_t j = 0;
    hashmap_t hashmap = { 0 };
    hashmap_values_t *values = NULL;
    char *found[4] = { NULL, NULL, NULL, NULL };
    char *keys[4] = { "KEY1", "KEY2", "KEY3", "KEY4" };
    char *expected[4] = { "VALUE1", "VALUE2", "VALUE3", "VALUE4" };

    hashmap_new(&hashmap, NULL);
    for (; i < 4; ++i)
        hashmap_set(&hashmap, keys[i], expected[i]);
    values = hashmap_values(&hashmap);
    hashmap_clear(&hashmap);
    cr_assert(ne(ptr, values, NULL));
    cr_assert(eq(ptr, (void *) 4, (void *) values->count));
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 4; ++j)
            if (0 == strcmp(values->values[i], expected[j]))
                found[j] = expected[j];
    hashmap_values_destroy(values);
    for (i = 0; i < 4; ++i)
        cr_assert(eq(str, expected[i], found[i]));
}

Test(hashmap_items, test_impl)
{
    size_t i = 0;
    size_t j = 0;
    char *found[4][2] = {
        { NULL, NULL },
        { NULL, NULL },
        { NULL, NULL },
        { NULL, NULL }
    };
    hashmap_t hashmap = { 0 };
    hashmap_items_t *items = NULL;
    char *e_keys[4] = { "KEY1", "KEY2", "KEY3", "KEY4" };
    char *e_values[4] = { "VALUE1", "VALUE2", "VALUE3", "VALUE4" };

    hashmap_new(&hashmap, NULL);
    for (; i < 4; ++i)
        hashmap_set(&hashmap, e_keys[i], e_values[i]);
    items = hashmap_items(&hashmap);
    hashmap_clear(&hashmap);
    cr_assert(ne(ptr, items, NULL));
    cr_assert(eq(ptr, (void *) 4, (void *) items->count));
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 4; ++j) {
            if (0 == strcmp(items->items[i].key, e_keys[j]) &&
                0 == strcmp((const char *) items->items[i].value, e_values[j])) {
                found[j][0] = e_keys[j];
                found[j][1] = e_values[j];
            }
        }
    hashmap_items_destroy(items);
    for (i = 0; i < 4; ++i) {
        cr_assert(eq(str, e_keys[i], found[i][0]));
        cr_assert(eq(str, e_values[i], found[i][1]));
    }
}
