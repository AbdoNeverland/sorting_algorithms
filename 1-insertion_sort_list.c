#include "sort.h"

/**
 * permute - swap two elements
 *@e1: first
 *@e2: second
 */
void permute(listint_t **list, listint_t *e1, listint_t *e2)
{
	/* listint_t *t;*/
	if (e1 && e1->prev)
	e1->prev->next = e2;
	if (e2 && e2->prev)
	e2->prev->next = e1;
	e1->next->prev = e2;
	e2->next->prev = e1; 
	if (!e1->prev)
	*list = e1;
	if (!e2->prev)
	*list = e2;
	
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
			permute(list, li, li->next);
			lj = li;
			while (lj && lj->prev)
			{
				if (lj->n < lj->prev->n)
				{
					permute(list, lj, lj->prev);
					print_list(*list);
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
