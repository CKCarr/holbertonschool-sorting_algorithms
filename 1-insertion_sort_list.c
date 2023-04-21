#include "sort.h"
/**
  * insertion_sort_list - function sorts dll of ints
  * in ascending order w/ insertion sort algorithim.
  * @list: a listint_t double pointer to struct
  * Return: void, Success(0).
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *curr_prev = NULL, *temp = NULL;

	if (!list || !*list || ((*list)->next == NULL))
	{	_error("Empty list: nothing to sort");
		return;
	}
	temp = *list;
	while (temp)
	{
		while ((temp->prev) && (temp->n < temp->prev->n))
		{	curr_prev = temp->prev;
			current = temp;

			curr_prev->next = current->next;
			if (current->next)
				current->next->prev = curr_prev;
			current->next = curr_prev;
			current->prev = curr_prev->prev;
			curr_prev->prev = current;
			if (current->prev)
				current->prev->next = current;
			else/* update head to pointer */
				*list = current;
			print_list(*list);
		}
		temp = temp->next;
	}
}
