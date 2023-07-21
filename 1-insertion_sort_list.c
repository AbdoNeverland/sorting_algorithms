#include "sort.h"

/**
 * adjustprev - it must be a better way
 * @list: list
 **/
void adjustprev(listint_t **list)
{

	int i;
	listint_t *head = *list, *last = NULL;

	i = 0;

	while (*list)
	{

		++i;
		(*list)->prev = last;

		last = *list;
		*list = (*list)->next;
	}
	*list = head;
}

/**
 * link - align next to pre
 * @list: main list
 * @pre: previous
 * @next: next
 */
void link(listint_t **list, listint_t *pre, listint_t *next)
{
	if (pre)
		(pre)->next = next;
	else
		*list = next;
	if (next)
		(next)->prev = pre;
}

/**
 * permute - swap two elements
 * @list: list
 *@e1: first
 *@e2: second
 */
void permute(listint_t **list, listint_t **e1, listint_t **e2)
{
	listint_t *n1, *n2, *p1, *p2, *o1, *o2;

	o1 = *e1;
	o2 = *e2;
	n2 = (*e2)->next;
	n1 = (*e1)->next;
	p1 = (*e1)->prev;
	p2 = (*e2)->prev;
	if ((*e1)->next != *e2)
	{
		link(list, p1, *e2);
		link(list, o2, n1);
		link(list, p2, o1);
		link(list, o1, n2);
	}
	else
	{
		listint_t *t;

		t = (*e1)->prev;
		(o1)->prev = o2;
		(*e2)->prev = t;
		if (t)
			t->next = o2;
		else
			*list = o2;

		t = (o2)->next;
		(o2)->next = o1;
		(o1)->next = t;
	}
	adjustprev(list);
}

/**
 * insertion_sort_list - sort list using insertion algo
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *li, *lj;

	li = *list;
	while (li && li->next)
	{
		if (li->n > li->next->n)
		{
			lj = li->next;
			permute(list, &li, &(li->next));
			print_list(*list);
			while (lj && lj->prev)
			{
				if (lj->n < lj->prev->n)
				{
					listint_t *t = lj->prev;

					permute(list, &(lj->prev), &lj);
					print_list(*list);
					lj = t;
				}
				else
					lj = lj->prev;
			}
		}
		else
		{
			li = li->next;
		}
	}
}
