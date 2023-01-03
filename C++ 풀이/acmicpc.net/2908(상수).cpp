#include <iostream>

using namespace std;


int strcmp_str(const char* s1, const char* s2) {
	int ret = -1,cnt=3;
	while (!(ret = *(unsigned char*)s1 - *(unsigned char*)s2) && cnt--)
		--s1, --s2;

	if (ret < 0)
		ret = 1;
	else if (ret > 0)
		ret = 0;

	return ret;
}


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char str[2][4];
	int i,flag=-1;

	cin >> str[0] >> str[1];


	flag=strcmp_str(&str[0][2], &str[1][2]);

	if (flag == -1) {
		cout << "error";
		return 0;
	}


	for (i = 2; i >= 0; i--)
	{
		cout << str[flag][i];
	}

	return 0;

}