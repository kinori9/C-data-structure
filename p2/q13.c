#include <stdio.h>

typedef struct {
    int y;      //년
    int m;      //월(1 ~ 12)
    int d;      //일(1 ~ 31)
} Date;

Date DateOf(int y, int m, int d);   //구조체를 반환하는 함수
Date After(Date x, int n);          //날짜 x의 n일 뒤의 날짜를 반환하는 함수
Date Before(Date x, int n);         //날짜 x의 n일 앞의 날짜를 반환하는 함수

static int mdays[2][13] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },			/* 평년 */
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }			/* 윤년 */
};

int isleap(int year)
{
    return year % 4 == 0
}

Date After(Date x, int n)
{

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
    day = DateOf(y, m, d);
}