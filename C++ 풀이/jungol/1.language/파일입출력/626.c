# include <stdio.h>
# define SWAP(a,b) tmp = a; a = b; b = tmp

int main()
{
	int num1, num2;
	int sum = 0, tmp, i;

	fscanf(stdin, "%d %d", &num1, &num2);

	if (num1 > num2)
	{
		SWAP(num1, num2);
	}

	for (i = num1; i <= num2; i++)
	{
		sum += i;
	}

	fprintf(stdout, "%d", sum);


}