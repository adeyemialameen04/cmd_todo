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

	data->head = NULL;
	data->size = size;

	return (data);
}
