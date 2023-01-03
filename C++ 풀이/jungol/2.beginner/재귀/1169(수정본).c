#include <stdio.h>

int nArr[7] = { 1, 0 }; // 0번째로 시작이 아닌 1번째로 시작
int mask[7]; // 전에 이미 쓴 숫자에 대한 정보를 1로 저장해둠
int n, m;

void Print()
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%d ", nArr[i]);
	printf("\n");
}

void Disp1(int count, int depth)
{
	int i;

	if (count== n)
	{
		Print();
		return;
	}

	for (i = 1; i <= 6; i++)
	{
		nArr[depth] = i;
		Disp1(count + 1 , depth + 1);
	}
}

void Disp2(int count, int depth)
{
	int i;

	if (count == n)
	{
		Print();
		return;
	}

	for (i = nArr[depth - 1]; i <= 6; i++)
	{
		nArr[depth] = i;
		Disp2(count + 1, depth + 1);
	}
}

void Disp3(int count, int depth)
{
	int i;

	if (count == n)
	{
		Print();
		return;
	}

	for (i = 1; i <= 6; i++)
	{
		if (mask[i]) continue;
		nArr[depth] = i;
		mask[i] = 1;
		Disp3(count + 1, depth + 1);
		mask[i] = 0;
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	switch (m)
	{
	case 1: Disp1(0, 1); break;
	case 2: Disp2(0, 1); break;
	case 3: Disp3(0, 1); break;
	}

	return 0;
}