#include <stdio.h>
#include <string.h>
#define MAX_LEN 100000 + 1



int main() {
    int newBar = 0;
    int depth = 0;
    int inputLen = 0;
    int answer = 0;

    char input[MAX_LEN];

    scanf("%s", input);

    inputLen = strlen(input);
    // 문자열의 끝까지 탐색해본다. 
    for (int idx = 1; idx < inputLen; idx++) {
        //    ( 를 만나면 depth 는 + 1,  ) 를 만나면 depth 는 -1
        if (input[idx] == '(' ) depth++;
        else depth--;

        //    만약 (( 구조이면 new_bar 에 하나 추가해준다.
        if (input[idx - 1] == '(' && input[idx] == '(') newBar++;

        //    만약 ()를 만나면 현재 depth 만큼 정답에 추가하고
        //    new_bar를 0으로 만든다.  
        if (input[idx - 1] == '(' && input[idx] == ')') {
            answer += newBar + depth + 1;
            newBar = 0;
        //    printf("%d\n", answer);
        }

    }

    printf("%d", answer);

    return 0;
}