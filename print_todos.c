#include "todo.h"

void display_todos(data_t *data)
{
	int i = 0;

	if (data->head == NULL)
	{
		fprintf(stderr, "Todo list is empty u dumbass\n");
		return;
	}

	todo_item *curr = data->head;

	while (curr != NULL)
	{
		if (i > 0)
			printf(" -> ");
		printf("%s", curr->todo);
		++i;
		curr = curr->next;
	}
	// printf("\n");
}
