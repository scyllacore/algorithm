#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;

	scanf("%d", &n);

	// 큐의 최대 개수는 명령어의 개수와 같다.
	int *queue = malloc(sizeof(int)*n);
	int front=0, rear=0;

	while (n)
	{
		char opCode;
		scanf(" %c", &opCode);

		// 입력 처리
		if (opCode == 'i')
		{
			scanf(" %d", &queue[rear++]);
		}
		// 출력 처리
		else if (opCode == 'o')
		{
			// 데이터가 없는 경우
			if (front == rear)
			{
				printf("empty\n");
			}
			// 데이터가 있는 경우
			else
			{
				printf("%d\n",queue[front++]);
			}
		}
		// 데이터 수 확인
		else if (opCode == 'c')
		{
			printf("%d\n" ,rear - front);
		}

		n--;
	}

	free(queue);
	return 0;
}