#include <stddef.h>
#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort - sorts a linked list of integers 
 * using the insertion sort algorithm
 * @list: pointer to the head of the list
 * @size: number of elements in the array
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *trans;
	curr = trans = NULL;
	trans = *list;
	while (trans)
	{
		curr = (trans) -> next;
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
/*			curr = (trans) -> next;*/
		swap_nodes(list, curr->prev, curr);
		/*	curr = curr -> prev;*/
		}
		trans = trans-> next;
	}
}

	void swap_nodes(listint_t **head, listint_t *a, listint_t *b)
	{
		listint_t *temp, *temp2;
		if (a->prev == NULL)
		{
			temp = b->next;
			b->prev = a->prev;
			a->prev = b;
			b->next = a;
			a->next = temp;
			temp->prev = a;
			*head = b;
		}
		else if (b->next == NULL)
		{
			temp = b->next;
			temp2 = a->prev;
			b->next = a;
			a->prev = b;
			a->next = temp;
			b->prev = temp2;
			temp2->next = b;
		}
		else 
		{
			temp = b->next;
			temp2 = a->prev;
			a->prev = b;
			b->next = a;
			b->prev = temp2;
			a->next = temp;
			temp->prev = a;
			temp2->next = b;
		}
	}	



/*for (i = 1; i < size; i++)
	{
		j= i - 1;
		k = array[i];
		while (j >= 0 && k < array[j])
		{
			array[j+1] = array[j];
			j--;
		}
		j++;
		array[j] = k;
	}
			printf("temp is: %p\n", (void *)temp);
			printf("a is: %p\n", (void *)a);
			printf("b is %p\n", (void *)b);
			printf("head is %p\n", (void *)*head);
			printf("temp is %p\n", (void *)temp);
			printf("a is %p\n", (void *)a);
			printf("b is %p\n", (void *)b);
			printf("head is %p\n", (void *)*head);
}*/
