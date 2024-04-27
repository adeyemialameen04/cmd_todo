#include "todo.h"

void display_todos(data_t *data)
{

	if (data->head == NULL)
	{
		fprintf(stderr, "Todo list is empty u dumbass\n");
		return;
	}

	todo_item *curr = data->head;

	while (curr != NULL)
	{
		switch (curr->priority)
		{
		case 0:
			printf("\033[1;33m%s\033[0m", curr->todo);
			break;
		case 1:
			printf("\033[1;36m%s\033[0m", curr->todo);
			break;
		case 2:
			printf("\033[1;35m%s\033[0m", curr->todo);
			break;
		default:
			break;
		}
		curr = curr->next;
	}
}
