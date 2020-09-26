#include <stdio.h>
#include <stdlib.h>
#include "Deck.h"

int		Initialize(Deck* d, int max)
{
	d->front = d->num = d->rear = 0;
	if ((d->que = calloc(max, sizeof(int))) == NULL)
	{
		d->max = 0;
		return -1;
	}
	d->max = max;
	return 0;
}

int		Enque(Deck *d, int sw, int x)
{
	if (d->max <= d->num)
		return -1;
	switch (sw)
	{
	case DeckA:
		if (d->front <= 0)
			return -1;
		d->que[d->front--] = x;
		break;
	case DeckB:
		if (d->rear >= d->max)
			return -1;
		d->que[d->rear++] = x;
		break;
	}
	d->num++;
	return 0;
}

int		Deque(Deck* d, int sw, int* x)
{
	if (d->num <= 0)
		return -1;
	switch (sw)
	{
	case DeckA:
		*x = d->que[d->front++];
		break;

	case DeckB:
		*x = d->que[d->rear--];
		break;
	}
	d->num--;
}

int		Size(const Deck* d)
{
	return d->num;
}

int		Capacity(const Deck* d)
{
	return d->max;
}

int		Peek(const Deck* d, int sw, int* x)
{
	if (d->num <= 0)
		return -1;
	switch (sw)
	{
	case DeckA:
		*x = d->que[d->front];
		break;
	case DeckB:
		*x = d->que[d->rear - 1];
		break;
	}
	return 0;
}

void	Print(Deck* d)
{
	int i;
	for (i = d->front; i < d->rear; i++)
		printf("x[%d] = %d ", i, d->que[i]);
}

void	Terminate(Deck* d)
{
	if (d->que != NULL)
		free(d->que);
	d->front = d->rear = d->num = d->max = 0;
}
