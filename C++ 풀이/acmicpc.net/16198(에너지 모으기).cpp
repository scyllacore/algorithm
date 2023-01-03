#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> energyBall;
int ans=0;


void DFS(int ballCnt,int sum) {

	if (ballCnt <= 2) {
		ans = max(sum, ans);
		return;
	}

	int	i,Wx,Wxx;

	for (i = 1; i < ballCnt - 1; i++) {

		Wx = energyBall[i];
		Wxx = energyBall[i - 1] * energyBall[i + 1];

		energyBall.erase(energyBall.begin() + i);
		DFS(ballCnt - 1, sum + Wxx);
		energyBall.insert(energyBall.begin() + i, Wx);
	}

}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, ball;
	cin >> n;
	
	for (i = 0; i < n; i++) {
		cin >> ball;
		energyBall.push_back(ball);
	}

	DFS(n, 0);

	cout << ans;

}