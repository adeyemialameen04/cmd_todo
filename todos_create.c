#include "todo.h"

data_t *init_todos(int size)
{
	data_t *data = malloc(sizeof(data_t));

	if (data == NULL)
	{
		fprintf(stderr, "Unable to create todo\n");
		return (NULL);
	}
	int i;

	data->todos = malloc(sizeof(todo_item *) * size);
	for (i = 0; i < size; i++)
	{
		data->todos[i] = NULL;
	}
	data->head = NULL;
	data->size = size;

	return (data);
}
