#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

// 큐 초기화
int		Initialize(IntQueue* q, int max)
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

 // 큐에 데이터를 인큐
int		Enque(IntQueue* q, int x)
{
	if (q->max <= q->num)
		return -1;
	if (q->rear >= q->max)
	{
		q->rear = 0;
		q->que[q->rear++] = x;
	}
	else
		q->que[q->rear++] = x;
	q->num++;
	return 0;
}

int		Deque(IntQueue* q, int* x)
{
	if (q->num <= 0)
		return -1;
	if (q->rear <= 0)
	{
		*x = q->que[q->front++];
		q->front = 0;
	}
	else
		*x = q->que[q->front++];
	q->num--;
	return 0;
}

int		Peek(const IntQueue* q, int* x)
{
	if (q->num <= 0)
		return -1;
	*x = q->que[q->front];
	return 0;
}

int		Size(const IntQueue* q)
{
	return q->num;
}

int		Capacity(const IntQueue* q)
{
	return q->max;
}

void	Print(const IntQueue* q)
{
	int i;
	if (q->num <= 0)
		return -1;
	for (i = 0; i < q->num; i++)
		printf("%d \n", q->que[(q->front + i) % q->max]);
}

void	Terminate(IntQueue* q)
{
	if (q->que != NULL)
		free(q->que);
	q->front = q->num = q->rear = q->max = 0;
}
