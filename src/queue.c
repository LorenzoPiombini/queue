
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



unsigned char q_init(Queue* q)
{
	(*q).front = calloc(1,sizeof(Node_q));
	if(!(*q).front)
	{
		printf("calloc failed %s:%d.\n",__FILE__,__LINE__-3);
		return 0;
	}

	(*q).back = calloc(1,sizeof(Node_q));
	if(!(*q).back)
	{
		printf("calloc failed %s:%d.\n",__FILE__,__LINE__-3);
		return 0;
	}

	(*q).front->next = NULL;
	(*q).back->next = NULL;
	(*q).length = 0;
	return 1;
}
unsigned char is_full(Queue* q)
{
	if((*q).length == MAX_SIZE) return 1;

	return 0;
}

unsigned char is_empty(Queue* q)
{
	if((*q).length == 0) return 1;

	return 0;
}

unsigned char enqueue(Queue* q, void* value)
{
	if(is_full(q)) return 0;

	Node_q* new_node = calloc(1,sizeof(Node_q));
	if(!new_node)
	{
		printf("calloc failed %s:%d.\n",__FILE__,__LINE__-3);
		return 0;
	}

	new_node->value = value;
	new_node->next = NULL;

	if((*q).length == 0)
	{
		(*q).front->next = new_node;
		(*q).back->next = new_node;
		(*q).length++;
		return 1;
	}

	(*q).back->next->next = new_node;
	Node_q* temp = (*q).back->next->next;
	(*q).back->next = temp;
	(*q).length++;
	return 1;

}

unsigned char dequeue(Queue* q)
{
	if(is_empty(q)) return 0;
	
	if((*q).length == 1)
	{
		free((*q).front->next);
		(*q).front->next = NULL;
		(*q).back->next = NULL;
		(*q).length = 0;
		return 1;
	}

	Node_q* temp = (*q).front->next->next;
	free((*q).front->next);
	(*q).front->next = NULL;
	(*q).front->next = temp;
	(*q).length--;
	
	return 1;
}


void q_free(Queue* q)
{
	if(is_empty(q)) return;

	while((*q).length > 0)
	{
		Node_q* temp = (*q).front->next->next;
		free((*q).front->next);
		(*q).front->next = NULL;
		(*q).front->next = temp;
		(*q).length--;
	}

	free((*q).front);
	free((*q).back);
}
