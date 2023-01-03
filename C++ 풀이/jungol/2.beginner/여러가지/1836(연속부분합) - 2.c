#include <stdio.h>

int n[100001];
int hap = 0;
int MAX = -10000;
int N;
int main()
{

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }
    for (int i = 0; i < N; i++) {
        hap = hap + n[i];
        if (MAX < hap)MAX = hap;
        if (hap < 0)hap = 0;
    }
    printf("%d", MAX);
    return 0;
}

/*
#include <stdio.h>  
 
const int LM = 100005;
int N, ans, sum;
 
int main(void) {
    // freopen("input.txt", "r", stdin);
    int i, num;
    scanf("%d", &N);
    for (i = 0; i < N; ++i) {
        scanf("%d", &num);
        if (sum > 0) sum += num;
        else sum = num;
        if (ans < sum) ans = sum;
    }
 
    printf("%d\n", ans);
    return 0;
}
*/