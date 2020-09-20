#include <stdio.h>
#include "IntStack.h"

int     main(void)
{
    IntStack s;
    if (Initalize(&s, 64) == -1)
    {
        puts("스택 생성에 실패하였습니다.");
        return 1;
    }

    while (1)
    {
        int menu, x;
        int idx;
        printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)스택 비우기 (6)스택 용량 (7)스택 데이터 (8)스택빔? (9)스택풀? (10)검색 (0)종료 : ");
        scanf("%d", &menu);

        if (menu == 0) break;
        switch (menu)
        {
        case 1:     //푸시
            printf("데이터 : ");
            scanf("%d", &x);
            if (Push(&s, x) == -1)
                puts("\a오류 : 푸시에 실패하였습니다.");
            break;

        case 2:     //팝
            if (Pop(&s, &x) == -1)
                puts("\a오류 : 팝에 실패하였습니다.");
            else
                printf("팝 데이터는 %d입니다.\n", x);
            break;
        case 3:     //피크
            if (Peek(&s, &x) == -1)
                puts("\a오류 : 피크에 실패하였습니다.");
            else
                printf("Peek 데이터는 %d 입니다.\n", x);
            break;
        case 4:     //출력
            Print(&s);
            break;
        case 5:     //비우기
            Clear(&s);
            puts("\a데이터를 비웠습니다.");
            break;
        case 6:     //스택용량보기
            printf("스택 용량은 %d\n", Capacity(&s));
            break;
        case 7:
            printf("스택에 쌓여 있는 데이터 수 : %d\n", Size(&s));
            break;
        case 8:
            if (IsEmpty(&s))
                puts("스택이 비어있습니다.");
            else
                puts("스택이 비어있지않습니다.");
            break;
        case 9:
            if (IsFull(&s))
                puts("스택이 꽉 찼습니다.");
            else
                puts("스택이 꽉 차지않았습니다.");
            break;
        case 10:
            printf("검색할 데이터를 넣어주세요 데이터 : ");
            scanf("%d", &x);
            if ((idx = Search(&s, x)) == -1)
                puts("검색에 실패하였습니다.");
            else
                printf("검색된 데이터는 x[%d]에 있습니다.", idx);
            break;
        }
    }
    Terminate(&s);
    return 0;
}
