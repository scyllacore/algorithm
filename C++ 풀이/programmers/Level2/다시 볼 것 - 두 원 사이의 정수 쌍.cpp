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
		double inner = sqrt(pow(r1, 2) - pow(x, 2)); //  x > r1이 됐을 때 생기는 의문에 대해 chatGpt가 이유를 답변해줌.
		double outer = sqrt(pow(r2, 2) - pow(x, 2));
		long long cnt = (long long)outer - (long long)inner;
		if (isInteger(inner)) cnt++;
		result += cnt * 4;
	}
	return result + (long long)((r2 - r1) * 4);
}

//https://jjuniyo.tistory.com/6
// chatGpt가 java 코드를 c++ 코드로 바꿔줌. 잘 동작함..


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
		double inner = x > r1 ? -1 : sqrt(pow(r1, 2) - pow(x, 2)); // chatGpt가 이유를 답변해줌.
		double outer = sqrt(pow(r2, 2) - pow(x, 2));
		long long cnt = (long long)outer - (long long)(inner == -1 ? 0 : inner);
		if (isInteger(inner)) cnt++;
		result += cnt * 4;
	}
	return result + (long long)((r2 - r1) * 4);
}

생각보다 매우 복잡한 코드이다.
NaN이 코드에서 어떤 식으로 처리되는지 정확히 알 수 있어야 작성할 수 있는 코드가 된다.
위 코드는 NaN을 사용하지 않고 처리해본 코드이다. 그러나 자잘한 부분이 추가되어 가독성이 떨어진다.

우선 NaN에 대해 기억해야될 두 가지만 정리해둔다.
1. 변수에 NaN이 들어가 있는데 이 변수를 가지고 연산을 해야할 때, NaN은 0으로 처리된다.
2. NaN끼리 비교 연산 ( == 등)을 통해 참,거짓을 따질 때 항상 거짓으로 처리된다.

*/