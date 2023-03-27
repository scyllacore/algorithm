#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;

    for (; storey > 0;) {
        int cur = storey % 10;
        int next = (storey / 10) % 10;

        if (cur > 5) {
            answer += 10 - cur;
            storey += 10;
        }
        else if (cur == 5) {
            answer += 5;
            storey += (next >= 5 ? 5 : 0); // > -> >= 4�� 5��, 5�� 6���� ����� ������ �ǹ��Ѵ�. 4�� 5�� ���� ���� ��� �������� ���� ��� ������ 5�� 6�� �Ǵ� ���� 10���� ���� ���� �� �̵��̴� �̿� ���� 5�� ���� ���� 10���� ���� �����ν� �̵��� ���� �ؾ��Ѵ�.
        }
        else {
            answer += cur;
        }

        storey /= 10;

    }

    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

int solution(int storey) {

    int answer = 0;

    for (; storey > 0;) {

        int cur = storey % 10;
        int next = (storey / 10) % 10;

        if (cur > 5) { // 1. ���� �ڸ��� 5���� Ŭ ���, 10���� �������� �� �����.
            answer += 10 - cur;
            storey += 10;
        }
        else if (cur == 5) { //2. ���� 5�� ��� ���� �ڸ��� ���� ���� 0,10 ���� �ƹ����� �����ص� ��� ������, 5�� ���Ͽ� ���� �ڸ��� 6 �̻��� ���� ���� ���� �ڸ��� 10���� �������� �� �� ������ ������ �� ����. �̸� �����Ͽ� ��ġ ����.
            answer += 5;
            storey += next >= 5 ? 5 : 0; // ���� �ڸ��� next�� cur�� � �������� ��ġ�� �����ߴ����� ���� ������ ������ �� �ִ� ��ġ�� �������� �̸� �����صξ���Ѵ�. ���� �ڸ� 5�� 5�� ���ϴ� ���� ������ �ʴ� ��츦 ���� ���� �ڸ��� �ִ��� �̵� �� �� �ִ� ��츦 ������ �Ѵ�.
        }
        else { // 3. ���� �ڸ��� 5���� ���� ���, 0���� ���� ���� �� �����.
            answer += cur;
        }

        storey /= 10;
    }

    return answer;

}

*/