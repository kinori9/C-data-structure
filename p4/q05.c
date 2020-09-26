#include<stdio.h>
#include"IntQueue.h"

int		main(void)
{
	IntQueue q;
	if (Initialize(&q, 10) == -1)
	{
		puts("큐의 생성에 실패하였습니다.");
		return 1;
	}
	while (1)
	{
		int m, x;
		int idx;
		printf("현재 데이터 수: %d / %d \n", Size(&q), Capacity(&q));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)검색1 (6)검색2 (7)빔? (8)꽉참? (9)클리어 (10)사이즈 (11)용량 (0)종료 : ");
		scanf("%d", &m);

		if (m == 0)
			break;
		switch (m)
		{
		case 1:
			printf("입력할 데이터를 넣어주세요 : ");
			scanf("%d", &x);
			if (Enque(&q, x) == -1)
				puts("데이터가 꽉찼습니다.");			
			break;
		case 2:
			if (Deque(&q, &x) == -1)
				puts("데이터가 없습니다.");
			else
				printf("디큐한데이터는 %d 입니다\n", x);
			break;
		case 3:
			if (Peek(&q, &x) == -1)
				puts("데이터가 없습니다.");
			else
				printf("피크 데이터는 %d 입니다.", x);
			break;
		case 4:
			Print(&q);
			putchar('\n');
			break;
		case 5:
			printf("검색할데이터를 입력해주십시오 : ");
			scanf("%d", &x);
			if ((idx = Search(&q, x)) == -1)
				puts("데이터가 없습니다.");
			else
				printf(" 검색한 데이터의 상대적 위치는 %d 입니다\n", idx);
			break;
		case 6:
			printf("검색할데이터를 입력해주십시오 : ");
			scanf("%d", &x);
			if ((idx = Search2(&q, x)) == -1)
				puts("데이터가 없습니다.");
			else
				printf(" 검색한 데이터의 위치는 %d 입니다\n", idx);
			break;
		case 7:
			if (IsEmpty(&q))
				puts("데이터가 비어있습니다.");
			else
				puts("데이터가 비어있지않습니다.");
			break;
		case 8:
			if (IsFull(&q))
				puts("데이터가 꽉찼습니다.");
			else
				puts("데이터가 꽉차지않았습니다.");
			break;
		case 9:
			Clear(&q);
			puts("클리어 완료했습니다.\n");
			break;
		case 10:
			printf("현재 사이즈는 %d입니다.\n",Size(&q));
			break;
		case 11:
			printf("현재 용량은 %d입니다.\n",Capacity(&q));
			break;
		}
	}
	Terminate(&q);
	return 0;
}
