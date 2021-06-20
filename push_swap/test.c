#include <stdio.h>

int normalize_range(int max, int min, int a)
{
	int range;

	while (a > max)
		a = a - max;
	return a;
}

int main()
{
	int nor = normalize_range(9 , 0, 15);
	printf("%d\n", nor);
	return 0;
}