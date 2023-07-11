#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SIZE (int)1e4
#define INF (int)1e5

struct edge {
	int start;
	int len;
};

int spotLen[SIZE + 1];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	fill(&spotLen[0], &spotLen[SIZE + 1], INF);

	int n, d;
	cin >> n >> d;

	vector<vector<edge>> graph(SIZE + 1);

	int s, e, l;
	for (int i = 0; i < n; i++) {
		cin >> s >> e >> l;
		graph[e].push_back({ s,l });
	}

	spotLen[0] = 0;

	for (int i = 1; i <= d; i++) {
		spotLen[i] = spotLen[i - 1] + 1; // �̰� ������ ��.

		for (int j = 0; j < graph[i].size(); j++) {
			int startSpot = graph[i][j].start;
			int len = graph[i][j].len;
			spotLen[i] = min(spotLen[startSpot] + len, spotLen[i]);
		}
	}

	cout << spotLen[d] << '\n';

	for (int i = 0; i <= d; i++) {
		cout << spotLen[i] << ' ';
	}
	return 0;
}

//c++ algorithm ����� min �Լ��� ���� ���� ������ ���Ϸ��� ({a,b,c}) �̷� ������ �߰�ȣ�� �����ָ� �ȴ�!