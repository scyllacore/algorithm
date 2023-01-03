#include <iostream>

using namespace std;

struct Rectangle { // typedef 생략가능
	int width, height;

};

bool smaller(Rectangle& left, Rectangle& right) {
	return left.width * left.height < right.width* right.height;
}


int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	Rectangle a, b;

	cin >> a.width >> a.height;
	cin >> b.width >> b.height;

	if (smaller(a, b)) {
		cout << "a is smaller";
	}
	else
	{
		cout << "b is smaller";

	}
	
	return 0;
	
}