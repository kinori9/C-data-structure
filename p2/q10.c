#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(type, x, y) do{ type t = x; x = y; y = t; } while(0)

void    shuffle(int a[], int n)
{
    int i;

    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        int randTemp = rand() % n;
        if (i != randTemp)
            swap(int, a[i], a[randTemp]);
    }
}

int     main(void)
{
    int i;
    int n;
    int *ar;

    printf("요소 갯수 :");
    scanf("%d", &n);
    ar = calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("a[%d] : ", i);
        scanf("%d", &ar[i]);
    }
    for (i = 0; i < n; i++)
        printf("%d", ar[i]);
    shuffle(ar, n);
    for (i = 0; i < n; i++)
        printf("%d", ar[i]);
    free(ar);
}