#include <stdio.h>
#include <stdlib.h>

int	sumof(const int a[], int n)
{
	int i;
	int sum;

    sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

int	main(void)
{
	int i;
	int *height;
	int num;
	int result;
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
	result = sumof(height, num);
    printf("키의 합계는 : ");
	printf("%d", result);
	free(height);
}