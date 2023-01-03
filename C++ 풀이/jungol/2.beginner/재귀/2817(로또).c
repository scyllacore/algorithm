#include <stdio.h>

#define MAX_SIZE 13
int lotto[MAX_SIZE];
int combi[MAX_SIZE];
int k;

void dfs(int start, int depth) {

	if (depth == 6) {                    //Ż������
		for (int i = 0; i < 6; i++) {
			printf("%d ", combi[i]);    //�����ϳ��� ����� �� Ż��
		}
		printf("\n");
		return;
	}
	else {
		for (int i = start; i < k; i++) {    //lotto�迭 0���� k-1���� Ž����     
			combi[depth] = lotto[i];    //depth�� ���� -> 0~5��° ���̱��� ��͸����� ���� Ž���� ���ڸ� ����.    
			dfs(i + 1, depth + 1);            //��� ���� �κ� , �ϳ��� ���̸� Ž�� �� ���������� ���� �Լ�ȣ���Ҷ��� ����+1�� �������.
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


/* �����
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
			combi[depth] = lotto[i]; // i�� �ϳ��� ���� ���� �ζ� ������ �� �ϳ��� ����
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
