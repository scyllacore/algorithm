#include <cstdio>

typedef struct candidate {
	int num[4]; // 4���� ��Ȳ�� ���� ���� ���� ����. [0] : ���� ���� , [1] : 3�� ����,[2] : 2�� ����,[3] : 1�� ����. 
}candidate;

int isValid(candidate* candi) {

	int maxScore = 0;

	for (int i = 0; i <= 3; i++) {

		int ansVal = 0, ansCandi = 1;

		for (int j = 1; j <= 3; j++) { // �� ��Ȳ�� ���� �ִ��� ���ִ� �ĺ��ڸ� ����.
			if (candi[j].num[i] > ansVal) {
				ansCandi = j;
				ansVal = candi[j].num[i];
			}
		}

		if (i == 0) {
			maxScore = ansVal;
		}

		int flag = 1;

		for (int j = 1; j < 3; j++) {
			for (int k = j + 1; k <= 3; k++) {
				if (candi[j].num[i] == candi[k].num[i] && candi[k].num[i] == ansVal) {
					/*
					���� ���� ���� ���� ���Դµ�, �� ��Ȳ�� ���� �ִ񰪰� ���ٸ� ��Ȯ�� �񱳰� �Ұ��� ������ ���� ��Ȳ���� ���ߵ�.
					ex) ���� �Է� �ڵ�
					10
					1 2 3
					1 2 3
					1 2 3
					1 2 3
					1 2 3
					1 3 2
					1 3 2
					1 3 2
					1 3 2
					1 3 2
					*/
					flag = 0;
				}
			}
		}


		if (!flag || candi[ansCandi].num[0] != maxScore) {
			/* ���� ���� ���� ���� �������� �� ��Ȳ�� ���� �ִ񰪰� �޶� �� ���¿��� �ִ밪�� �ϳ��� �� �� ���� ��(flag�� 1�� ���),
			�� ��Ȳ�� ���� �ִ��� ���ִ� �ĺ����� �������� ������ ���� ������ �ִ밪(maxScore)�� ���ƾ� �Ѵ�.
			���� �ٸ� ���(candi[ansCandi].num[0] != maxScore) ���������� �ִ� ���� ������ �������� �������� ���� ��Ȳ���� ���ߵȴ�.
			ex) ���� �Է� �ڵ�
			4
			1 2 3
			2 1 3
			3 2 1
			2 3 1
			*/
			continue;
		}

		return ansCandi;
	}

	return maxScore * -1;
}

int main() {

	candidate candi[4]; // �ĺ� 1,2,3 . 0��° �ε����� �Ⱦ�.

	for (int i = 1; i <= 3; i++) {
		candi[i].num[0] = candi[i].num[1] = candi[i].num[2] = candi[i].num[3] = 0;
	}

	int n;
	scanf("%d", &n);
	int score;


	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &score);
			candi[j].num[0] += score;
			candi[j].num[4 - score]++;
		}
	}

	int ans = isValid(candi);

	if (ans > 0) {
		printf("%d %d", ans, candi[ans].num[0]);
	}
	else {
		printf("%d %d", 0, ans * -1);
	}

	return 0;
}
