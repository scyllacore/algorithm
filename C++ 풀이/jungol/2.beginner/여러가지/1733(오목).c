#include <stdio.h>

void search(int gomoku[][19], int* win, int* win_x, int* win_y); // 이긴돌 찾기 
int explore(int gomoku[][19], int y, int x); // 탐색

int main(void)
{
	//검은색이 이겼을 경우 1, 흰색이 이겼을 경우 2
	int gomoku[19][19];
	int win,win_x, win_y;
	int i, j;

	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 19; j++)
			scanf(" %d", &gomoku[i][j]);
	}

	search(gomoku,&win, &win_x, &win_y);

	printf("%d\n", win);
	if (win != 0)
		printf("%d %d", win_x, win_y);

	return 0;
}

void search(int gomoku[][19],int *win, int *win_x, int *win_y)
{
	int i, j, spot;

	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 19; j++)
		{
			if ((i > 14 && j > 14) || (i < 4 && j > 14)) // 오른쪽 아래 대각선 과 위 대각선 둘다 
				break;

			else if (gomoku[i][j] != 0)
			{
				spot = explore(gomoku,i, j);

				if (spot != 0)
				{
					*win = spot;
					*win_x = i + 1;
					*win_y = j + 1;
					break;
				}
			}
		}
	}
}

int explore(int gomoku[][19] ,int y, int x)
{
	int i, j, spot, cnt = 0;
	spot = gomoku[y][x]; //흰색 혹은 검은색 

	for (i = y + 1; i <= (y + 5) && i < 19; i++) //세로줄 판단 
	{
		if (gomoku[i][x] != spot) //같은 색의 바둑돌이 놓여있지 않을 경우
			break;

		cnt++;
	}
	if (cnt == 4) //5개의 바둑알이 된 경우
	{
		if (gomoku[y - 1][x] != spot) //여섯알이 아닌 경우
			return spot;
	}

	cnt = 0;
	for (j = x + 1; j <= (x + 5) && j < 19; j++) //가로줄 판단
	{
		if (gomoku[y][j] != spot) //같은 색의 바둑돌이 놓여있지 않을 경우
			break;

		cnt++;
	}
	if (cnt == 4) //5개의 바둑알이 된 경우
	{
		if (gomoku[y][x - 1] != spot) //여섯알이 아닌 경우
			return spot;
	}

	cnt = 0;
	for (i = y + 1, j = x + 1; i <= (y + 5) && i < 19 && j < 19; i++, j++) //오른쪽 아래 방향 대각선 판단 
	{
		if (gomoku[i][j] != spot) //같은 색의 바둑돌이 놓여있지 않을 경우
			break;

		cnt++;
	}
	if (cnt == 4) //5개의 바둑알이 된 경우
	{
		if (gomoku[y - 1][x - 1] != spot) //여섯알이 아닌 경우 
			return spot;
	}

	cnt = 0;
	for (i = y - 1, j = x + 1; i >= (y - 5) && i >= 0 && j < 19; i--, j++) //오른쪽 위 방향 대각선 판단 
	{
		if (gomoku[i][j] != spot) //같은 색의 바둑돌이 놓여있지 않을 경우
			break;

		cnt++;
	}
	if (cnt == 4) //5개의 바둑알이 된 경우
	{
		if (gomoku[y + 1][x - 1] != spot) //여섯알이 아닌 경우 
			return spot;
	}

	return 0;
}