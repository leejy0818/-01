#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[101];   // 최대 100자
    char* stack;
    int top = -1;
    int length;

    // 문자열 입력
    printf("문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    // 개행 제거
    input[strcspn(input, "\n")] = '\0';

    length = strlen(input);

    // 스택 메모리 할당
    stack = (char*)malloc(sizeof(char) * length);
    if (stack == NULL) {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    // push
    for (int i = 0; i < length; i++) {
        stack[++top] = input[i];
    }

    // pop 하면서 출력
    printf("거꾸로 출력된 문자열: ");
    while (top >= 0) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    // 메모리 해제
    free(stack);

    return 0;
}