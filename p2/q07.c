#include    <stdio.h>

int     card_conv(unsigned int x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLNMOPQRSTUVWXYZ";
    int digits = 0;

    if (x == 0)
        d[digits++] = dchar[0];
    else
    {
        while (x)
        {
            printf("%d |      %3d ⋅⋅⋅ ", n, x);
            d[digits++] = dchar[x % n];
            printf("%d\n", x % n);
            printf("  +---------\n");
            x /= n;
        }
        printf("         %3d\n", x);
    }
    return digits;
}

int     main(void)
{
    int num;
    int gs;
    int retry;
    char a[512];
    int dno;
    int i;

    printf("10진수를 기수 변환합니다.\n");
    do{
        printf("변환하는 음이 아닌 정수 : ");
        scanf("%d", &num);
        do
        {
            printf("어떤 진수로 변환할까요?(2 ~ 36) : ");
            scanf("%d", &gs);
        } while (2 > gs || 36 < gs);
        dno = card_conv(num, gs, a);
        printf("2진수로 ");
        for (i = dno - 1; i >= 0; i--)
            printf("%c", a[i]);
        printf("입니다.\n");
        printf("한 번 더 할까요?(1 ··· 예/0 ··· 아니오): ");
        scanf("%d", &retry);
    } while (retry == 1);
}