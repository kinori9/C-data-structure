int     Search2(const IntQueue *q, int x)
{
    int i;
    if (q->num <= 0)
        return -1;
    for (i = 0; i < q->num; i++)
        if (q->que[(i + q->front) % q->max] == x)
            return i;
}