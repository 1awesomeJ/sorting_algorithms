#include <stddef.h>
#include "sort.h"
#include <stdio.h>


/**
 *swap -swaps two integers
 * @a: the first integer
 * @b: the second integer
 */
void swap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}

/**
 *L_partition -pations an array around a pivot
 * @arr: the array being partitioned
 * @low: the low index of the array
 * @high: the high index of the array
 * Return: the new index of the pivot element
 */
int L_partition(int *arr, int low, int high)
{
	int a, b, element;

	element = arr[high];
	a = low;
	for (b = low; b < high; b++)
	{
		if (arr[b] < element)
		{
			swap(&arr[b], &arr[a]);
			a++;
		}
	}
	swap(&arr[a], &arr[high]);
	print_array(arr, 10);
	return (a);
}


/**
 *quick_recursion -carries out partion sort recursively on an array
 * @arr: the array to be sorted
 * @low: lowest index of the array
 * @high: highest index of the array
 */
void quick_recursion(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot = L_partition(arr, low, high);

		quick_recursion(arr, low, pivot - 1);
		quick_recursion(arr, pivot + 1, high);
	}
}


/**
 *quick_sort -sorts an array of integers using the quick sort algorithm
 * @array: the array of integers
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	quick_recursion(array, 0, size - 1);
}
