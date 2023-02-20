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

	int i;

	for (i = 1; i <= n; i++) {
		cin >> day[i].t >> day[i].p;
	}

	int* dp = new int[n + 2]{ 0 };


	for (int i = n; i >= 1; i--) {
		if (i + day[i].t > n + 1) {
			dp[i] = dp[i + 1]; // 기간이 넘어가면 해당날 일을 할 수 없음으로 다음 날의 최대 금액으로 해당 날의 금액을 갱신한다. 
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + day[i].t] + day[i].p); // 당일에 일을 할 수 있다면 해당날에 일을 하지 않는 경우와 , 당일에 일을 하고 받는 금액과 일한 뒤에 받을 수 있는 최대 금액(계산되어있음)과 더해준다. 
		}
	}

	cout << dp[1];
	return 0;
}

//https://yabmoons.tistory.com/519