/*
** EPITECH PROJECT, 2024
** Tests Hashmap in C
** File description:
** hashmap_delete.c
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "hashmap.h"

typedef struct s_person {
    const char *name;
    int age;
    int free;
} person_t;

static void my_free(void *elem)
{
    person_t *p = (person_t *) elem;

    p->free = 1;
}

Test(hashmap_delete, test_impl)
{
    hashmap_t hashmap = { 0 };
    person_t ximaz = {
        .name = "Ximaz",
        .age = 20,
        .free = 0
    };
    person_t *item = NULL;

    hashmap_new(&hashmap, my_free);
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "ximaz", &ximaz)));
    item = hashmap_delete(&hashmap, "ximaz");
    cr_assert(eq(ptr, item, &ximaz));
    hashmap_clear(&hashmap);
    cr_assert(eq(int, 0, ximaz.free));
    item = hashmap_delete(&hashmap, "ximaz");
    cr_assert(eq(ptr, NULL, item));
}
