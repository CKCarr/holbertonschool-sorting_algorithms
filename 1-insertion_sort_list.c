#include "sort.h"
/**
  * insertion_sort_list - function sorts dll of ints
  * in ascending order w/ insertion sort algorithim.
  * @list: a listint_t double pointer to struct
  * Return: void, Success(0).
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *node1 = NULL, *node2 = NULL, *temp = NULL;

	if (!list || !(*list) || (!(*list)->next))
	{	return;	}
	temp = *list;
	while (temp->next)
	{
		while (temp->n > temp->next->n)
		{	node1 = temp;
			node2 = temp->next;
			node2->prev = node1->prev;
			if (node1->prev)
				node1->prev->next = node2;
			else
				*list = node2;
			if (node2->next)
				node2->next->prev = node1;
			node1->prev = node2;
			node1->next = node2->next;
			node2->next = node1;
			temp = temp->prev;
			print_list(*list);
			if (temp->prev && temp->prev->n > temp->n)
			{
				temp = temp->prev;
				continue;
			}
		}
		temp = temp->next;
	}
}
