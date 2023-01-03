#include <iostream>

using namespace std;

unsigned long long binarySearch(unsigned long long n) {
	unsigned long long low = 1, high = n/2, mid = 0;;
	unsigned long long target;

	if (n == 1)
		return 1;

	while (low <= high) {
		mid = (low + high) / 2;

		target = mid * mid;

		if (target == n)
			return mid;
		else if (target > n || target <= 0)
			 high = mid - 1;
		else if (target < n)
			low = mid + 1;
		else
			break;
		
	}

	if (n > mid * mid) mid++;

	return mid-1;

}

int main()
{
	unsigned long long n;
	cin >> n ;

	cout << binarySearch(n);

	return 0;
}