#include "sort.h"

void print_listrr(const listint_t *list)
{

	int i;

	i = 0;
	while (list)
	{
		++i;
		list = list->next;
		if (list->next == NULL)
			break;
	}
	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->prev;
	}
	printf("\n");
}
/**
 * permute - swap two elements
 * @list: list
 *@e1: first
 *@e2: second
 */
listint_t *permute(listint_t **list, listint_t **e1, listint_t **e2)
{
	listint_t *t, *o1, *o2;

	/*printf("permuting %d<%d<%d    %d<%d<%d\n", (*e1)->prev->n, (*e1)->n, (*e1)->next->n,
		   (*e2)->prev->n, (*e2)->n, (*e2)->next->n);*/
	if (*e1 == *e2 || !(*e1) || !(*e2))
		return *e1;
	/*swap actual node*/
	t = *e1;
	*e1 = *e2;
	*e2 = t;
	o1 = *e1;
	o2 = *e2;
	/*swap next node*/
	t = (*e1)->next;
	(*e1)->next = (*e2)->next;
	(*e2)->next = t;
	/*swap previous node*/
	t = (o1)->prev;
	(*e1)->prev = (o2)->prev;
	(*e2)->prev = t;

	if ((*e1)->prev)
		(*e1)->prev->next = *e1;
	if ((*e2)->prev)
		(*e2)->prev->next = *e2;
	/*swap previous node*/
	if ((*e1)->next)
		(*e1)->next->prev = *e1;
	if ((*e2)->next)
		(*e2)->next->prev = *e2;

	if ((*e1)->prev == NULL)
		*list = *e1;
	if ((*e2)->prev == NULL)
		*list = *e2;

	return *e1;
}

/**
 * insertion_sort_list - sort list using insertion algo
 * @list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *li, *lj , *t;

	li = *list;
	while (li && li->next)
	{
		if (li->n > li->next->n)
		{
			
            printf("main %d  %d\n",li->n, li->next->n);
			lj = permute(list, &li, &(li->next));
			t= lj;
			print_list(*list);
			print_listrr(*list);
			while (lj && lj->prev)
			{
				if (lj->n < lj->prev->n)
				{
					

 printf("inside %d  %d\n",lj->prev->n, lj->n);
 print_listrr(*list);
					lj = permute(list, &(lj->prev), &lj);
					print_list(*list);
					
					
				}
				else
					lj = lj->prev;
			}
			li =t;
		}
		else
		{
			li = li->next;
		}
	}
}
