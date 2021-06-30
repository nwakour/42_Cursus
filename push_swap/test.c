#include <stdio.h>

int normalize_range(int len, int a)
{
	while (a > len)
		a = a - len;
	return a;
}

int main()
{
	int nor = normalize_range(10, 35);
	printf("%d\n", nor);
	return 0;
}
