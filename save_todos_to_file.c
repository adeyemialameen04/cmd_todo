#include "todo.h"

void save_todo(data_t *data)
{
	int fd = 0, sz;
	todo_item *curr = NULL;

	if (data->head == NULL)
	{
		fprintf(stderr, "Todo list is empty u dumbass\n");
		return;
	}

	fd = open("todos.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	curr = data->head;

	if (fd < 0)
	{
		fprintf(stderr, "Error creating file descriptor\n");
		exit(EXIT_FAILURE);
	}

	while (curr != NULL)
	{
		sz = write(fd, curr->todo, strlen(curr->todo));
		curr = curr->next;
	}
}
