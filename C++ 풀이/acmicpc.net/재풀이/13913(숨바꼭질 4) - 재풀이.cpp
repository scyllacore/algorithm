#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX (int)1e5

int visited[MAX + 1];
int parent[MAX + 1];
int n, k;

int bfs() {
	queue<int> bfsQ;
	visited[n] = 1;
	bfsQ.push(n);

	for (; !bfsQ.empty();) {
		int cur = bfsQ.front();
		bfsQ.pop();

		if (cur == k) {
			return visited[cur] - 1;
		}

		if (cur >= 1 && !visited[cur - 1]) {
			visited[cur - 1] = visited[cur] + 1;
			bfsQ.push(cur - 1);

			parent[cur - 1] = cur;
		}

		if (cur <= MAX - 1 && !visited[cur + 1]) {
			visited[cur + 1] = visited[cur] + 1;
			bfsQ.push(cur + 1);

			parent[cur + 1] = cur;
		}

		if (cur <= MAX / 2 && !visited[cur * 2]) {
			visited[cur * 2] = visited[cur] + 1;
			bfsQ.push(cur * 2);

			parent[cur * 2] = cur;
		}
	}

}

void route() {
	/*vector<int> routeV(1,k);
	k(17)를 먼저 넣고

	if (n == k) {
		cout << k;
		return;
	}

	나머지 값 넣는 형태. 그러나 n==k와 같으면 문제되어 위에 조건을 넣어준 형태이다.
	int next = k;
	for (;next != n;) {
		next = parent[next];
		routeV.push_back(next);
	}

	for (int i = routeV.size() - 1; i >= 0; i--) {
		cout << routeV[i] << ' ';
	}*/

	vector<int> routeV;

	int next = k;
	for (; next != n;) { // k부터 넣을 수 있는지 판단. n과 같다면 이동이 없음으로 넣는 것이 없어야 한다.
		routeV.push_back(next); // 
		next = parent[next]; // Line 72,73의 순서를 바꾸었다. n은 빼고 k부터 모두 넣는다.
	}
	routeV.push_back(n); // 이동이 없어도 모든 경로가 나와야하기 때문에 n은 항상 들어간다.

	for (int i = routeV.size() - 1; i >= 0; i--) {
		cout << routeV[i] << ' ';
	}

}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	cout << bfs() << '\n';

	route();

	return 0;
}