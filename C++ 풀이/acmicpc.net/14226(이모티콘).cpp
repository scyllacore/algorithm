#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 1001

typedef struct emo {
	int screen;
	int clip;
	int second;
};

bool visited[MAX_SIZE][MAX_SIZE] = { {0} };
int s;
queue<emo> emoBFS;


void BFS() {

	int screenN, clipN, time;

	while (!emoBFS.empty()) {
		screenN = emoBFS.front().screen;
		clipN = emoBFS.front().clip;
		time = emoBFS.front().second;
		emoBFS.pop();

		if (screenN == s) {
			cout << time;
			return;
		}

		if (screenN > 0 && !visited[screenN][screenN]) {
			visited[screenN][screenN] = 1;
			emoBFS.push({ screenN, screenN, time + 1 });
		}


		if (clipN > 0 && screenN + clipN < MAX_SIZE) {
			if (!visited[screenN + clipN][clipN]) {
				visited[screenN + clipN][clipN] = 1;
				emoBFS.push({ screenN + clipN, clipN, time + 1 });
			}
		}

		if (screenN > 0 && !visited[screenN - 1][clipN]) {
			visited[screenN - 1][clipN] = 1;
			emoBFS.push({ screenN - 1, clipN, time + 1 });
		}


	}


}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> s;

	visited[1][0] = 1;
	emoBFS.push({ 1,0,0 });
	BFS();

	return 0;

}