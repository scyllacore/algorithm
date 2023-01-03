#include <stdio.h>

int main()
{
	int nArr[101];
	int n, i, size = 0;
	char cmd;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf(" %c", &cmd);

		if (cmd == 'i') scanf(" %d", &nArr[size++]);
		else if (cmd == 'o')
		{
			if (!size) printf("empty\n");
			else printf("%d\n", nArr[--size]); // 꺼낸값
		}
		else printf("%d\n", size); //사이즈
	}

	return 0;
}