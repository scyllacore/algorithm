#include <cstdio>

using namespace std;

int C[10001] = {0, };
int main () {

    int N, i, j, temp, max;

    scanf("%d", &N);

    max = 0;
    for(i = 0; i < N; i++) {
        scanf("%d", &temp);
        C[temp]++;
        if (temp > max) max = temp;
    }

    for (i = 0; i <= max; i++) {
        for(j = 0; j < C[i]; j++) printf("%d ", i);
    }
    printf("\n");
    return 0;
}