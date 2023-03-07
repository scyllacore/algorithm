#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int& a, int& b) {
        return a > b;
    }
};

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>, cmp> pq;

    int sum = 0;

    for (int i = 0; i < enemy.size(); i++) {

        int e = enemy[i];
        pq.push(e);
        // pq���� �������� �� ���忡 ���� ������ ��´�.

        if (pq.size() > k) {
            // ���� �������� �� �� �ִ� ������ �Ѿ�� 
            sum += pq.top(); //���� ���� ���� ���带 �����Ͽ� ���縦 �Ҹ��ϰ�.
            pq.pop();// �� ���带 ������ pq���� ��������.
        }
        // �ᱹ pq�� �������� ������ ���带 �����Ѵ�.

        if (sum > n) { // �̿� ���� sum�� ������ ���� �Ҹ��� ������ ������ ���� �̰��� �Ѿ ��
            return i; // �� �̻� �Ҹ��� �� �ִ� ���簡 ���� �������� ���� ���带 ��ȯ�Ѵ�.
        }
    }

    return enemy.size();
}