#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getVector(int n,int leng)
{
	int sum = n;
	vector<int> placeVector;

	while (leng!=0)
	{
		int place = pow(10, leng - 1);
		placeVector.push_back(sum/place);
		sum -= (sum / place) * place; // (sum / place * place) 로 씀
		leng--;
	}
	return placeVector;

}

bool IsHanNum(vector<int>& nArr) // 참조 형태로 사용
{
	int i;
	int d = nArr[1] - nArr[0]; //  i=2인 경우를 생각해서 매개변수 d 없애고 추가

	for (i = 2; i < nArr.size(); i++) // i=1 로 씀
	{
		if (nArr[i] - nArr[i - 1] != d) // nArr[i] - d != nArr[i - 1]로 씀
			return false;
	}

	return true;
}


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, cnt=99, i;

	cin >> n;

	if (n < 100)
	{
		cout << n;
		return 0;
	}

	vector<int> nArr;

	for (i = 100; i <= n; i++)
	{
		nArr = getVector(i,3);

		if (IsHanNum(nArr))
		{
			cnt++;
		}

	}

	cout << cnt;

	return 0;



}