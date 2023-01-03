#include <iostream>
#include <deque>
using namespace std;

int n, k;
bool visited[100001] = { 0 };
deque<pair<int, int>> spotBFS;

void BFS() {

	int spot, second;

	while (!spotBFS.empty()) {

		spot = spotBFS.front().first;
		second = spotBFS.front().second;
		spotBFS.pop_front();

		if (spot == k) {
			cout << second;
			return;
		}

		if (spot >= 1 && spot <= 50000 && !visited[spot * 2]) {
			visited[spot * 2] = 1;
			spotBFS.push_front(make_pair(spot * 2, second));
		}

		if (spot >= 1 && !visited[spot - 1]) {
			visited[spot - 1] = 1;
			spotBFS.push_back(make_pair(spot - 1, second + 1));
		}

		if (spot <= 99999 && !visited[spot + 1]) {
			visited[spot + 1] = 1;
			spotBFS.push_back(make_pair(spot + 1, second + 1));
		}

	}


}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	visited[n] = 1;
	spotBFS.push_back(make_pair(n, 0));
	BFS();

	return 0;

}
