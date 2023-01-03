#include <stdio.h>
int min(int A, int B) { return A < B ? A : B; }
char ball[500005];
int N, ans, redBallCnt, blueBallCnt;

int main() {
    int i, cnt = 0;
    scanf("%d %s", &N, ball);

    // 1) 각 색깔의 개수를 센다.
    //    작은 값이 답 후보이다. (그 색의 모든 볼을 다 옮기는 경우)
    for (i = 0; i < N; i++) {
        if (ball[i] == 'R') redBallCnt++;
        else blueBallCnt++;
    }
    ans = min(redBallCnt, blueBallCnt);

    // 2) 가장 왼쪽부터 연속된 색깔의 개수를 세어서 해당색의 전체개수에서 뺀다.
    //    기존의 답보다 작으면 갱신한다. (나머지 볼을 왼쪽으로 옮기는 경우)
    for (i = 0; i < N; i++) {
        if (ball[i] != ball[0]) break;
        cnt++;
    }
    if (ball[0] == 'R') ans = min(ans, redBallCnt - cnt);
    else ans = min(ans, blueBallCnt - cnt);

    // 3) 가장 오른쪽부터 연속된 색깔의 개수를 세어서 해당색의 전체개수에서 뺀다.
    //    기존의 답보다 작으면 갱신한다. (나머지 볼을 오른쪽으로 옮기는 경우)
    cnt = 0;
    for (i = N - 1; i >= 0; i--) {
        if (ball[i] != ball[N - 1]) break;
        cnt++;
    }

    if (ball[N - 1] == 'R') ans = min(ans, redBallCnt - cnt);
    else ans = min(ans, blueBallCnt - cnt);

    printf("%d\n", ans);
}
