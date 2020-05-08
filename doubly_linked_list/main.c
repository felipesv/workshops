#include "header.h"

int main()
{
	order *head = NULL;

	add_node_queue_end(&head, 0);
	add_node_queue_end(&head, 1);
	add_node_queue_end(&head, 2);
	add_node_queue_end(&head, 3);
	add_node_queue_end(&head, 4);
	del_node_queue_ndx(&head, 0);
	print_left_rigth(head);
	del_node_queue_ndx(&head, 0);
	print_left_rigth(head);
	del_node_queue_ndx(&head, 0);
	print_left_rigth(head);
	del_node_queue_ndx(&head, 0);
	print_left_rigth(head);
	del_node_queue_ndx(&head, 0);


	/*add_node_queue_beg(&head, 0);
	add_node_queue_beg(&head, 1);
	add_node_queue_beg(&head, 2);*/
	print_left_rigth(head);
	/*print_rigth_left(head);*/

	free_list(head);
	return (0);
}