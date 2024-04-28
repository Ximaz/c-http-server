/*
** EPITECH PROJECT, 2024
** Hashmap in C
** File description:
** hashmap.h
*/

#ifndef __HASHMAP_H_

    #define __HASHMAP_H_
    #define HASHMAP_SIZE (2 << 12)

    #include <stddef.h>

typedef void (*hashmap_value_destroy_t)(void *value);

typedef size_t hash_t;

typedef struct s_hashmap_entry {
    hash_t hash;
    const char *key;
    void *value;
    struct s_hashmap_entry *prev;
    struct s_hashmap_entry *next;
} hashmap_entry_t;

typedef struct s_hashmap_entries_t {
    hashmap_entry_t *head;
    hashmap_entry_t *tail;
} hashmap_entries_t;

typedef struct s_hashmap_key {
    const char *key;
    struct s_hashmap_key *next;
} hashmap_key_t;

typedef struct s_hashmap_value {
    void *value;
    struct s_hashmap_value *next;
} hashmap_value_t;

typedef struct s_hashmap {
    hashmap_entries_t buckets[HASHMAP_SIZE];
    hashmap_value_destroy_t destroy;
} hashmap_t;

/**
 * @brief Internal functions (must not be used by developers)
 */

hashmap_entry_t *hashmap_entry_new(const char *key, void *value);

void hashmap_entry_set(hashmap_t *hashmap, hashmap_entry_t *entry);

const hashmap_entry_t *hashmap_entry_get(const hashmap_t *hashmap,
    const char *key);

void hashmap_entries_destroy(hashmap_entries_t *entries,
    hashmap_value_destroy_t destroy);

/**
 * @brief Initialize the hasmap with the destroy function for entries' values.
 *
 * @param[in] hashmap
 * @param[in] destroy the function used to destroy entries' values
 */
void hashmap_new(hashmap_t *hashmap, hashmap_value_destroy_t destroy);

/**
 * @brief Compute the hash of the key considering it's length.
 *
 * @param[in] key
 * @return The (hash of the key) % HASHMAP_SIZE
 */
hash_t hashmap_hash(const char *key);

/**
 * @brief Set the value to the correct hashmap bucket. If an element with the
 * same key already exists, it gets replaced.
 *
 * @param[in] hashmap
 * @param[in] key
 * @param[in] value
 * @return 0 on success, -1 on error (unable to add the value to the hashmap)
 */
int hashmap_set(hashmap_t *hashmap, const char *key, void *value);

/**
 * @brief Get the hashmap entry stored in the hashmap with the key.
 *
 * @param[in] hashmap
 * @param[in] key
 * @return Non-NULL hashmap entry on success, NULL on error (not found)
 */
const hashmap_entry_t *hashmap_entry_get(const hashmap_t *hashmap,
    const char *key);

/**
 * @brief Get the value stored in the hashmap with the key.
 *
 * @param[in] hashmap
 * @param[in] key
 * @return Non-NULL element on success, NULL on error (not found)
 */
void *hashmap_get(const hashmap_t *hashmap, const char *key);

/**
 * @brief Delete the value stored in the hashmap with the key.
 *
 * @param[in] hashmap
 * @param[in] key
 */
void hashmap_delete(hashmap_t *hashmap, const char *key);

/**
 * @brief Clear all buckets of the hashmap.
 *
 * @param[in] hashmap
 */
void hashmap_clear(hashmap_t *hashmap);

#endif /* __HASHMAP_H_ */
