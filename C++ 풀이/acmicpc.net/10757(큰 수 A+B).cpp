#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char num1[100001], num2[100001], result[100001] = {0};


	cin >> num1 >> num2;

	int i, num1_idx = strlen(num1), num2_idx = strlen(num2);
	int len = num1_idx > num2_idx ? num1_idx : num2_idx;

	for (i=len; num1_idx > 0 || num2_idx > 0; i--)
	{
		int n1=0, n2=0;

		if (num1_idx > 0)
			n1 = num1[--num1_idx] - '0';
		if (num2_idx > 0)
			n2 = num2[--num2_idx] - '0';

		int sum = result[i] + n1 + n2; // 미리 계산 할 것 , int sum = n1 + n2 -> X

		result[i] = sum % 10;
		//result[i] += (sum+result[i]) % 10; -> X 

		result[i - 1] += sum / 10; // 자릿수 누적
		//result[i - 1] += ( result[i] + sum )/ 10; -> 전 코드의 바뀐 값에 영향을 받음으로 X
	}


	if (result[0] == 0) {

		for (i = 0; i <= len; i++)
		{
			result[i] = result[i + 1];
			result[i] += '0';
		}
		result[len] = '\0';

	}
	else
	{
		for (i = 0; i <= len; i++)
		{
			result[i] += '0';
		}
	}
	


	cout << result;


}