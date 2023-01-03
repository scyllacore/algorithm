#include <stdio.h>

int stack[13];
int lotto[13] = { 0 };
int N, top = 0;


void print() {
	for (int i = 0; i < 6; i++) {
		printf("%d ", stack[i]);
	}
	printf("\n");
}

void combi(int start) {
	if (top == 6) {
		print();
		return;
	}
	for (int i = start; i < N; i++) {
		stack[top++] = lotto[i];
		combi(i+1);
		stack[--top] = -1;
	}
	return;
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &lotto[i]);
	}

	for (int i = 0; i < 13; i++)
	{
		stack[i] = -1;
	}

	combi(0);

	return 0;


}
