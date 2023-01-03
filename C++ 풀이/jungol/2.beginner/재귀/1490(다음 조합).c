#include <stdio.h>

int stack[100];
int N, K;
int top = 0;
int data[1000][10] = { {0} };
int cnt = 0;

void print_data() {
	for (int i = 0; i < K; i++) {
		//printf("%d ", stack[i]);
		data[cnt][i] = stack[i];
	}
	//printf("\n");
	cnt++;
}

void combi(int start) {
	if (top == K) {
		print_data();
		return;
	}
	for (int i = start + 1; i <= N; i++) {
		stack[top++] = i;
		combi(i);
		stack[--top] = -1;
	}
	return;
}

void compare(int arr[]) {

	int check = 0, zero = 0;
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < K; j++)
		{
			if (data[i][j] == arr[j])
				check++;
			if (data[i + 1][j] == 0)
				zero++;
		}

		if (check == K) {
			if (zero == K)
			{
				printf("NONE");
				return;
			}

			for (int j = 0; j < K; j++)
				printf("%d ", data[i + 1][j]);
			//printf("\n");
			return;
		}
		check = 0;
		zero = 0;
	}
	//printf("�߸��� ���� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���");
}

int main() {

	int arr[11] = { 0 };

	scanf("%d %d", &N, &K);

	if ((N < 5 || N>10)) {
		//printf("������ ���� �Է��ϼ���");
		return 0;
	}
	else if ((K<1 || K>N)) {
		//printf("������ ���� �Է��ϼ���");
		return 0;
	}

	for (int i = 0; i < K; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 100; i++)
	{
		stack[i] = -1;
	}

	//printf("\n");
	combi(-1);
	//printf("\n");
	compare(arr);
	/*for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < K; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}*/
	return 0;


}
