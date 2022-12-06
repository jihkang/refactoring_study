#include "types.h"
#include "list.h"
#include <stdio.h>

void	link_print_data(t_link_lst *link)
{
	printf("linked list run\n");
	list_print_data(link->head);
}
