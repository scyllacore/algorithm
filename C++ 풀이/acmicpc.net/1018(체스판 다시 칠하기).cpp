#include <iostream>

using namespace std;

char chess1[8][8], chess2[8][8]; // W,B
char chessBoard[50][50] = { 0 };
int minValue = 9999;

void chessReset() {
	int i, j;
	int cnt;


	for (i = 0; i < 8; i++)
	{

		cnt = (i % 2 == 0) ? 0 : 1;


		for (j = 0; j < 4; j++)
		{
			chess1[i][cnt + 2 * j] = 'W';  //white start
			chess2[i][cnt + 2 * j] = 'B'; //black start
		}
	}

	for (i = 0; i < 8; i++)
	{
		cnt = (i % 2 == 1) ? 0 : 1;

		for (j = 0; j < 4; j++)
		{
			chess1[i][cnt + 2 * j] = 'B';  //white start
			chess2[i][cnt + 2 * j] = 'W'; //black start
		}
	}


	/*for (i = 0; i < 8; i++)
	{

		for (j = 0; j < 8; j++)
		{
			cout << chess1[i][j];
		}
		cout << '\n';
	}

	cout << '\n';
	for (i = 0; i < 8; i++)
	{

		for (j = 0; j < 8; j++)
		{
			cout << chess2[i][j];
		}
		cout << '\n';
	}*/



}

int chessCheck(int x, int y)
{
	int cntWs = 0, cntBs = 0;
	int i, j;

	for (i = x; i < x + 8; i++)
	{
		for (j = y; j < y + 8; j++)
		{
			if (chess1[i - x][j - y] != chessBoard[i][j])
			{
				cntWs++;
			}
			if (chess2[i - x][j - y] != chessBoard[i][j])
			{
				cntBs++;
			}


		}
	}

	if (cntWs < cntBs)
	{
		return cntWs;
	}
	else
	{
		return cntBs;
	}


}



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	chessReset();


	int m, n;
	int i, j;
	int cnt;

	cin >> m >> n;

	for (i = 0; i < m; i++)
	{
		cin >> chessBoard[i];
	}


	for (i = 0; i <= m - 8; i++)
	{
		for (j = 0; j <= n - 8; j++)
		{
			cnt = chessCheck(i, j);

			if (cnt < minValue)
			{
				minValue = cnt;
			}
		}
	}


	cout << minValue;


}