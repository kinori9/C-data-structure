#include <stdio.h>
#include <stdlib.h>

void    print_n(int n)
{
    int i;
    printf("   |");
    for (i = 0; i < n; i++)
        printf("  %d",i);
    putchar('\n');
    puts("------------------------------------");
}

void    printing(const int a[], int pl, int pr, int pc, int n)
{
    int i;
    printf("   |");
    for (i = 0; i < n; i++)
    {
        if (i == pc)
            printf("  +");
        else if (i == pl)
            printf(" <-");
        else if (i == pr)
            printf(" ->");
        else
            printf("   ");
    }
    putchar('\n');
    printf("  %d|",pc);
    for (i = 0; i < n; i++)
        printf("  %d",a[i]);
    putchar('\n');
}

int     bin_search(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;
    int pc;
    print_n(n);
    do
    {
        pc = (pl + pr) / 2;
        printing(a, pl, pr, pc, n);
        if (a[pc] == key)
            return pc;
        else if (a[pc] > key)
            pr = pc - 1;
        else
            pl = pc + 1; 
    } while (pl <= pr);
    return -1;
}

int     main(void)
{
    int i, nx, ky, idx;
    int *x;
    puts("이진 검색");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    printf("오름차순을 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (i = 1; i < nx; i++)
    {
        do
        {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);
    }
    printf("검색값 : ");
    scanf("%d", &ky);
    idx = bin_search(x, nx, ky);
    putchar('\n');
    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, idx);
    free(x);

    return 0;
}