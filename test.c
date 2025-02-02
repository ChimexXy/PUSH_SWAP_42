#include <stdlib.h>
#include <stdio.h>

typedef struct s_list{
	int content;
	// int index;
	struct s_list *next;
}	t_list;

t_list *new_node(int data)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	node->content = data;
	node->next = NULL;
	return (node);
}
void add_fornt(t_list **list, t_list *node)
{

	if(*list == NULL)
		*list = node;
	else
	{
		node->next = *list;
	}
	list = &node;
}

int main(int ac, char **av)
{
	int i = 1;
	t_list *node;

	t_list *header;
	int data = 0;
	while(i < ac )
	{
		data = atoi(av[i]);
		node = new_node(data);
		add_fornt(&header, node);
		i++;
	}
	printf("%d\n", header->content);

}