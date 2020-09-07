#include <stdio.h>
#include <stdlib.h>

int     search_idx(const int a[], int n, int key, int idx[])
{
    int i;
    int j;
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            idx[j] = i;
            j++;
        }
    }
    printf("idx 배열에 저장된 요소는 ");
    for (i = 0; i < j; i++)
    {
        printf("%d ",idx[i]);
    }
    printf("입니다.");
    return i;
}

int     main(void)
{
    int i, n, si, result;
    int *a;
    int *idx;
    printf("요소의 갯수를 입력하시오 : ");
    scanf("%d", &n);
    a = calloc(n, sizeof(int));
    idx = calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    printf("검색할 숫자를 입력해주세요 : ");
    scanf("%d", &si);
    result = search_idx(a, n, si, idx);
    printf("검색한 요소의 갯수는 %d개 입니다. ", result);
    free(a);
    free(idx);
}