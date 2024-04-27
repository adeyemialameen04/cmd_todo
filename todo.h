#ifndef _TODO_H_
#define _TODO_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct todo_item
{
	char *todo;
	int id;
	struct todo_item *next;
} todo_item;

typedef struct data_t
{
	todo_item **todos;
	todo_item *head;
	int size;
} data_t;

data_t *init_todos(int size);
void display_todos(data_t *data);
void add_todo(data_t *data, char *todo);
char *get_user_input(data_t *data);
void free_todo_item(todo_item *todo);
void delete_todo(data_t *data, int id);
void free_todos(data_t *data);

#endif /* _TODO_H_ */
