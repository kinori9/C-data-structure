#include <stdio.h>

int     main(void)
{
    int i, n;
    unsigned long counter = 0;  //나눗셈 횟수
    for(n = 2; n <= 1000; n++)
    {
        for(i = 2; i < n; i++)
        {
            counter++;
            if(n % i == 0)      //나누어 떨어지면 소수가 아닙니다
                break;          // 나누어 떨어졌을경우 반복은 불필요
        }
        if(n == i)              // 마지막까지 나누어 떨어지지않았을경우 출력
            printf("%d\n", n);
    }
    printf("나눗셈을 실행한 횟수 : %lu\n", counter);
    return 0;
}