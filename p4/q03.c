#include <stdio.h>
#include "ArrayIntQueue.h"

int		main(void)
{
	ArrayIntQueue que;
	initialize(&que, 12);

	while (1)
	{
		int menu, x;
		printf("현재 데이터 수 : %d\n", que.num);
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0) 종료 : ");
		scanf("%d", &menu);
		if (menu == 0) break;
		switch (menu)
		{
		case 1:
			puts("데이터를 입력해주십시오 : ");
			scanf("%d", &x);
			if (Enqueue(&que, x) == -1)
				puts("데이터가 꽉 찼습니다.");
			break;
		case 2:
			if (Dequeue(&que) == -1)
				puts("데이터가 없습니다.");
			else
				puts("데이터 1개를 삭제하였습니다.");
			break;
		case 3:
			if (Peek(&que, x) == -1)
				puts("데이터가 없습니다.");
			else
				printf("피크 데이터는 %d 입니다.\n", x);
			break;

		case 4:
			Print(&que);
			break;
		}
	}
	Terminate(&que);
	return 0;
}
