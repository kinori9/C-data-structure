#include <stdio.h>
#include <stdlib.h>

long    long_cmpr(const long *a, const long *b)
{
    if (*a < *b)
        return 1;
    else if (*a > *b)
        return -1;
    else
        return 0;
}

int     main(void)
{
    long i, nx, ky;
    long *x;
    long *p;
    puts("bsearch 함수를 사용하여 검색");
    printf("요소 개수 : ");
    scanf("%ld", &nx);
    x = calloc(nx, sizeof(long));

    printf("내림차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%ld", &x[0]);
    for (i = 1; i < nx; i++)
    {
        do{
            printf("x[%ld] : ",i);
            scanf("%ld",&x[i]);
        } while(x[i] > x[i - 1]);
    }
    printf("검색값 : ");
    scanf("%ld", &ky);
    p = bsearch(&ky,
                x,
                nx,
                sizeof(long),
                (int (*)(const void *, const void *)) long_cmpr
                );
    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%ld은(는) x[%ld]에 있습니다.\n", ky, (long)(p - x));
    free(x);

    return 0;
}