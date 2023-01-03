#include <stdio.h>

int top = -1;
char math[12]; //처음 입력 받을 배열
int stack[6] = { 0 };

int cal(int m); //계산하기
void push(int a); //숫자 집어 넣기
int pop(void); //숫자 빼내기
int main(void)
{
	int m, i, result;

	scanf(" %d", &m); //m=피연산자와 연산자의 개수의 합

	for (i = 0; i < m; i++)
		scanf(" %c", &math[i]); //m개의 피연산자와 연산자 입력

	result = cal(m);

	printf("%d", result);

	return 0;
}
int cal(int m)
{
	int i;

	for (i = 0; i < m; i++)
	{
		if (math[i] >= '0' && math[i] <= '9') //숫자일 경우
			push(i);

		else //문자일 경우
		{
			switch (math[i])
			{
			case '+':
				stack[top] += pop();
				break;

			case '-':
				stack[top] -= pop();
				break;

			case '*':
				stack[top] *= pop();
				break;

			case '/':
				stack[top] /= pop();
				break;
			}
		}
	}

	return stack[0];
}
void push(int a)
{
	//a= math배열에서 숫자가 있는 위치
	//top= stack배열에서 숫자가 있는 마지막 위치

	top++;
	stack[top] = math[a] - '0';
}
int pop(void)
{
	return stack[top--];
}