#include <iostream>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,tmp,cnt=0;
	int titleN=665;

	cin >> n;

	for (;++titleN;)
	{
		tmp = titleN;

		for (; tmp > 0;)
		{
			if (tmp %1000 == 666) {
				cnt++;
				break;
			}
			tmp /= 10;
		}

		if (n == cnt)
		{
			cout << titleN;
			return 0;
		}

	}



}

//내가 다시 푼 것