#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n,cnt=0;

	cin >> n;

	for (; n >= 5;)
	{
		cnt += n/5;
		n /= 5;
	}

	cout << cnt;
	

}



/*
이해용 코드

#include <iostream>

using namespace std;

void Result()
{
	int n;
	scanf("%d", &n);

    // 0팩토리얼 예외 처리
	if(n==0)
	{
		printf("0\n");
		exit(0);
	}

	int count_0=0;
	for(long i=5;i<=n;++i){
		if(i%5==0)count_0++;
		if(i%25==0)count_0++;
		if(i%125==0)count_0++;
	}
	printf("%d\n", count_0);
}

int main()
{
	Result();
	return 0;
}
*/