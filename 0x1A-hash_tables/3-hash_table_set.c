#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates a key-value pair in a hash table.
 *
 * @ht: A pointer to the hash table.
 * @key: The key string to be added or updated.
 * @value: The value string associated with the key.
 *
 * Return: 1 if the operation succeeds, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node;
    
    if (key == NULL || strlen(key) == 0 || value == NULL)
    {
        fprintf(stderr, "Key and value must not be empty or NULL.\n");
        return (0);
    }

    index = hash_djb2((const unsigned char *)key) % ht->size;
    new_node = malloc(sizeof(hash_node_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return (0);
    }

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        fprintf(stderr, "Key duplication failed.\n");
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        fprintf(stderr, "Value duplication failed.\n");
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
