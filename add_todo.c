#include "todo.h"

void add_todo(data_t *data, char *todo)
{
	todo_item *new_todo = malloc(sizeof(todo_item));
	int random;

	if (new_todo == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for todo\n");
		exit(EXIT_FAILURE);
	}

	new_todo->todo = strdup(todo);
	srand(time(NULL));
	random = rand() % 100;
	new_todo->id = random;
	printf("%d\n", random);
	if (new_todo->todo == NULL)
	{
		fprintf(stderr, "Add todo strdup failed");
		exit(EXIT_FAILURE);
	}

	new_todo->next = data->head;
	data->head = new_todo;
}
