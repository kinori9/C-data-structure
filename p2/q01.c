#include <stdio.h>
#include <stdlib.h>

int	minof(const int a[], int n)
{
	int i;
	int min = a[0];
	for (i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
	}
	return min;
}

int	main(void)
{
	int i;
	int *height;
	int num;
	int result;
	
	printf("학생들 키의 최솟값을 구합니다.");
	do
	{
		printf("학생수를 입력해주십시오");
		scanf("%d", &num);
	}while(num <= 0);
	height = (int*)calloc(num,sizeof(int));
	for (i = 0; i < num; i++)
	{
		printf("height[%d] : 키를 입력해주세요", i);
		scanf("%d", &height[i]);
	}
	result = minof(height, num);
	printf("최솟값은 :");
	printf("%d", result);
	free(height);
}