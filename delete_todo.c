#include "todo.h"

void delete_todo(data_t *data, int id)
{
	if (data->head == NULL)
	{
		fprintf(stderr, "Todo list is empty u dumbass\n");
		return;
	}

	todo_item *curr = data->head, *prev = NULL;
	while (curr != NULL)
	{
		if (curr->id == id)
		{
			if (prev == NULL)
			{
				data->head = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}

			free_todo_item(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}

	printf("Todo not found\n");
}
