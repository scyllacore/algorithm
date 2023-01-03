#include <stdio.h>

#define MAX_SIZE 13
int lotto[MAX_SIZE];
int combi[MAX_SIZE];
int k;

void dfs(int start, int depth) {

	if (depth == 6) {                    //탈출조건
		for (int i = 0; i < 6; i++) {
			printf("%d ", combi[i]);    //조합하나를 출력한 뒤 탈출
		}
		printf("\n");
		return;
	}
	else {
		for (int i = start; i < k; i++) {    //lotto배열 0부터 k-1까지 탐색함     
			combi[depth] = lotto[i];    //depth는 깊이 -> 0~5번째 깊이까지 재귀를통해 새로 탐색한 숫자를 넣음.    
			dfs(i + 1, depth + 1);            //재귀 들어가는 부분 , 하나의 깊이를 탐색 후 저장했으니 다음 함수호출할때는 깊이+1을 해줘야함.
		}
	}
}

int main() {

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &lotto[i]);
	}

	dfs(0, 0);
	printf("\n");

	return 0;
}


/* 설명용
#include <stdio.h>

#define MAX 13
int lotto[MAX];
int combi[MAX];
int k;

void dfs(int start, int depth)
{
	int i;
	if (depth == 3)
	{
		for (i = 0; i < 3; i++)
			printf("%d ", combi[i]);
		printf("\n");
		return;
	}
	else
	{
		for (i = start; i < k; i++)
		{
			combi[depth] = lotto[i]; // i는 하나를 고르고 다음 로또 구슬을 중 하나를 선택
			dfs(i + 1, depth + 1);
		}
	}

}

int main() {
	int i;

	scanf("%d", &k);

	for (i = 0; i < k; i++)
	{
		scanf("%d", &lotto[i]);
	}

	dfs(0, 0);

	return 0;

}
*/
