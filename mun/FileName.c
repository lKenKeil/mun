#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

char stack[MAX_LENGTH];
int top = -1;

void push(char c) {
    if (top == MAX_LENGTH - 1) {
        printf("Stack full\n");
    }
    else {
        top++;
        stack[top] = c;
    }
}

char pop() {
    char c = '\0';
    if (top == -1) {
        printf("Stack empty\n");
    }
    else {
        c = stack[top];
        top--;
    }
    return c;
}

int isPalindrome(char str[]) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {  // 문자인 경우만 스택에 push
            push(tolower(str[i]));
        }
    }
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {  // 문자인 경우만 pop하여 비교
            if (tolower(str[i]) != pop()) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char str[MAX_LENGTH];
    while (1) {
        printf("문자열을 입력하세요 (type 'exit' to quit): ");
        scanf("%[^\n]", str);
        getchar();  // 버퍼 비우기
        if (strcmp(str, "exit") == 0) {
            break;
        }
        if (isPalindrome(str)) {
            printf("회문입니다.\n", str);
        }
        else {
            printf("회문이 아닙니다.\n", str);
        }
    }
    return 0;
}
