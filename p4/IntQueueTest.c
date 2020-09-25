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
		printf("현재 데이터 수: %d / %d \n", Size(&q), Capacity(&q));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0)종료 : ");
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
		}
	}
	Terminate(&q);
	return 0;
}
