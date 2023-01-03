#include <stdio.h>

int top = -1; // flag
int stack[6] = {0};

int postFix_calculator(char postFix[],int n);
void push(int n);
int pop();

int main() {
	
	int i, n;
	char postFix[12];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf(" %c", &postFix[i]);
	}

	printf("%d", postFix_calculator(postFix ,n));


}

int postFix_calculator(char postFix[],int n) {
	int i;

	for (i = 0; i < n; i++)
	{
		if ('0' <= postFix[i] && postFix[i] <= '9')
			push(postFix[i]);

		else
		{
			switch (postFix[i])
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

void push(int n)
{
	stack[++top] = n - '0';
}

int pop()
{
	return stack[top--];
}

//숫자가 3개이상 연산은 안됨