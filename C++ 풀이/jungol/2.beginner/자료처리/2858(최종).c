#include <stdio.h>
#include <string.h>
#define MAX_LEN 100000 + 1

int top = -1;
char stack[MAX_LEN];

int main() {
    int sum = 0;
    char input[MAX_LEN];

    scanf("%s", input);
        
    int inputLen = strlen(input);

    for (int i = 0; i < inputLen; i++) {
        if (input[i] == '(') { stack[++top] = input[i]; }
        else { // ')' // 무조건 막대기 갯수 하나 감소
            stack[--top];
            if (input[i - 1] == '(') sum += top + 1; // () 이든간에
            else sum += 1; // ')' )) 이든간에
        }
    }
    printf("%d", sum);
    return 0;
}

//https://blog.joonas.io/86