#include <stdio.h>

typedef struct {
    int y;      //년
    int m;      //월(1 ~ 12)
    int d;      //일(1 ~ 31)
} Date;

Date DateOf(int y, int m, int d);   //구조체를 반환하는 함수
Date After(Date x, int n);          //날짜 x의 n일 뒤의 날짜를 반환하는 함수
Date Before(Date x, int n);         //날짜 x의 n일 앞의 날짜를 반환하는 함수

static int mdays[][12] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },			/* 평년 */
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }			/* 윤년 */
};

int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void    print_day(Date x)
{
    int i, days;
    days = 0;
    printf("%d년의",x.y);
    for (i = 1; i < x.m; i++)
        days += mdays[isleap(x.y)][i - 1];
    printf("%d일 입니다.",days + x.d);
}

Date After(Date x, int n)
{
    if (n < 0)
        return Before(x, -n);

    x.d += n ;
    while (x.d > mdays[isleap(x.y)][x.m - 1])
    {
        x.d -= mdays[isleap(x.y)][x.m - 1];
        if(++x.m > 12)
        {
            x.m = 1;
            x.y++;
        }
    }
    return x;
}

Date Before(Date x, int n)
{
    if (n < 0)
        return After(x, -n);
    x.d -= n;
    while(x.d < 1)
    {
        if (--x.m < 1)
        {
            x.m = 12;
            x.y--;
        }
        x.d += mdays[isleap(x.y)][x.m - 1];
    }
    return x;
}

Date DateOf(int y, int m, int d)
{
    Date temp;

    temp.y = y;
    temp.m = m;
    temp.d = d;

    return temp;
}

int     main(void)
{
    int n;
    int y, m, d;
    Date day;

    printf("년: ");
    scanf("%d", &y);
    printf("월: ");
    scanf("%d", &m);
    printf("일: ");
    scanf("%d", &d);
    printf("n의 값");
    scanf("%d", &n);
    day = DateOf(y, m, d);
    print_day(day);
    day = After(day, n);
    print_day(day);
    day = Before(day, n);
    day = Before(day, n);
    print_day(day);

}