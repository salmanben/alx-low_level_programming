#include "hash_tables.h"

/**
 * hash_table_get - Retrieves the value associated with a key in a hash table.
 *
 * @ht: A pointer to the hash table.
 * @key: The key string for which to retrieve the value.
 *
 * Return: A pointer to the value associated with the key, or NULL if not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *ptr;

    index = key_index((const unsigned char *)key, ht->size);
    ptr = ht->array[index];
    while (ptr != NULL)
    {
        if (strcmp(ptr->key, key) == 0)
            return (ptr->value);
        ptr = ptr->next;
    }
    return (NULL);
}
