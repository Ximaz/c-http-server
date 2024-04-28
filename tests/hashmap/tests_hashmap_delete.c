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

    p->free += 1;
}

Test(hashmap_delete, test_impl)
{
    hashmap_t hashmap = { 0 };
    person_t ximaz = {
        .name = "Ximaz",
        .age = 20,
        .free = 0
    };
    person_t zamix = {
        .name = "Zamix",
        .age = 2,
        .free = 0
    };

    hashmap_new(&hashmap, my_free);
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "ximaz", &ximaz)));
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "zamix", &zamix)));
    hashmap_delete(&hashmap, "zamix");
    cr_assert(eq(int, 1, zamix.free));
    cr_assert(eq(int, 0, ximaz.free));
    hashmap_delete(&hashmap, "ximaz");
    cr_assert(eq(int, 1, zamix.free));
    cr_assert(eq(int, 1, ximaz.free));
    hashmap_clear(&hashmap);
    cr_assert(eq(int, 1, zamix.free));
    cr_assert(eq(int, 1, ximaz.free));

    ximaz.free = 0;
    zamix.free = 0;
    hashmap_new(&hashmap, my_free);
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "zamix", &zamix)));
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "ximaz", &ximaz)));
    hashmap_delete(&hashmap, "zamix");
    cr_assert(eq(int, 1, zamix.free));
    cr_assert(eq(int, 0, ximaz.free));
    hashmap_delete(&hashmap, "ximaz");
    cr_assert(eq(int, 1, zamix.free));
    cr_assert(eq(int, 1, ximaz.free));
    hashmap_clear(&hashmap);
    cr_assert(eq(int, 1, zamix.free));
    cr_assert(eq(int, 1, ximaz.free));

    ximaz.free = 0;
    hashmap_new(&hashmap, NULL);
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "ximaz1", &ximaz)));
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "ximaz2", &ximaz)));
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "ximaz3", &ximaz)));
    cr_assert(eq(int, 0, hashmap_set(&hashmap, "ximaz4", &ximaz)));
    hashmap_clear(&hashmap);
    cr_assert(eq(int, 0, ximaz.free));
}
