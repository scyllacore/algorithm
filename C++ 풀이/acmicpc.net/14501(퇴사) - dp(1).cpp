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
			if (j + day[j].t <= i) {  //1. 2(j) + 3(day[j].t) = 5�ε� ���� �ؼ��� 2�� ���� 3�ϰ� (2,3,4�Ͽ�) �����ϴ� ����̴�.
				dp[i] = max(day[i].p + dp[j], dp[i]); //2. i(����)���� ������ ���� �ؼ� ���� �ݾװ� i ���� �߿��� ���� �ִ� �ݾ��� ���� ���� �ִ� �ݾ��� �����Ѵ�. 
			}
		}
	}

	int maxVal = 0;

	for (i = 1; i <= n; i++) {
		if (i + day[i].t <= n + 1) { //3. 2������ ���� �� ������ ���� �ϵ��� ó���߱� ������ ���� �� ���� ���ϴ� ��츦 �������� �ʾҴ�. �� �κ��� ó�����ش�. 
			maxVal = max(dp[i], maxVal);
		}
	}

	cout << maxVal;
	return 0;
}

//https://mygumi.tistory.com/151