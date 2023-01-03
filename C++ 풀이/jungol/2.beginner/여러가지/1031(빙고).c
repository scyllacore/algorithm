#include <stdio.h>

int host[5][5];
int user[5][5];

void bingo_in(void);
int check(void);
void search(int spot);
int clear(void);


int main(void)
{

	bingo_in();

	printf("%d", check());
	return 0;
}


void bingo_in(void)
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &host[i][j]);
		}
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			scanf("%d", &user[i][j]);
	}
}

int check(void)
{
	int i, j, cnt = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			search(user[i][j]);
			cnt++;
			if (clear() > 0) {

				return cnt;
			}
		}
	}
}

void search(int spot)//0 집어 넣는 함수
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (host[i][j] == spot)
			{
				host[i][j] = 0;
				return;
			}
		}
	}
}


int clear(void)
{
	int i, j, spot, cnt = 0;

	//세로 확인
	for (i = 0; i < 5; i++)
	{
		spot = 0;
		for (j = 0; j < 5; j++)
		{
			if (host[j][i] != 0)  //동그라미가 연속으로 안나올 경우 멈춤 -> j,i (세로)
				break;
			spot++;//사회자가 부른 숫자를 본인 빙고에 동그라미를 쳤을 때 연속으로 동그라미가 있는 경우를 확인
		}
		if (spot == 5)
		{
			cnt++;
			if (cnt >= 3)
				return cnt;
		}
	}
	//끝

	//가로 확인
	for (i = 0; i < 5; i++)
	{
		spot = 0;
		for (j = 0; j < 5; j++)
		{
			if (host[i][j] != 0) // i,j (가로)
				break;
			spot++;
		}
		if (spot == 5)
		{
			cnt++;
			if (cnt >= 3)
				return cnt;
		}
	}

	//끝

	// 오른쪽 아래 대각선 확인

	spot = 0;
	for (i = 0; i < 5; i++)
	{
		if (host[i][i] != 0)
			break;
		spot++;
	}


	if (spot == 5)
	{
		cnt++;
		if (cnt >= 3)
			return cnt;
	}
	// 끝

	// 오른쪽 위 대각선 확인
	spot = 0;
	for (i = 0; i < 5; i++)
	{
		if (host[4 - i][i] != 0)
			break;
		spot++;
	}

	if (spot == 5)
	{
		cnt++;
		if (cnt >= 3)
			return cnt;
	}
	// 끝

	return 0;
}
