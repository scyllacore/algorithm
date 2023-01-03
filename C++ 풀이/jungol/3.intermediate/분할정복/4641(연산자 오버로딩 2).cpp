#include <iostream>

using namespace std;

struct Rectangle { // typedef 생략가능
	int width, height;

	bool smaller(Rectangle& right) { // 2. (Rectangle left , Rectangle right) -> ( [생략] Rectangle right)
		return width * height < right.width* right.height;
		//  3. left.width * left.height -> width * height
		// a.에 대한 정보는 젤 앞 생략된 매개변수가 받으며 생략된 정보는 표시하지 않는다.
	}

};



int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	Rectangle a, b;

	cin >> a.width >> a.height;
	cin >> b.width >> b.height;
	
	
	// 1. smaller(a,b) -> a.smaller(b)
	if (a.smaller(b)) {
		cout << "a is smaller";
	}
	else
	{
		cout << "b is smaller";

	}

	return 0;

}