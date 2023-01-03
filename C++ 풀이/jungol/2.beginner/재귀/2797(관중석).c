#include <stdio.h>
#include <math.h>
#include <stdbool.h>
 
bool chk[2001][2001];
int d1, d2, cnt;
int gcd(int a, int b)
{
    return (a >= b) ? ((a%b == 0) ? b : gcd(b, a%b)) : gcd(b, a);
}
int main()
{
    int i, j, k, m, n, o;
    scanf("%d %d", &d1, &d2);
    for (i = d1; i <= d2; i++)
    {
        for (j = i; j >= 1; j--)
        {
            m = i, n = j, o = gcd(m, n);
            m /= o, n /= o;
			if (!chk[m][n]) {
				cnt++;
				chk[m][n] = true;
			}
        }
    }
    printf("%d", cnt);
    return 0;
}
