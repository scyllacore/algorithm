#include <stdio.h>

#define MAXINPUT 10

int gcd(int n, int m);
int lcm(int n, int m);

int main()
{
	// FILE *fi = fopen("input.txt", "r");
	// FILE *fo = fopen("output.txt", "w");

	int i, size;
	int inputs[MAXINPUT];
	int g, l;

	// 입력의 갯수 읽어오기
	//fscanf(fi, "%d", &size);
	scanf("%d", &size);
	// 입력 읽어오기
	for (i = 0; i < size; i++)
		scanf("%d", &inputs[i]);

	// 최소공배수, 최대공약수 구하기
	g = gcd(inputs[0], inputs[1]);
	l = lcm(inputs[0], inputs[1]);

	for (i = 2; i < size; i++)
	{
		g = gcd(g, inputs[i]);
		l = lcm(l, inputs[i]);
	}

	// 결과 출력
	//fprintf(fo, "%d %d", g, l);
	printf("%d %d", g, l);
	// fclose(fi);
	//fclose(fo);

	return 0;
}

int gcd(int n, int m)
{
	if (m == 0)
		return n;
	else
		return gcd(m, n % m);
}

int lcm(int n, int m)
{
	return n * m / gcd(n, m);
}

// 처음에  n이 작은수고 m이 큰수라면 , 연산 후 n->m , m->n으로 감