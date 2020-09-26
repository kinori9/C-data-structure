#include <stdio.h>
#include "Deck.h"

int		main(void)
{
	Deck d;
	if (Initialize(&d, 12) == -1)
	{
		puts("덱에 생성에 실패하였습니다.");
		return 1;
	}
		

	while (1)
	{
		int m, x;
		int idx;
		printf("현재 데이터 수 : %d / %d \n",Size(&d),Capacity(&d));
		printf("(1)<인큐 (2)인큐> (3)<디큐 (4)디큐> (5)<피크 (6)피크> (7)출력 (0)종료 : ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m)
		{
		case 1:
			puts("데이터를 입력해주세요");
			scanf("%d", &x);
			if (Enque(&d, DeckA, x) == -1)
				puts("데이터 입력에 실패했습니다.\n");
			else
				puts("데이터 입력에 성공했습니다.\n");
			break;

		case 2:
			puts("데이터를 입력해주세요");
			scanf("%d", &x);
			if (Enque(&d, DeckB, x) == -1)
				puts("데이터 입력에 실패했습니다.\n");
			else
				puts("데이터 입력에 성공했습니다.\n");
			break;
			
		case 3:
			if (Deque(&d, DeckA, &x) == -1)
				puts("데이터 인출에 실패했습니다.\n");
			else
				printf("인출한데이터는 %d 입니다\n", x);
			break;

		case 4:
			if (Deque(&d, DeckB, &x) == -1)
				puts("데이터 인출에 실패했습니다.\n");
			else
				printf("인출한데이터는 %d 입니다\n", x);
			break;
		case 5:
			if (Peek(&d, DeckA, &x) == -1)
				puts("데이터가 없습니다.");
			else
				printf("피크데이터는 %d입니다.",x);
			break;
		case 6:
			if (Peek(&d, DeckB, &x) == -1)
				puts("데이터가 없습니다.");
			else
				printf("피크데이터는 %d입니다.", x);
			break;
		case 7:
			Print(&d);
			break;
		}
	}
	Terminate(&d);
	return 0;
}
