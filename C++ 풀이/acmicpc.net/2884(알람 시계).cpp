#include <iostream>

using namespace std;

int main()
{
	int h, m,alarm;

	cin >> h >> m;
	alarm = 60 * h + m; // alarm은 m 단위로 처리

	if(alarm <45){
		alarm += 60 * 24 - 45;
	}
	else {
		alarm -= 45;
	}

	cout << alarm / 60 << " " << alarm % 60;

	return 0;
}