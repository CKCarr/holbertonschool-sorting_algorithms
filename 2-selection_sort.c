#include "sort.h"
/**
  * selection_sort - sort an array of ints in ascending
  * order using Selection Sort Algorithim.
  * @array: they array to be sorted.
  * @size: number of elements in @array.
  * Return: void, Success=0
  */
void selection_sort(int *array, size_t size)
{
	size_t pos1, pos2, min_idx;
	int temp;

	for (pos1 = 0; pos1 < size; pos1++)
	{	min_idx = pos1;
	for (pos2 = pos1 + 1; pos2 < size; pos2++)
	{
		if (array[pos2] < array[min_idx])
		{
			min_idx = pos2;
		}
	}
	if (min_idx != pos1)
	{
		temp = array[pos1];
		array[pos1] = array[min_idx];
		array[min_idx] = temp;
		print_array(array, size);
	}
	}
}
