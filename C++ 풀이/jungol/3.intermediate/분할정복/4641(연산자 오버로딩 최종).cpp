#include <iostream>

using namespace std;

struct Rectangle { // typedef 생략가능
	int width, height;

	bool operator<(Rectangle& right) { //  오버로딩 2번에서 smaller만 operator<로 바꿈
		return width * height < right.width* right.height;

	}

};



int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	Rectangle a, b;

	cin >> a.width >> a.height;
	cin >> b.width >> b.height;


	if (a < b) {
		cout << "a is smaller";
	}
	else
	{
		cout << "b is smaller";

	}

	return 0;

}