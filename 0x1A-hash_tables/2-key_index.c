#include "hash_tables.h"

/**
 * key_index - Computes the index for a given key in a hash table.
 *
 * @key: The key string to be hashed.
 * @size: The size of the hash table.
 *
 * Return: The index at which the key's corresponding value should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    unsigned long int index;
    unsigned long int hash;

    hash = hash_djb2(key);
    index = hash % size;
    return (index);
}
