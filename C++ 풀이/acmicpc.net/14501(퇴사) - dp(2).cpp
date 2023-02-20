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
			dp[i] = dp[i + 1]; // �Ⱓ�� �Ѿ�� �ش糯 ���� �� �� �������� ���� ���� �ִ� �ݾ����� �ش� ���� �ݾ��� �����Ѵ�. 
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + day[i].t] + day[i].p); // ���Ͽ� ���� �� �� �ִٸ� �ش糯�� ���� ���� �ʴ� ���� , ���Ͽ� ���� �ϰ� �޴� �ݾװ� ���� �ڿ� ���� �� �ִ� �ִ� �ݾ�(���Ǿ�����)�� �����ش�. 
		}
	}

	cout << dp[1];
	return 0;
}

//https://yabmoons.tistory.com/519