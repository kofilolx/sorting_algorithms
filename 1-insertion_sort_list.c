#include "sort.h"

/**
 * swap_node - swaps nodes in a doubly-linked list
 * @a: address of first node
 * @b: address of second node
 *
 * Return: void
 */
void swap_node(listint_t *a, listint_t *b)
{
        if (a->prev)
                a->prev->next = b;
        if (b->next)
                b->next->prev = a;
        a->next = b->next;
        b->prev = a->prev;
        a->prev = b;
        b->next = a;

}
/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *j;

	if (!list || !*list || !(*list)->next)
		return;
	itr = (*list)->next;
	while (itr)
	{
		j = itr;
		itr = itr->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_node(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}

	}
}
