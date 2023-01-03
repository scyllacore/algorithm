#include <stdio.h>

int main()
{
	int K;
	int dir[6], len[6];
	int size[6];
	int i;
	int farm = 0;
	int widthMax = 0, heightMax = 0;
	
	scanf("%d", &K);


	for (i = 0; i < 6; ++i)
	{
		scanf("%d %d", &dir[i],&len[i]);
		if (dir[i] == 1 || dir[i] == 2) // 동 , 서 ( 가로 방향 )
		{
			if (len[i] > widthMax)
				widthMax = len[i]; // 가장 큰 가로 길이 
		}
		else // (남 , 북 ( 세로 방향 )
		{
			if (len[i] > heightMax)
				heightMax = len[i]; // 가장큰 세로 길이
		}
	}
	//end input area

	for (i = 0; i < 5; ++i)
	{
		size[i] = len[i] * len[i + 1];
		farm += size[i];
	}
	size[5] = len[0] * len[5];
	farm += size[5];
	farm -= widthMax * heightMax * 2; // (1 + 1 + 1 + 2 + 2 + 2 + 3 + 3 + 4 + 4 + 4) - (1 + 1 + 2 + 2 + 3 + 3 + 4 + 4) = (1 + 2 + 4)
	printf("%d\n", farm * K);
	return 0;
}

//https://dyndy.tistory.com/130