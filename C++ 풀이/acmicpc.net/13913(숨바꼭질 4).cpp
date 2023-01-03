#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100001

int n, k;
int visited[MAX], parent[MAX];

void BFS(int spot) {

	queue<int> bfsQ;
	bfsQ.push(spot);
	visited[spot] = 1;

	int curSpot, nextSpot;

	while (!bfsQ.empty()) {

		curSpot = bfsQ.front();
		bfsQ.pop();

		if (curSpot == k) {

			vector<int> order; // vector<int> order(1,k); -> n과 k가 같을 때 문제가 된다. k를 무조건 넣어주면 안 됨.

			nextSpot = k; //  nextSpot = parent[k]; n과 k가 같을 때 k의 부모지점은 존재하지 않는다. 따라서 k값 자체도 n과 다른지 확인하여야 한다. 

			while (nextSpot != n) { 
				order.push_back(nextSpot);
				nextSpot = parent[nextSpot];
			}
			order.push_back(n);

			cout << visited[curSpot] - 1 << '\n';

			while (!order.empty()) {
				cout << order.back() << ' ';
				order.pop_back();
			}

			return;
		}

		if (curSpot >= 1 && !visited[curSpot - 1]) {
			nextSpot = curSpot - 1;
			visited[nextSpot] = visited[curSpot] + 1;
			parent[nextSpot] = curSpot;
			bfsQ.push(nextSpot);
		}

		if (curSpot <= 99999 && !visited[curSpot + 1]) {
			nextSpot = curSpot + 1;
			visited[nextSpot] = visited[curSpot] + 1;
			parent[nextSpot] = curSpot;
			bfsQ.push(nextSpot);
		}

		if (curSpot >= 2 && curSpot <= 50000 && !visited[curSpot * 2]) {
			nextSpot = curSpot * 2;
			visited[nextSpot] = visited[curSpot] + 1;
			parent[nextSpot] = curSpot;
			bfsQ.push(nextSpot);
		}


	}


}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	fill(&visited[0], &visited[MAX], 0);

	cin >> n >> k;

	BFS(n);

}