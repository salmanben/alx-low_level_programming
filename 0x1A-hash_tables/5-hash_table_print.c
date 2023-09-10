#include "hash_tables.h"

/**
 * hash_table_print - Prints the contents of a hash table.
 *
 * @ht: A pointer to the hash table.
 *
 * Description:
 *   This function prints the contents of the hash table in the following format:
 *   { 'key1': 'value1', 'key2': 'value2', ... }
 *
 * Note:
 *   The keys and values are enclosed in single quotes (' ') and separated by commas.
 *   The entire output is enclosed in curly braces ({ }).
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *ptr;
    int first_index;

    first_index = 0;
    printf("{");
    for (i = 0; i < ht->size; i++)
    {   
	if (ht->array[i] != NULL && first_index == 1)
           printf(", ");
        ptr = ht->array[i];
        while (ptr != NULL)
        {
	    first_index = 1;	
            printf("'%s': '%s'", ptr->key, ptr->value);
            ptr = ptr->next;
            if (ptr != NULL)
                printf(", ");
        }
    }
    printf("}\n");
}
