/*
** EPITECH PROJECT, 2024
** Tests Hashmap in C
** File description:
** tests_hashmap_hash.c
*/

#include <stddef.h>
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "hashmap.h"

Test(hashmap_hash, test_impl)
{
    hash_t hash1 = 0;
    hash_t hash2 = 0;
    const char *string = "This is the key I want to hash";

    hash1 = hashmap_hash(string);
    hash2 = hashmap_hash(string);
    cr_assert(eq(ptr, (void *) hash1, (void *) hash2));
}
