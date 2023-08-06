#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct lecture {
	int start, end;
};

bool cmpV(const lecture& l1, const lecture& l2) {
	/*if (l1.start == l2.start) {
		return l1.end < l2.end;
	}*/

	return l1.start < l2.start;
}

struct cmpPQ {
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};

int getMaxSize(vector<lecture>& lecV, int n) {

	priority_queue<int, vector<int>, cmpPQ> pq;

	pq.push(lecV[0].end);

	for (int i = 1; i < n; i++) {
		pq.push(lecV[i].end);

		if (pq.top() <= lecV[i].start) {
			pq.pop();
		}
	}

	return pq.size();
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<lecture> lecV(n);

	for (int i = 0; i < n; i++) {
		cin >> lecV[i].start >> lecV[i].end;
	}

	sort(lecV.begin(), lecV.end(), cmpV);

	cout << getMaxSize(lecV, n);

	return 0;
}

//https://wooono.tistory.com/393

/*
#include <iostream>
#include <algorithm>

using namespace std;

#define SIZE (int)1e9

int add[SIZE + 1] = { 0 };
int sub[SIZE + 1] = { 0 };

int dp[SIZE + 1] = { 0 };


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int idxA, idxS;

	for (int i = 0; i < n; i++) {
		cin >> idxA >> idxS;
		add[idxA] = 1;
		sub[idxS] = -1;
	}

	int ans = 0;

	for (int i = 1; i <= SIZE; i++) {
		dp[i] = dp[i - 1];
		dp[i] += add[i];
		dp[i] += sub[i];

		ans = max(dp[i], ans);
	}

	cout << ans;
}
*/