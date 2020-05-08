#ifndef DOUBLE_LIST
#define DOUBLE_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct order
{
	int num_order;
	struct order *next;
	struct order *prev;
} order;

order* create_node(int num_order);
void add_node_queue_end(order **head, int num_order);
void add_node_queue_beg(order **head, int num_order);
void add_node_queue_ndx(order **head, int num_order, int index);
void del_node_queue_ndx(order **head, int index);
void print_left_rigth(order *head);
void print_rigth_left(order *head);
void free_list(order *head);

#endif