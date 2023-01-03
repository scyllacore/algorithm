#include <iostream>
#include <algorithm>

using namespace std;

typedef struct position {
	int x;
	int y;
}Position;

bool cmp(const Position& pos1, const Position& pos2)
{
	if (pos1.y == pos2.y)
		return pos1.x < pos2.x;
	else {
		return pos1.y < pos2.y;
	}

}

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int n,i;
	cin >> n;

	Position* pos = new Position[n];

	for (i = 0; i < n; i++)
	{
		cin >> pos[i].x >> pos[i].y;
	}

	sort(pos, pos + n, cmp);


	for (i = 0; i < n; i++)
	{
		cout << pos[i].x << ' ' << pos[i].y << '\n';
	}



}