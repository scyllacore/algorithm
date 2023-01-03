#include <iostream>

using namespace std;

int main(void) {

    int N, K, tmpK;
    long long num = 0, numCnt = 9;
    int numLen = 1;
    int res = 0;

    cin >> N >> K;
    tmpK = K;

    for (; tmpK > numCnt * numLen;) {
        num += numCnt;
        tmpK -= numCnt * numLen;
        numCnt *= 10;
        numLen++;
    }

    num = (num + 1) + ((tmpK - 1) / numLen);

    if (num > N)
        res = -1;
    else {
        int tmp = (tmpK - 1) % numLen + 1;

        /*res = num;

        for (int i = 0; i < tmp - 1; i++)
        {
            res = num % 10;
            num /= 10;
        } 제일 앞자리를 뗄 수 없음.*/

        long long ten = 1;

        for (int i = 0; i < numLen - 1; i++) {
            ten *= 10;
        }

        for (int i = 0; i < tmp; i++)
        {
            res = num / ten;
            num %= ten;
            ten /= 10;
        }

    }

    cout << res;
    return 0;
}
