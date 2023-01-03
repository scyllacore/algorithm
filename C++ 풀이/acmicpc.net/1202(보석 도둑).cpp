#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 300000

int bag[MAX];

struct jewelry {
	int weight;
	int price;
};

jewelry jewel[MAX];
priority_queue<int> pq;

bool cmp(jewelry& j1, jewelry& j2) {
	return j1.weight < j2.weight;
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	int i;

	for (i = 0; i < n; i++) {
		cin >> jewel[i].weight >> jewel[i].price;
	}

	for (i = 0; i < k; i++) {
		cin >> bag[i];
	}

	sort(jewel, jewel + n,cmp);
	sort(bag, bag + k);

	unsigned long long ans = 0;
	int idx = 0;

	for (i = 0; i < k; i++) {

		while (idx < n && jewel[idx].weight <= bag[i]) {
			pq.push(jewel[idx++].price);
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;

	return 0;

}

