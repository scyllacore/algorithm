#include <iostream>
#include <string>

using namespace std;


int d;
long long x, y;
string quadrantNum;

struct pos {
	long long y, x;
};

pos getCoordinate(string& str, int idx, long long row, long long col, long long size)
{
	if (size == 1) return { row, col };
	else
	{
		if (str[idx] == '1') {
			return getCoordinate(str, idx + 1, row, col + size / 2, size / 2);
		}
		else if (str[idx] == '2') {
			return getCoordinate(str, idx + 1, row, col, size / 2);
		}
		else if (str[idx] == '3') {
			return getCoordinate(str, idx + 1, row + size / 2, col, size / 2);
		}
		else if (str[idx] == '4') {
			return getCoordinate(str, idx + 1, row + size / 2, col + size / 2, size / 2);
		}
	}

}
string search(long long row, long long col, long long y, long long x, long long size)
{
	if (size == 1) return "";

	if (y < row + size / 2 && x >= col + size / 2) return "1" + search(row, col + size / 2, y, x, size / 2);
	else if (y < row + size / 2 && x < col + size / 2) return "2" + search(row, col, y, x, size / 2);
	else if (y >= row + size / 2 && x < col + size / 2) return "3" + search(row + size / 2, col, y, x, size / 2);
	else return "4" + search(row + size / 2, col + size / 2, y, x, size / 2);

}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> d >> quadrantNum;

	cin >> x >> y;

	long long size = (1LL << d); // int형에서 long long 형으로 바꿔주기 위해 LL을 붙임

	pos dPos = getCoordinate(quadrantNum, 0, 0, 0, size);

	dPos.y -= y;
	dPos.x += x;

	if (dPos.y >= 0 && dPos.y < size && dPos.x >= 0 && dPos.x < size)
		cout << search(0, 0, dPos.y, dPos.x, size);
	else cout << "-1" << "\n";

	return 0;
}