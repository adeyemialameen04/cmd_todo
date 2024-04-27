#include "todo.h"

void free_todo_item(todo_item *todo)
{
	free(todo->todo);
	free(todo);
}

void free_todos(data_t *data)
{
	todo_item *curr;
	todo_item *next;

	if (data == NULL)
		return;

	curr = data->head;
	while (curr != NULL)
	{
		next = curr->next;
		free_todo_item(curr);
		curr = next;
	}

	free(data);
}
