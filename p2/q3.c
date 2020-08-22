#include <stdio.h>
#include <stdlib.h>

double  aveof(const int a[], int n)
{
    int i;
    double sum;

    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
    }
    sum = sum / n ;
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
		printf("학생수를 입력해주십시오 : ");
		scanf("%d", &num);
	}while(num <= 0);
	height = (int*)calloc(num,sizeof(int));
	for (i = 0; i < num; i++)
	{
		printf("height[%d] 키를 입력해주세요 : ", i);
		scanf("%d", &height[i]);
	}
	result = aveof(height, num);
    printf("키의 평균은 : ");
	printf("%d", result);
	free(height);
}