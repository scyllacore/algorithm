#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDay;
int maxProfit = 0;

typedef struct day {
	int durTime; // duration time
	int money;
}Day;

Day* baekjoon;

void maxDFS(int sumT, int sumP) {

	if (sumT > maxDay + 1) { // maxDay가 아니고 maxDay+1을 해줘야 한다.
		return;
	}

	int i;

	maxProfit = max(sumP, maxProfit);

	/*입력
	3
	1 1
	1 2
	1 3 에 대해
	sumT가 4일 때, sumT가 3인 때의 1+2+3(sumP)값을 최댓값으로 만든다.
	*/

	for (i = sumT; i <= maxDay; i++) {
		maxDFS(i + baekjoon[i].durTime, sumP + baekjoon[i].money);
	}

	/*
	입력
	7
	3 10
	5 20
	1 10
	1 20
	2 15
	4 40
	2 200
	일 때도 
	sumT가 9일 때, sumT가 7일 때의 sumP를 최댓값으로 만든다.
	*/

	// 따라서 dayMax+1 해줌으로써 마지막 P(i)값도 누적 될 수 있게 되며 이에 따라 이 코드는 최대 maxDay+2만큼 재귀탐색을 할 수 있다.

}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> maxDay;

	int i;

	baekjoon = new Day[maxDay + 1];

	for (i = 1; i <= maxDay; i++) {

		cin >> baekjoon[i].durTime >> baekjoon[i].money;
	}

	maxDFS(1, 0);

	cout << maxProfit;

}

//index를 1로 지정하고 고친 코드