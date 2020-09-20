#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

// 스택 초기화
int     Initalize(IntStack *s, int max)
{
    s->ptr = 0;
    if((s->stk = calloc(max, sizeof(int))) == NULL)
    {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

//스택에 데이터를 푸시
int     Push(IntStack *s, int x)
{
    if(s->ptr >= s->max)//스택이 가득참
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

// 스택에서 데이터를 팝
int     Pop(IntStack *s, int *x)
{
    if(s->ptr <= 0)// 스택이 비어있음
        return -1;
    *x = s->stk[--s->ptr]; // ptr이 있는 위치가 현재 스택정보량
    return 0;
}

// 스택에서 데이터를 피크(엿보기)
int     Peek(const IntStack *s, int *x)
{
    if(s->ptr <= 0) //스택이 비어있음
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

// 스택비우기
void    Clear(IntStack *s)
{
    s->ptr = 0;
}

// 스택용량
int     Capacity(const IntStack *s)
{
    return s->max;
}

// 스택에 쌓여 있는 데이터 수
int     Size(const IntStack *s)
{
    return s->ptr;
}

// 스택이 비어있는가?
int     IsEmpty(const IntStack *s)
{
    return s->ptr <= 0;
}

// 스택이 가득 찼는가?
int     IsFull(const IntStack *s)
{
    return s->ptr >= s->max;
}

// 스택에서 검색
int     Search(const IntStack *s, int x)
{
    int i;
    for (i = s->ptr - 1; i >= 0; i++)
        if (s->stk[i] == x)
            return i;
    return -1;
}

// 모든데이터 출력
void    Print(const IntStack *s)
{
    int i;
    for (i = 0; i < s->ptr; i++)
        printf("s[%d] ",i);
}

// 스택종료
void    Terminate(IntStack *s)
{
    if(s->stk != NULL)
        free(s->stk);
    s->max = s->ptr = 0;
}