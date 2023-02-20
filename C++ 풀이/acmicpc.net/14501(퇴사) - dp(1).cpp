#include <iostream>
#include <algorithm>

using namespace std;

struct dayInfo {
	int t;
	int p;
};


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	dayInfo* day = new dayInfo[n + 1];
	int* dp = new int[n + 1]{ 0 };

	int i, j;

	for (i = 1; i <= n; i++) {
		cin >> day[i].t >> day[i].p;
		dp[i] = day[i].p;
	}

	for (i = 2; i <= n; i++) {
		for (j = 1; j < i; j++) {
			if (j + day[j].t <= i) {  //1. 2(j) + 3(day[j].t) = 5인데 실제 해석은 2일 부터 3일간 (2,3,4일에) 일을하는 경우이다.
				dp[i] = max(day[i].p + dp[j], dp[i]); //2. i(당일)날에 무조건 일을 해서 받은 금액과 i 전날 중에서 계산된 최대 금액을 합쳐 당일 최대 금액을 갱신한다. 
			}
		}
	}

	int maxVal = 0;

	for (i = 1; i <= n; i++) {
		if (i + day[i].t <= n + 1) { //3. 2번에서 당일 날 무조건 일을 하도록 처리했기 때문에 당일 날 일을 못하는 경우를 생각하지 않았다. 이 부분을 처리해준다. 
			maxVal = max(dp[i], maxVal);
		}
	}

	cout << maxVal;
	return 0;
}

//https://mygumi.tistory.com/151