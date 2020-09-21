#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

int		initialize(ArrayIntQueue *q, int max)
{
	q->front = q->num = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL)
	{
		q->max = 0;
		return -1;
	}
	q->max = max;
	return 0;
}

int		Enqueue(ArrayIntQueue *q, int x)
{
	if (q->rear >= q->max)
		return -1;
	q->que[q->rear++] = x;
	q->num++;
	return 0;
}

int		Dequeue(ArrayIntQueue* q)
{
	int i;
	if (q->front >= q->rear)
		return -1;
	for (i = 1; i <= q->max; i++)
		q->que[i - 1] = q->que[i];
	q->num--;
	q->rear--;
	return 0;
}

int		Peek(ArrayIntQueue* q, int* x)
{
	if (q->rear <= 0)
		return -1;
	*x = q->que[q->rear - 1];
	return 0;
}

void	Print(const ArrayIntQueue* q)
{
	int i;
	for (i = 0; i < q->rear; i++)
		printf("%d ", q->que[i]);
}

void	Terminate(ArrayIntQueue* q)
{
	if (q->que != NULL)
		free(q->que);
	q->max = q->front = q->num = q->rear = 0;
}
