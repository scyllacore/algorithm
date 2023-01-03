#include <iostream>
#define MOD 1234567891

using namespace std;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i;
	cin >> n;

	char* str = new char[n + 1];

	cin >> str;

	unsigned long long hash = 0,powVal=1;

	for (i = 0; i < n; i++) {
		hash += ((str[i] - 96) * powVal),hash %= MOD;
		powVal *= 31 , powVal %= MOD;	
	}

	cout << hash;


}