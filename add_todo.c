#include "todo.h"

void add_todo(data_t *data, char *todo)
{
	todo_item *new_todo = malloc(sizeof(todo_item));
	int random, priority;

	if (new_todo == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for todo\n");
		exit(EXIT_FAILURE);
	}

	new_todo->todo = strdup(todo);
	if (new_todo->todo == NULL)
	{
		fprintf(stderr, "Add todo strdup failed\n");
		exit(EXIT_FAILURE);
	}

	srand(time(NULL));
	random = rand() % 100;

	do
	{
		printf("\033[1;34mEnter priority (0 for low, 1 for medium, 2 for high): \033[0m");
		scanf("%d", &priority);
		if (priority >= 0 && priority <= 2)
			new_todo->priority = priority;
		else
			printf("\033[1;31mInvalid priority. Please enter (0), (1), or (2).\033[0m\n");
	} while (priority < 0 || priority > 2);

	new_todo->id = random;
	new_todo->next = data->head;
	data->head = new_todo;
	printf("\033[1;32mTodo added Id: (%d)\n\033[0m", random);
}
