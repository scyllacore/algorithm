#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int alpha[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
	char dial[16];  

	cin >> dial;

	int i,timeCnt=0;

	for (i = 0; dial[i] != '\0'; i++)
	{
		timeCnt += alpha[dial[i] - 65] + 1; // alpha[dial[i] - 65] : 해당 숫자까지 갈 때 걸리는 시간 ,  + 1 : 원 위치로 돌아갈 때 걸리는 시간 -> 다이얼 전화기 동작 방식을 알아야한다.
	}
	
	cout << timeCnt;

	return 0;

}