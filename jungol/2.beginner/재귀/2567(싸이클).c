#include<stdio.h>

int check[1001];
void func(int x);
int n, p;

int main()
{
	scanf("%d %d",&n,&p);
	int cnt = 0;
	//����Լ�
	func(n);

	//check[]�� 2�� ���� ���
	for (int i = 0; i < p; i++)
	{
		if (check[i] == 2)cnt++;
	}
	printf("%d\n",cnt);
}
void func(int x)
{
	//�ѹ� ���°��� �� ������?
	//�� ���� �� ������ �������� ����Ŭ��
	if (check[x] == 2)return;
	check[x]++;
	func(x * n % p);
}