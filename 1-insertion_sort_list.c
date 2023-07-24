#include "sort.h"

/**
 * permute - swap two nodes
 * @list: list
 *@e1: first
 *@e2: second
 * Return: lower node
 */
listint_t *permute(listint_t **list, listint_t *e1, listint_t *e2)
{
	listint_t *t;

	if (e1 == e2 || !(e1) || !(e2))
		return (e1);

	if ((e1)->prev)
		(e1)->prev->next = (e2);
	else
		*list = e2;
	t = e2->next;
	if (e1->next != e2)
	{
		(e2)->next = e1->next;
		e2->prev->next = e1;
	}
	else
		e2->next = e1;
	e1->next = t;
	if (t)
		t->prev = e1;
	t = e2->prev;
	e2->prev = e1->prev;
	e1->prev = t;
	if (e1->next)
		e1->next->prev = e1;
	if (e2->next)
		e2->next->prev = e2;
	print_list(*list);
	return (e2);
}

/**
 * insertion_sort_list - sort list using insertion algo
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *li, *lj, *t;

	li = *list;
	while (li && li->next)
	{
		if (li->n > li->next->n)
		{
			t = permute(list, li, (li->next));
			lj = t->prev;
			while (lj)
			{
				if (t->n < lj->n)
				{
					t = permute(list, lj, t);
					lj = t->prev;
				}
				else
					lj = lj->prev;
			}
		}
		else
			li = li->next;
	}
}
