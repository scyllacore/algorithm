#include <stdio.h>



int N;



void move(int from, int to) 

{

	printf("%d -> %d\n", from, to);

}



void hanoi(int n, int from, int by, int to)

{

	if (n == 1) {

		printf("%d : ", n);

		move(from, to);

	}

	else {

		hanoi(n - 1, from, to, by); // 중간 전까지 모든 원판은 시작점에서 목적지로 향한다

		printf("%d : ", n);

		move(from, to);

		hanoi(n - 1, by, from, to); // 중간 후의 모든 원판도 시작점에서 목적지로 향한다

	}

}



int main()

{

	scanf("%d", &N);

	hanoi(N, 1, 2, 3);

}

//https://shoark7.github.io/programming/algorithm/tower-of-hanoi
//http://swworld.woobi.co.kr/hanoi_tower.htm
// 막대의 순서를 바꿔서 이해 시켜야함