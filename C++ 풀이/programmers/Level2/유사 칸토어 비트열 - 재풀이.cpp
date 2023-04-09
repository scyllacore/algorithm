#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long getCountofOne(long long idx) {

	int exp = 0;

	for (; powl(5, exp + 1) <= idx; exp++) {}

	if (exp <= 0) {
		return idx >= 3 ? idx - 1 : idx;
	}

	long long powVal = powl(5, exp);

	int quotient = idx / powVal;
	int remainder = quotient + 1 != 3 ? idx % powVal : 0; // ����1. quotient + 1
	// 0��° ������ ���� ���� ��ȣ�� 1���̴�.

	powVal = powl(4, exp);
	int res = quotient * powVal;

	if (quotient >= 3) {
		res -= powVal;
	}

	return res + getCountofOne(remainder);
}

int solution(int n, long long l, long long r) {
	return getCountofOne(r) - getCountofOne(l - 1);
}