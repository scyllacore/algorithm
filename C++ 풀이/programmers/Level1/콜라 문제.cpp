#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
	int totalCola = 0;

	for (; n >= a;) {
		int cola = n / a * b;
		totalCola += cola;
		n = cola + n % a;
	}

	return totalCola;

}