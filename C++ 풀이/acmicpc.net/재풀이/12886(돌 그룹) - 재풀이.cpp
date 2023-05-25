#include <iostream>
#include <queue>

using namespace std;

#define MAX 1501 // ��� �׽�Ʈ ���̽��� ���� ǥ���Ǵ� �ִ� �� ������ 1500�� ���� �� ����.
// 500 499 498 -> �̰� �� �׷��� ���� �� �ִ� �ִ� �� �������ٵ� �̸� bfs�� ������ �ִ� 1497�� ������ �ȴ�.
// �׷��� ���Ǹ� ���� 1501�� �����ص� ��.

struct stone {
	int a, b, c;
};

struct newPair {
	int x, y;
};

bool visited[MAX][MAX] = { {0} };

newPair getNewPair(int x, int y) {
	if (x < y) {
		return { 2 * x , y - x };
	}

	return { 2 * y , x - y };
}

bool bfs(stone start) {

	if ((start.a + start.b + start.c) % 3) {
		return 0;
	}

	queue<stone> bfsQ;
	bfsQ.push(start);
	visited[start.a][start.b] = visited[start.b][start.a] = 1;

	for (; !bfsQ.empty();) {
		int a = bfsQ.front().a;
		int b = bfsQ.front().b;
		int c = bfsQ.front().c;
		bfsQ.pop();

		if (a == b && b == c) {
			return 1;
		}

		int newA, newB, newC;

		if (a != b) {
			newPair newAB = getNewPair(a, b);
			newA = newAB.x;
			newB = newAB.y;

			if (!visited[newA][newB]) {
				visited[newA][newB] = visited[newB][newA] = 1;
				bfsQ.push({ newA,newB,c });
			}
		}

		if (a != c) {
			newPair newAC = getNewPair(a, c);
			newA = newAC.x;
			newC = newAC.y;

			if (!visited[newA][newC]) {
				visited[newA][newC] = visited[newC][newA] = 1;
				bfsQ.push({ newA,b,newC });
			}
		}


		if (b != c) {
			newPair newBC = getNewPair(b, c);
			newB = newBC.x;
			newC = newBC.y;

			if (!visited[newB][newC]) {
				visited[newB][newC] = visited[newC][newB] = 1;
				bfsQ.push({ a,newB,newC });
			}
		}

	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	cout << bfs({ a,b,c });
	return 0;
}