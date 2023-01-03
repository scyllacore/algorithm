#include <iostream>

using namespace std;

int coinDp[10001] = { 0 };
int coinVal[101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	int i, j;
	for (i = 1; i <= n; i++) {
		cin >> coinVal[i];
	}

	coinDp[0] = 1; // 자기 자신을 반영하기 위해 저장해둔 경우의 수
	/*ex ) 3원 짜리를 이용해서 3원을 만드는 경우를 보자.
	DP[3] = DP[3] + DP[3 - 3]이 될 것이고, 즉, DP[3] += DP[0]이 된다는 것이다.
	이 때, DP[0]이 만약 0이라면 ? ? DP[3] = 0이 될 것이다.
	3원짜리를 이용해서 만들 수 있는 경우가 한 가지 존재하는데도 불구하고, 계산이 제대로 되지 않는다는 것이다.*/


	for (i = 1; i <= n; i++) {
		for (j = coinVal[i]; j <= k; j++) {
			coinDp[j] += coinDp[j - coinVal[i]];
		}
	}

	cout << coinDp[k];


	// 1.
	//	for (i = 1; i <= k; i++) {
	//		for (j = 0; j <= n; j++) {
	//			if (i - coinVal[j] >= 0) {
	//				coinDp[i] += coinDp[i - coinVal[j]];
	//			}
	//		}
	//	}
	// 
	// 2.
	// 
	//	for (i = 0; i < n; i++) {
	//		cin >> coinVal[i];
	//		coinCombi[coinVal[i]] = 1;
	//	}
	//
	//	for (i = 2; i <= k; i++) {
	//		for (j = 0; j < n; j++) {
	//			if (i - coinVal[j] > 0) { //  && coinCombi[i - coinVal[j]] > 0
	//				coinCombi[i] += coinCombi[j];
	//			}
	//			else if (i - coinVal[j] <= 0) break;
	//		}
	//	}
	// "1,2" 는 순열로 처리되어 안됨.
	// 
	//#include <cstdio>
	//	
	//		int main() {
	//		int n, k;
	//		int c[101];
	//		int d[101][10001] = { 0, };
	//		
	//			scanf("%d %d", &n, &k);
	//		for (int i = 1; i <= n; i++) {
	//			scanf("%d", &c[i]);
	//		}
	//
	//		for (int i = 1; i <= n; i++) {
	//			d[i][0] = 1;
	//		}
	//		
	//			for (int i = 1; i <= n; i++) {
	//				for (int j = 1; j <= k; j++) {
	//					if (j >= c[i]) {
	//						d[i][j] = d[i - 1][j] + d[i][j - c[i]];
	//					}
	//					else {
	//						d[i][j] = d[i - 1][j];
	//					}
	//				}
	//			}
	//		
	//			printf("%d\n", d[n][k]);
	//		
	//			return 0;
	//	}
	// 가능은 하나 메모리 초과



}


//https://lotuslee.tistory.com/113?category=848933