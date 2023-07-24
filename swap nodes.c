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
 * permute - swap two nodes
 * @list: list
 *@e1: first
 *@e2: second
 * Retrun: lower node
 */
listint_t *permute(listint_t **list, listint_t *e1, listint_t *e2)
{

	listint_t *t;
	if (e1 == e2 || !(e1) || !(e2))
		return e1;

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
	/*swap previous node   e2->prev = e1->prev;*/
	if (e1->next)
		e1->next->prev = e1;
	if (e2->next)
		e2->next->prev = e2;

	return e2;
}
