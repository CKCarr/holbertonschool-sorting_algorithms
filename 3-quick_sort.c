#include "sort.h"
/**
  * swap_int- swap two integers in an array.
  * @cur_idx: index of first elem to swap.
  * @nxt_idx: index of second element to swap.
  * Return: void
  */
void swap_int(int *cur_idx, int *nxt_idx)
{
	int temp;

	temp = *cur_idx;
	*cur_idx = *nxt_idx;
	*nxt_idx = temp;
}

/**
  * part_like_lomuto - partition an array using lomuto scheme.
  * @array: array to partition.
  * @lo: lower index of partitiion.
  * @hi: higher index of partition.
  * @size: size of the array.
  * Return: index of pivot.
  */
size_t part_like_lomuto(int *array, size_t size, int left, int right)
{
	int hi, lo, *pivot = array + right;

	for ( hi = lo = left; lo <  right; lo++)
	{
		if (array[lo] < *pivot)
		{
			if (hi < lo)
			{
				swap_int(array + lo, array + hi);
				print_array(array, size);
			}
			hi++;
		}
	}
	if (array[hi] > *pivot)
	{
		swap_int(array + hi, pivot);
		print_array(array, size);
	}
	return (hi);
}

/**
  * sort_like_lomuto - quicksort through recursion
  * @array: array of ints to sort.
  * @size: size of the @array to sort.
  * @left: starting index of array partition to sort.
  * @right: ending index of array partition to sort.
  * Return: void, Success=0.
  */
void sort_like_lomuto(int *array, size_t size, int left, int right)
{
	int part_i;

	if (right - left > 0)
	{
		part_i = part_like_lomuto(array, size, left, right);
		sort_like_lomuto(array, size, left, part_i - 1);
		sort_like_lomuto(array, size, part_i + 1, right);
	}
}

/**
  * quick_sort - functon sorts an array of ints in
  * ascending order using Quick Sort Algorithim.
  * @array: array t be sorted.
  * @size: the size of the @array.
  * Return: void, Success(0).
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_like_lomuto(array, size, 0, size -1);
}
