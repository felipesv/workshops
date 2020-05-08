#include "header.h"

/* CREATE THE NEW NODE*/
order* create_node(int num_order)
{
	/* NODE TO RETURN*/
	order *new_node = NULL;

	/* ALLOC MEMORY*/
	new_node = malloc(sizeof(order));
	/* IF WE CAN'T ALLOC MEMORY*/
	if (new_node == NULL)
		return (NULL);

	/* DEFAULT VALUES*/
	new_node->num_order = num_order;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}

/* ADD NODE AT THE END QUEUE*/
void add_node_queue_end(order **head, int num_order)
{
	/* NEW NODE TO ADD AND VARIABLE TO MOVE IN THE QUEUE*/
	order *new_node = NULL, *current = NULL;

	/* VALIDATE IF A QUEUE EXISTS */
	if (!head)
		return;

	/* START AT HEAD NODE*/
	current = *head;
	/* CREATE THE NEW NODE*/
	new_node = create_node(num_order);

	/* IF THE NODE WAS CREATED*/
	if (!new_node)
		return;

	/* IF THE QUEUE IS EMPTY*/
	if(!*head)
	{
		/* NEW_NODE IS THE HEAD*/
		*head = new_node;
		return;
	}

	/* MOVE TO AT THE LAST NODE OF THE QUEUE*/
	while (current->next)
		current = current->next;

	/* THE LAST NODE POINT TO THE NEW NODE IN "NEXT"*/
	current->next = new_node;
	/* THE NEW NODE TO THE LAST NODE IN "PREV"*/
	new_node->prev = current;
}

void print_left_rigth(order *head)
{
	printf("(NULL)");
	while (head)
	{
		printf("<-->");
		printf("(%d)", head->num_order);
		head = head->next;
	}
	printf("<-->(NULL)\n");	
}

void print_rigth_left(order *head)
{
	printf("(NULL)");
	while (head->next)
		head = head->next;

	while (head)
	{
		printf("<-->");
		printf("(%d)", head->num_order);
		head = head->prev;
	}
	printf("<-->(NULL)\n");	
}

/* ADD NODE AT THE BEGINNING*/
void add_node_queue_beg(order **head, int num_order)
{
	/* NEW NODE TO ADD*/
	order *new_node = NULL;

	/* VALIDATE IF A QUEUE EXISTS*/
	if (!head)
		return;

	/* VALIDATE IF A QUEUE EXISTS*/
	new_node = create_node(num_order);

	/* CREATE THE NEW NODE*/
	if (!new_node)
		return;

	/* IF THE QUEUE IS EMPTY*/
	if (!*head)
	{
		/* NEW_NODE IS THE HEAD*/
		*head = new_node;
		return;
	}

	/* HEAD POR TO NEW NODE IN "PREV"*/
	(*head)->prev = new_node;
	/* NEW NODE POINT TO HEAD IN "NEXT"*/
	new_node->next = *head;
	/* NEW_NODE IS THE HEAD*/
	*head = new_node;
}

/* FREE ALL THE QUEUE*/
void free_list(order *head)
{
	order *current = NULL;

	/* WHILE EXISTS HEAD*/
	while (head)
	{
		/* SAVE THE NEXT NODE*/
		current = head->next;
		/* FREE THE HEAD*/
		free(head);
		/* CHANGE THE HEAD TO THE NEXT, SAVE IN CURRENT*/
		head = current;
	}
}

