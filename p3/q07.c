#include <stdio.h>
#include <stdlib.h>

void    *seqsearch(const void *key, const void *base, size_t nmemb,
 size_t size, int (*compar)(const void *,const void *));

int     int_cmp(const int *a, const int *b)
{
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

void    *seqsearch(const void *key, const void *base, size_t nmemb,
 size_t size, int (*compar)(const void *,const void *))
{
    size_t i;
    char *x = (char *)base;
    for (i = 0; i < nmemb; i++)
        if(!compar((const void *)&x[i * 4], key))
            return (&x[i * size]);
    return NULL;
}

int    main(void)
{
    int i, nx, ky;
    int *x;
    int *p;
    
    puts("bsearch 함수를 사용하여 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for (i = 0; i < nx; i++)
    {
        do
        {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (i < 0);
    }

    printf("검색값 : ");
    scanf("%d", &ky);
    p = seqsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *)) int_cmp);
    
    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d은(는) x[%d]에 있습니다.\n", ky, (int)(p - x));
    free(x);

    return 0;
}