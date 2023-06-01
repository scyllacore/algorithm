#include <cstdio>

typedef struct candidate {
	int num[4]; // 4가지 상황에 대한 값을 각각 저장. [0] : 점수 총합 , [1] : 3의 개수,[2] : 2의 개수,[3] : 1의 개수. 
}candidate;

int isValid(candidate* candi) {

	int maxScore = 0;

	for (int i = 0; i <= 3; i++) {

		int ansVal = 0, ansCandi = 1;

		for (int j = 1; j <= 3; j++) { // 한 상황에 대해 최댓값을 내주는 후보자를 구함.
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
					현재 쌍이 같은 값이 나왔는데, 현 상황에 대한 최댓값과 같다면 정확한 비교가 불가능 함으로 다음 상황으로 가야됨.
					ex) 예시 입력 코드
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
			/* 현재 쌍이 같은 값이 나왔지만 현 상황에 대한 최댓값과 달라 현 상태에서 최대값을 하나만 고를 수 있을 때(flag가 1인 경우),
			현 상황에 대해 최댓값을 내주는 후보자의 점수값과 이전에 계산된 점수의 최대값(maxScore)과 같아야 한다.
			만일 다른 경우(candi[ansCandi].num[0] != maxScore) 문제에서의 최대 점수 조건을 만족하지 못함으로 다음 상황으로 가야된다.
			ex) 예시 입력 코드
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

	candidate candi[4]; // 후보 1,2,3 . 0번째 인덱스는 안씀.

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
