#include "todo.h"

void clear_input_buffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

void clear(void)
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

int main(void)
{
	int cmd;

	data_t *data = init_todos(20);

	printf("\033[1;32m=========== Welcome to this todo app by CodeSavantAl ===========\n");
	printf("\033[1;32m[[[[[[[[[[[[[[[[   Lets go over the commands  ]]]]]]]]]]]]]]]\n");
	printf("Press (1) to add a new todo, (2) to delete a todo, and (3) to print all todos, (4) to clear the terminal, (100) to quit the program\n");
	printf("\033[0m");
	while (1)
	{
		printf("Command: ");
		scanf("%d", &cmd);
		clear_input_buffer();
		switch (cmd)
		{
		case 1:
			printf("Enter todo to be added: ");
			char *str = get_user_input(data);
			add_todo(data, str);
			free(str);
			break;
		case 2:
			printf("\033[1;31mEnter id of the todo to be deleted: \033[0m");
			int id;
			scanf("%d", &id);
			delete_todo(data, id);
			break;
		case 3:
			display_todos(data);
			break;
		case 4:
			clear();
			break;
		case 100:
			printf("getting here?\n");
			free_todos(data);
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid command\n");
			break;
		}
	}

	free_todos(data);
	return (0);
}
