#include <stdio.h>

long long factorial(long long n)
{
	if (n == 1) {// n�� 1�� ��
		printf("1! = 1\n");
		return 1;
	}    // 1�� ��ȯ�ϰ� ���ȣ���� ����

	printf("%d! = %d * %d!\n", n, n, n - 1);

	return n * factorial(n - 1);    // n�� factorial �Լ��� n - 1�� �־ ��ȯ�� ���� ����
}

int main()
{
	int n;

	scanf("%d", &n);

	printf("%lld", factorial(n));

	return 0;
}