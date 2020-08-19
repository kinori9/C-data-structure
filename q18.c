#include <stdio.h>

void    nrpira(int n)
{
    int i, j, k;

    for (i = n; i >= 0; i--)
    {
        for (k = 0; k <= n - i; k++)
            putchar(' ');
        for(j = 0; j < (i - 1) * 2 + 1; j++)
            printf("%d", (n - i + 1) % 10);
        for (k = 0; k <= n - i; k++)
            putchar(' ');
        putchar('\n');
    }
}

int     main(void)
{
    int n;
    puts("숫자를 입력해주세요");
    scanf("%d", &n);
    nrpira(n);
    putchar('\n');
}