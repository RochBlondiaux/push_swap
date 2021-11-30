#include <stdio.h>

int main(void)
{
	int	amount = 1000;
	FILE *fp;

	fp = fopen("test.txt", "w+");

	while (amount > 0)
	{
		fprintf(fp, "%d ", amount);
		amount--;
	}
	fclose(fp);
}