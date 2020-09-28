#include <stdio.h>

int     factorial(int x)
{
    int i;
    int result;
    result = 1;
    if (x > 0)
    {
        for (i = 1; i <= x; i++)
            result *= i;
        return result;
    }
    else
        return 1;
}

int     main(void)
{
    int x;
    printf("숫자를 입력해주십시오 : ");
    scanf("%d", &x);
    printf("순차곱셉의 값은 %d입니다.", factorial(x));
    return 0;
}