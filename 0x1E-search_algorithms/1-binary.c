#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array using binary search
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: Value to search for in the array
 *
 * Return: If value is found, return the index where the value is located, otherwise return -1
 */
int binary_search(int *array, size_t size, int value)
{
    size_t left,right, i;
    
    left = 0;
    right = size - 1;
    while (left <= right) {
        printf("Searching in array: ");
        for (i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i + 1 != size)
                printf(", ");
        }
        printf("\n");
        size_t mid = left + (right - left) / 2;
        if (array[mid] == value)
            return mid;

        if (array[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return (-1);
}
