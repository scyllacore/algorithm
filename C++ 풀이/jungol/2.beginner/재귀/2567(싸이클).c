#include<stdio.h>

int check[1001];
void func(int x);
int n, p;

int main()
{
	scanf("%d %d",&n,&p);
	int cnt = 0;
	//계산함수
	func(n);

	//check[]가 2인 갯수 출력
	for (int i = 0; i < p; i++)
	{
		if (check[i] == 2)cnt++;
	}
	printf("%d\n",cnt);
}
void func(int x)
{
	//한번 나온값이 또 나오면?
	//또 나올 떄 까지의 과정들이 싸이클임
	if (check[x] == 2)return;
	check[x]++;
	func(x * n % p);
}