#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long getOneCount(long long idx, int& n) {
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
    long long res = powVal * quotient;

    if (quotient >= 3) {
        res -= powVal;
    }

    return res + getOneCount(remainder, n);

}

int solution(int n, long long l, long long r) {
    return getOneCount(r, n) - getOneCount(l - 1, n);
}