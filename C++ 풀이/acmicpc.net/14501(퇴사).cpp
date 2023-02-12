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
	1 200
	일 때도
	***sumT는 사용한 날이 아니고 현재 위치를 나타내고 있는 날이다. 사용 되어야 할 날(durTime)을 더한다면 현재의 날(sumT)로 이동할 수 있는 것이다.
	현재 위치의 날에서 그 당일의 날까지 포함해 어떤 강의를 선택해야할지 결정해야한다.
	ex) sumT가 5이고 durTime을 3으로 처리한다면 5일날 강의를 5,6,7일 하기로 결정한 것이다.

	현재 sumT가 8이라면 이전에 sumT가 7일 때 사용되어야 할 날이 1일이기에 현재날이 8일이 된 것이고, 이는 7일(마지막 날)에 강의를 한 것이다.
	결국 7일을 사용할 수 있기 때문에 245가 나온다.

	만약 문제의 예시처럼 7일 때 사용되어야할 날이 2일이라면 7일과 8일을 써야되기 때문에 이는 범위를 넘음으로 7일을 쓸 수 없다.
	따라서 dayMax+1 해줌으로써 마지막 날의 사용여부를 결정할 수 있으며 이에 따라 이 코드는 sumT가 maxDay+2가 될 때 만큼 재귀탐색을 할 수 있다.
	*/

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