#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and its contents.
 *
 * @ht: A pointer to the hash table to be deleted.
 *
 * Description:
 *   This function frees the memory occupied by the hash table @ht, including
 *   all its key-value pairs, keys, and values. After deletion, the hash table
 *   and its contents are no longer accessible.
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *ptr;
    hash_node_t *tmp;

    for (i = 0; i < ht->size; i++)
    {
        if (ht->array[i] == NULL)
           continue;
        ptr = ht->array[i];
        while (ptr != NULL)
        {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
        }
    }
    free(ht->array);
    free(ht);
}
