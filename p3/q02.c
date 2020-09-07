#include <stdio.h>
#include <stdlib.h>

int     search(int a[], int n, int key)
{
    int i;
    int j;
    a[n] = key;
    printf("   |");
    for (j = 0; j < n; j++)
        printf(" %d", j);
    putchar('\n');
    puts("--------------------------");
    j = 0;
    i = 0;
    while(1)
    {
        printf("   |");
        for (j = 0; j < n; j++)
        {
            if (i == j)
                printf(" *");
            else
                printf("  ");
        }
        putchar('\n');
        j = 0;
        printf("  %d|", i);
        for (j = 0; j < n; j++)
            printf(" %d", a[j]);
        putchar('\n');
        if(a[i] == key)
            break;
        i++;
        printf("   |\n");
    }
    return i == n ? -1 : i;
}

int     main(void)
{
    int i, nx, ky, idx;
    int *x;
    puts("선형검색(보초법)");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx + 1, sizeof(int));
    for(i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d",&x[i]);
    }
    printf("검색값 : ");
    scanf("%d", &ky);
    idx = search(x, nx, ky);
    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);
    free(x);
    return 0;
}