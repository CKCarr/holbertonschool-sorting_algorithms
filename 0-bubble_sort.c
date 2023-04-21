#include "sort.h"
/**
  * bubble_sort - prints an array of integers in
  * ascending order using the bubble sort algorithim
  * @array: the array to be sorted
  * @size: size of the array
  * Return: void (0)=Success
  */
void bubble_sort(int *array, size_t size)
{
	size_t bub_a, bub_b;
	int temp = 0;

	if (!array)
	{	return;	}

	for (bub_a = 0; bub_a < size - 1; bub_a++)
	{
		for (bub_b = 0; bub_b < size - bub_a - 1; bub_b++)
		{
			if (array[bub_b] > array[bub_b + 1])
			{
				temp = array[bub_b];
				array[bub_b] = array[bub_b + 1];
				array[bub_b + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
