/*
** EPITECH PROJECT, 2024
** Tests Hashmap in C
** File description:
** hashmap_get.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "hashmap.h"

typedef struct s_person {
    const char *name;
    int age;
} person_t;

static void my_free(void *elem)
{
    (void)(elem);
}

Test(hashmap_get, test_impl)
{
    hashmap_t hashmap = { 0 };
    person_t ximaz = {
        .name = "Ximaz",
        .age = 20
    };
    person_t *item = NULL;

    hashmap_new(&hashmap, my_free);
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "ximaz", &ximaz)));
    item = hashmap_get(&hashmap, "ximaz");
    cr_assert(eq(ptr, item, &ximaz));
    item = hashmap_get(&hashmap, "ximaz");
    hashmap_clear(&hashmap);
    item = hashmap_get(&hashmap, "ximaz");
    cr_assert(eq(ptr, NULL, item));
}
