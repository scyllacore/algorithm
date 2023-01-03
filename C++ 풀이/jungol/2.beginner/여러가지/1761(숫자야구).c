#include <stdio.h>

typedef struct NumberBaseball {
    int numbers[3];
    int strike;
    int ball;
}Baseball;

int main()
{
    int n,num1,num2;
    scanf("%d", &n);
    Baseball* inputNumbers = (Baseball*)malloc(sizeof(Baseball) * n);

    // n번 만큼 케이스를 입력받는다.
    for (int i = 0; i < n; ++i)
    {
        int number;
        scanf("%d %d %d", &number, &inputNumbers[i].strike, &inputNumbers[i].ball);

        // 입력된 숫자를 자리수 별로 나눠서 저장한다.
        inputNumbers[i].numbers[0] = number / 100;
        inputNumbers[i].numbers[1] = (number % 100) / 10;
        inputNumbers[i].numbers[2] = number % 10;
    }

    int testCnt = 0;
    Baseball testNumbers[1000];

    // 테스트 할 숫자를 생성한다.
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            for (int k = 1; k <= 9; ++k)
            {
                // 중복되는 숫자 제거
                if (j == i) break;
                if (k == j || k == i) continue;
                testNumbers[testCnt].numbers[0] = i;
                testNumbers[testCnt].numbers[1] = j;
                testNumbers[testCnt++].numbers[2] = k;
            }
        }
    }

    int possibleCnt = 0;
    // 생성한 숫자와 입력된 숫자를 비교하고 스트라이크, 볼 개수를 비교한다.
    for (int i = 0; i < testCnt; ++i)
    {
        int passCase = 0;
        for (int j = 0; j < n; ++j)
        {
            int testStrike = 0, testBall = 0;
            for (int k = 0; k < 3; ++k)
            {
               // int num1 = (k == 0) ? 1 : 0; 
               // int num2 = (k == 2) ? 1 : 2;
                if (k == 0) { num1 = 1, num2 = 2; }
                else if (k == 1) { num1 = 0, num2 = 2; }
                else { num1 = 0, num2 = 1; }
                // 자리 위치와 값이 같은 경우 Strike 증가
                if (testNumbers[i].numbers[k] == inputNumbers[j].numbers[k])
                {
                    testStrike++;
                }
                // 위치는 다른데 값이 같은 경우 Ball 증가
                else if (testNumbers[i].numbers[k] == inputNumbers[j].numbers[num1]
                    || testNumbers[i].numbers[k] == inputNumbers[j].numbers[num2])
                {
                    testBall++;
                }
            }
            // 테스트한 숫자와 입력한 숫자의 스트라이크 개수가 동일할 때
            // 해당 숫자의 테스트를 통과한다.
            if (inputNumbers[j].strike == testStrike &&
                inputNumbers[j].ball == testBall)
            {
                passCase++;
            }
        }
        // 모든 케이스에 통과한 경우 해당 값이 후보군으로 들어간다.
        if (passCase == n)
        {
            possibleCnt++;
        //    printf("%d%d%d\n", testNumbers[i].numbers[0], testNumbers[i].numbers[1], testNumbers[i].numbers[2]);
        }
    }

    printf("%d\n", possibleCnt);

    free(inputNumbers);
}

//예상 숫자 출력하는 것도