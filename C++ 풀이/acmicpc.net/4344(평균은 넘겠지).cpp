#include <iostream>

using namespace std;

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cout<<fixed;
	cout.precision(3);


	int num,sbjNum,i,j;
	double sum = 0, avg, cnt = 0;


	cin >> num;


	for (i = 0; i < num; i++)
	{
		cin >> sbjNum;
		int* arr = new int[sbjNum];

		for (j = 0; j < sbjNum; j++)
		{
			cin >> arr[j];
			sum += arr[j];
		}

		avg = sum / sbjNum;
		
		for (j = 0; j < sbjNum; j++)
		{
			if (arr[j] > avg)
				cnt++;
		}

		cout << cnt / sbjNum * 100 << "%\n";

	
		delete[] arr;
		sum = 0, cnt = 0;
	}



	return 0;

}