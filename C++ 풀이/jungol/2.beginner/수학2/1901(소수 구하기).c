#include <stdio.h>
#include <stdbool.h>

bool isPrime(int N) {
    if (N < 2) // 1은 소수 X
        return false;

    for (int i = 2; i <= N / i; ++i) {
        if (N % i == 0)
            return false;
    }
    return true;
}


void output(int N) {
    if (isPrime(N)) { // N 자체가 소수인 경우
        printf("%d\n", N);
        return;
    }

    int flag = 0;
    for (int i = 1; flag<1; i++) { // !flag
        // N으로 부터 i 크기 차이나는 숫자가 소수인지 확인
        if (isPrime(N - i)) {
            printf("%d ", N - i);
            flag++;
        }
        if (isPrime(N + i)) {
            printf("%d ", N + i);
            flag++;
        }
    }
    printf("\n");
}

int main() {
    // freopen("input.txt", "r", stdin);
    int tc, N;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &N);
        output(N);
    }
}



//입력한 숫자에 대해 가장 가깝게 나올 수 있는 소수 구하기
// 똑같이 가까운게 있으면 둘다 출력