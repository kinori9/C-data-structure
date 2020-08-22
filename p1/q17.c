#include <stdio.h>

void	spira(int n)
{
	int i, j, k;
	int result;

	for (i = 1; i <= n; i++)
	{
		for (k = 0; k < (result = n - i); k++)
			putchar(' ');
		for (j = 0; j < (i - 1) * 2 + 1; j++)
			putchar('*');
		putchar('\n');
	}
}

int		main(void)
{
	int n;
	puts("입력해주세요 숫자를");
	scanf("%d", &n);
	spira(n);
}