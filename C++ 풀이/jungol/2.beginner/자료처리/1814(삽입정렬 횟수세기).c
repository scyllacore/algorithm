#include <stdio.h>
#include <stdlib.h>

void printArr(int* arr, int n);

int count = 0;

int main()
{
	int n;

	scanf("%d", &n);

	// 데이터를 저장할 행렬 생성
	int* arr = malloc(sizeof(int) * n);

	// 데이터 저장
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}

	// 첫번째 인덱스의 값이 있는 부분을 정렬된 배열로 가정
	// 정렬된 배열로 새 데이터 위치를 지정해 삽입해 정렬한다.
	for (int i = 1; i < n; ++i)
	{
		int data = arr[i];
		int index = i;

		// 비교할 값의 왼쪽 부터 검사해 자리를 찾는다.
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[j] < data) break;
			count++;
			arr[index--] = arr[j];
		}

		// 자리 확정
		arr[index] = data;

		// 결과를 출력한다.
		//printArr(arr, n);
	}

	printf("%d\n", count); // \ncount : 

	free(arr);
}

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
