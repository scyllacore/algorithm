#include <iostream>
#include <cmath>

using namespace std;

int stats[21][21];
bool check[22];
int N;
int ans = (int)1e9; 

void DFS(int start,int depth)
{
	if (depth == N / 2) 
	{
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i < N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				if (check[i] == true && check[j] == true) start += stats[i][j] + stats[j][i];
				if (check[i] == false && check[j] == false) link += stats[i][j] + stats[j][i];
			}
		}

		int temp = abs(start - link);
		if (ans > temp) ans = temp;

		return;
	}

	for (int i = start; i < N; i++)
	{
		check[i] = true;
		DFS(i + 1, depth + 1);
		check[i] = false;
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> stats[i][j];
		}
	}

	DFS(1, 0);

	cout << ans;
}