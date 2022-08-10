#include <stdio.h>
#include <stdlib.h>

void printArr(int* arr, int n);

int main()
{
	int n,i,j;

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
	for ( i = 1; i < n; ++i)
	{
		int data = arr[i];

		// 비교할 값의 왼쪽 부터 검사해 자리를 찾는다.
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] < data) break;
			arr[j+1] = arr[j]; // 한칸씩 자리를 땡김
		}

		// 자리 확정 ,땡기고 빈자리에 삽입
		arr[j+1] = data;

		// 결과를 출력한다.
		printArr(arr, n);
	}

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
