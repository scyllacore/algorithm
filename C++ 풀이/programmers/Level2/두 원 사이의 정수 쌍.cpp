#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isInteger(double val) {
	return val == (long long)val;
}

long long solution(int r1, int r2) {
	long long result = 0;
	for (int x = 1; x < r2; x++) {
		double inner = sqrt(pow(r1, 2) - pow(x, 2)); //  x > r1�� ���� �� ����� �ǹ��� ���� chatGpt�� ������ �亯����.
		double outer = sqrt(pow(r2, 2) - pow(x, 2));
		long long cnt = (long long)outer - (long long)inner;
		if (isInteger(inner)) cnt++;
		result += cnt * 4;
	}
	return result + (long long)((r2 - r1) * 4);
}

//https://jjuniyo.tistory.com/6
// chatGpt�� java �ڵ带 c++ �ڵ�� �ٲ���. �� ������..


/*
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isInteger(double val) {
	if(val == -1 ){
		return false;
	}

	return val == (long long)val;
}

long long solution(int r1, int r2) {
	long long result = 0;
	for (int x = 1; x < r2; x++) {
		double inner = x > r1 ? -1 : sqrt(pow(r1, 2) - pow(x, 2)); // chatGpt�� ������ �亯����.
		double outer = sqrt(pow(r2, 2) - pow(x, 2));
		long long cnt = (long long)outer - (long long)(inner == -1 ? 0 : inner);
		if (isInteger(inner)) cnt++;
		result += cnt * 4;
	}
	return result + (long long)((r2 - r1) * 4);
}

�������� �ſ� ������ �ڵ��̴�.
NaN�� �ڵ忡�� � ������ ó���Ǵ��� ��Ȯ�� �� �� �־�� �ۼ��� �� �ִ� �ڵ尡 �ȴ�.
�� �ڵ�� NaN�� ������� �ʰ� ó���غ� �ڵ��̴�. �׷��� ������ �κ��� �߰��Ǿ� �������� ��������.

�켱 NaN�� ���� ����ؾߵ� �� ������ �����صд�.
1. ������ NaN�� �� �ִµ� �� ������ ������ ������ �ؾ��� ��, NaN�� 0���� ó���ȴ�.
2. NaN���� �� ���� ( == ��)�� ���� ��,������ ���� �� �׻� �������� ó���ȴ�.

*/