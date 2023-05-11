#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	if (!(n >= m + k - 1 && n <= m * k)) { // ����1. ���� ���� ���� �� ���ҿ� ���� ����. ����2. ��ѱ��� ������ ���� ����
		cout << -1;
		return 0;
	}

	vector<int> sequence(1, 0);

	for (int i = 1; i <= n; i++) {
		sequence.push_back(i);
	}

	vector<int> rangeV;

	//���� �� ���� �κ� ���� ó��. ù��° �׷쿡 �ش��Ѵ�.
	rangeV.push_back(0);
	rangeV.push_back(k);
	n -= k;
	m -= 1;// ���� ������ k���� ù��° �׷� �ݿ�. k���� ���ڿ� �׷� 1���� ���.

	//���� �� ���� �κ� ���� ó��. ù��° �׷��� ó���� �� ���� �׷쿡 �ش��Ѵ�.
	int groupSize = m == 0 ? 0 : n / m; // ���� ���� / ������ �ϴ� �׷� �� = �׷� �ϳ��� �����ϴ� ���� ����
	int r = m == 0 ? 0 : n % m; //���� �Ѱ��� �߰��� �־�����ϴ� �׷��� �� ���

	for (int i = 0; i < m; i++) {
		rangeV.push_back(rangeV.back() + groupSize + (r > 0 ? 1 : 0));
		if (r > 0) {
			r--;
		}
	}

	int start, end = rangeV[0];

	for (int i = 1; i < rangeV.size(); i++) {
		start = end + 1;
		end = rangeV[i];

		for (int j = end; j >= start; j--) {
			cout << sequence[j] << ' ';
		}
	}

	return 0;
}
//https://hongjw1938.tistory.com/191