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
        if (isalpha(str[i])) {  // ������ ��츸 ���ÿ� push
            push(tolower(str[i]));
        }
    }
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {  // ������ ��츸 pop�Ͽ� ��
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
        printf("���ڿ��� �Է��ϼ��� (type 'exit' to quit): ");
        scanf("%[^\n]", str);
        getchar();  // ���� ����
        if (strcmp(str, "exit") == 0) {
            break;
        }
        if (isPalindrome(str)) {
            printf("ȸ���Դϴ�.\n", str);
        }
        else {
            printf("ȸ���� �ƴմϴ�.\n", str);
        }
    }
    return 0;
}
