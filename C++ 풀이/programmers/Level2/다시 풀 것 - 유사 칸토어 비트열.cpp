#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long countNumberOne(long long idx) {

    long long result = 0;
    int exp = 0; // exp�� ��Ģ���� ������ ������ �� ���ȴ�. ��ġ�� �ƴϴ�. �� �̸� ���� ��� n���� ��Ʈ���� ����� �´��� �� �� �ִ�.

    for (; (long long)(pow(5, exp + 1)) < idx; exp++) {} // idx ��ġ�� �̿��� ��Ģ���� ������ ã�´�. �̸� ���� exp+1�� ���༭ idx�� ������ ����� ���� ��Ģ ������ ã�´�.

    if (exp == 0) { // ��Ģ ������ ���� ����̴�. ������ �κи� ���Ҵ�.
        return idx < 3 ? idx : idx - 1;
    }

    long long quotient = idx / (long long)pow(5, exp);// n�� exp+1�̴�. exp(n-1)�� ���� �̿��� n���¿��� ó������ idx���� ��Ģ������ 1�� ������ ������, 1�� ��� ������ ��ġ�Ǿ��ִ��� Ȯ���� �� �ִ�.  
    long long remainder = (quotient + 1 != 3 ? idx % (long long)pow(5, exp) : 0); // ��Ģ������ ���� �����̴�. �ٽ� ��͸� ���� �� ����Ѵ�.

    if (quotient >= 3) {
        result += (quotient - 1) * (long long)pow(4, exp); // ���� �߰��� 0�� ������ �ִ� ���� 0�� �����ϰ� 1�� ������ ����.
    }
    else {
        result += (long long)(quotient * pow(4, exp));
    }

    return result + countNumberOne(remainder);

}

int solution(int n, long long l, long long r) {
    return countNumberOne(r) - countNumberOne(l - 1);
}

//https://nxnaxx.github.io/algorithm/%EC%9C%A0%EC%82%AC-%EC%B9%B8%ED%86%A0%EC%96%B4-%EB%B9%84%ED%8A%B8%EC%97%B4/algorithm-solution/

//���� ����