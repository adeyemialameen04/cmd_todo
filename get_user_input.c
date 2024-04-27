#include "todo.h"

char *get_user_input(data_t *data)
{
	size_t size = 0;
	__ssize_t chars_read;
	char *str = NULL;

	chars_read = getline(&str, &size, stdin);
	if (chars_read < 0)
	{
		free_todos(data);
		fprintf(stderr, "Error reading line\n");
		exit(EXIT_FAILURE);
	}

	return (str);
}
