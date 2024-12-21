#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAX_SIZE 300
typedef struct Node_q
{
	void* value;
	struct Node_q* next;
}Node_q;


typedef struct Queue
{
	Node_q* front;
	Node_q* back;
	int length;
}Queue;

unsigned char q_init(Queue* q);
unsigned char is_full(Queue* q);
unsigned char is_empty(Queue* q);
unsigned char enqueue(Queue* q, void* value);
unsigned char dequeue(Queue* q);
void q_free(Queue* q);
#endif
