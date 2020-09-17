
#include <stdio.h>
#include <stdlib.h>

int     search_fn(char *base, size_t pc)
{
    while(base[pc] == base[pc - 1])
    {
        if (base[pc] == base[pc - 1])
            pc -= 1;
    }
    return pc - 1;
}

void    *bsearchx(const void *key, const void *base, size_t nmemb,
 size_t size, int(*compar)(const void *, const void *))
{
    size_t pc;
    size_t pl = 0;
    size_t pr = nmemb - 1;
    char *x = (char *)base;
    while(1)
    {
        int comp = compar((const void *)&x[(pc = (pl + pr) / 2) * size], key);

        if (comp == 0)
            return &x[search_fn(x, pc) * size];
        else if (pl == pr)
            break;
        else if (comp < 0)
            pl = pc + 1;
        else
            pr = pc - 1;
    }
    return NULL;
}

int     int_cmp(const int *a, const int *b)
{
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int     main(void)
{
    int i, nx, ky;
    int *x;
    int *p;
    
    puts("bsearch 함수를 사용하여 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
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
    p = bsearchx(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *)) int_cmp);

    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d는 x[%d]에 있습니다.", ky, (int)(p - x));
    free(x);
}