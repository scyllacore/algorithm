#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct homework {
	int d;
	int w;
};

bool cmp(const homework& hw1, homework& hw2) {
	return hw1.d < hw2.d;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	priority_queue<int, vector<int>, greater<>> scorePQ;
	vector<homework> hwV;
	int n,i,d,w;
	cin >> n;
	int maxScore = 0;

	for (i = 0; i < n; i++) {
		cin >> d >> w;
		hwV.push_back({ d,w });
	}
	
	sort(hwV.begin(), hwV.end(), cmp);

	for (i = 0; i < n; i++) {
		maxScore += hwV[i].w;
		scorePQ.push(hwV[i].w);

		if (scorePQ.size() > hwV[i].d) {
			maxScore -= scorePQ.top();
			scorePQ.pop();
		}
	}

	cout << maxScore;
	return 0;


}


