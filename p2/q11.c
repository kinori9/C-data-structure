
/* 한 해의 지난 날 수를 구합니다*/
#include <stdio.h>

/*- 각 달의 날 수 -*/
int     mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    ,{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/*--- year년이 윤년인가? ---*/
int     isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int     dayofyear(int y, int m, int d)
{
    while (--m)
    {
        d += mdays[isleap(y)][m - 1];
    }
    return d;
    /*
    int i;
    int days = d;
    for (i = 1; i < m; i++)
        days += mdays[isleap(y)][i - 1];
    return days;
    */
}

int     main(void)
{
    int y, m, d;
    int result;
    int retry;

    do
    {
        printf("년: ");
        scanf("%d" , &y);
        printf("월: ");
        scanf("%d" , &m);
        printf("일: ");
        scanf("%d" , &d);
        result = dayofyear(y, m, d);
        printf("%d년의 %d일쨰입니다.\n", y, result);
        printf("다시 할까요?(1 ··· 예/0 ··· 아니오) : ");
        scanf("%d" , &retry);
    } while (retry == 1);
    
    return 0;
}