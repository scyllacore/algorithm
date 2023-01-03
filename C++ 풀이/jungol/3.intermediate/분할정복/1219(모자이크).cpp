#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n' 
typedef long long ll;

typedef pair<int, int> pii; vector<int> arr; int need(int width)
{
	// 색종이 폭이 width일때, 다 덮기 위해 필요한 종이의 수 
	int prev = -1; int ret = 0; for (int pos : arr) {
		if (prev == -1) { //처음 종이를 놓는 경우, [prev, prev+width) 까지 커버 가능 
			prev = pos; ret++;
		}
		else if (prev + width <= pos)
		{
			prev = pos; ret++;
		}
	} return ret;


}


int main() {
	int row, col, num_paper, num_hole;
	int max_height = 0;
	cin >> row >> col >> num_paper >> num_hole;
	for (int i = 0; i < num_hole; i++)
	{
		int x, y; //행, 열
		cin >> x >> y;
		max_height = max(max_height, x);
		arr.push_back(y);
	}
	sort(arr.begin(), arr.end());

	int l = max_height; int r = 1000000; //range = [l, r] 
	while (l < r) {
		int m = (l + r) / 2;
		if (need(m) <= num_paper) { //가능한 경우
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	cout << l << endl;
	return 0;
}