/* ADD NODE AT SPECIFIC INDEX*/
void add_node_queue_ndx(order **head, int num_order, int index)
{
	/* NEW NODE TO ADD AND VARIABLE TO MOVE IN THE QUEUE*/
	order *new_node = NULL, *current = NULL;
	/* COUNTER TO KNOW IN WHAT INDEX NEED TO ADD*/
	int count = 0;

	/* IF THE QUEUE IS EMPTY*/
	if (!head)
		return;

	/* START AT HEAD NODE*/
	current = *head;
	/* CREATE THE NEW NODE*/
	new_node = create_node(num_order);

	/* IF THE NODE WAS CREATED*/
	if (!new_node)
		return;

	/* IF QUEUE IS EMPTY OR IF INDEX IS 0 (CHANGE THE HEAD)*/
	if (!*head || index == 0)
	{
		/* IF QUEUE IS NOT EMPTY*/
		if (*head)
		{
			/* HEAD POINT TI NEW NODE IN "PREV"*/
			(*head)->prev = new_node;
			/* NEW NODE POINT TO HEAD IN "NEX"*/
			new_node->next = *head;
		}
		/* NEW_NODE IS THE HEAD*/
		*head = new_node;
		return;
	}

	/* WHILE COUNTER IS LESS TAH INDEX OR IF THE NEXT NODE IN QUEUE EXISTS*/
	while (count < index && current->next)
	{
		/* MOVE TO THE NEXT NODE*/
		current = current->next;
		/* ADD 1 TO THE COUNTER*/
		count++;
	}

	/* IF COUNT IS EQUALS TO INDEX -  ADD IN THE MIDDLE OF QUEUE*/
	if (count == index)
	{
		/* NEW NODE POINTE TO THE NODE IN CURRENT IN "NEXT"*/
		new_node->next = current;
		/* NEW NODE POINT TO THE PREVIOUS NODE THAN CURRENT IN IN "PREV"*/
		new_node->prev = current->prev;
		/* CURRENT NODE POINT TO NEW NODE IN "PREV"*/
		current->prev = new_node;
		/* PREVIOUS NODE THAN NEW NODE, POINT TO NEW NODE IN "NEXT"*/
		new_node->prev->next = new_node;
		return;
	}
	/* IF NEXT NODE IS NULL AND COUNTER PLUS ONE IS EQUALS TO INDEX - ADD ATH THE END OF QUEUE*/
	else if (!current->next && count + 1 == index)
	{
		/* CURRENT NODE POINT TO NEW NODE IN "NEXT"*/
		current->next = new_node;
		/* NEW NODE POINT TO CURRENT IN "PREV"*/
		new_node->prev = current;
		return;
	}
}

/* DELETE AT SPECIFIC INDEX */
void del_node_queue_ndx(order **head, int index)
{
	/* VARIABLE TO MOVE IN THE QUEUE*/
	order *current = NULL;
	/* COUNTER TO KNOW IN WHAT INDEX NEED TO DELETE*/
	int count = 0;

	/* IF NOT EXISTS QUEUE OR IF IS A EMPTY QUEUE OR IF INDEX IS LESS THAN 0*/
	if (!head || !*head || index < 0)
		return;

	/* START AT HEAD NODE*/
	current = *head;

	/* IF NEED TO DELETE THE HEAD*/
	if (index == 0)
	{
		/* IF IS NOT THE ONLY ONE NODE*/
		if (current->next)
		{
			/*THE NODE NEXT TO THE CURRENT POINT TO NULL IN "PREV"*/
			current->next->prev = NULL;
			/* FREE THE HEAD*/
			free(*head);
			/* NEW HEAD*/
			*head = current->next;
			return;
		}
		/* FREE HEAD*/
		free(*head);
		/* EMPTY HEAD*/
		*head = NULL;
		return;
	}

	/* WHILE COUNTER IS LESS TAH INDEX OR IF THE NEXT NODE IN QUEUE EXISTS*/
	while (count < index && current->next)
	{
		/* MOVE TO THE NEXT NODE*/
		current = current->next;
		/* ADD 1 TO THE COUNTER*/
		count++;
	}

	/* IF COUNT IS EQUALS TO INDEX -  ADD IN THE MIDDLE OF QUEUE*/
	if (count == index)
	{
		/* THE NODE PREVIOUS THAN THE CURRENT, POINT TO THE NODE THAT IS NEXT TO THE CURRENT IN "NEXT"*/
		current->prev->next = current->next;
		/* IF NEXT NODE EXISTS*/
		if (current->next)
			/* THE NODE NEXT THAN THE CURRENT, POINT TO THE NODE THAT IS PREVIOUS TO THE CURRENT IN "PREV"*/
			current->next->prev = current->prev;
		/*FREE CURRENT*/
		free(current);
	}
}