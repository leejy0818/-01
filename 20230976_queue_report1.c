#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int queue[MAX];
int front = -1;
int rear = -1;

// 큐 초기화
void initQueue() {
    front = -1;
    rear = -1;
}

// 공백 상태 확인
int isEmpty() {
    return (front == -1 || front > rear);
}

// 포화 상태 확인
int isFull() {
    return (rear == MAX - 1);
}

// 삽입
void enqueue(int data) {
    if (isFull()) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }

    if (front == -1)
        front = 0;

    queue[++rear] = data;
    printf("%d 삽입 완료\n", data);
}

// 삭제
int dequeue() {
    if (isEmpty()) {
        printf("큐가 비어 있습니다. 초기화합니다.\n");
        initQueue();  
        return -1;
    }

    int data = queue[front++];

    // 모든 요소 제거 후 초기화
    if (front > rear) {
        initQueue();
    }

    return data;
}

// 큐 출력
void printQueue() {
    if (isEmpty()) {
        printf("큐가 비어 있습니다.\n");
        return;
    }

    printf("현재 큐 상태: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// 메뉴 출력
void menu() {
    printf("\n\n==== 큐 메뉴 ====\n");
    printf("1. 삽입\n");
    printf("2. 삭제\n");
    printf("3. 큐 데이터 출력\n");
    printf("4. 종료\n");
    printf("선택 >> ");
}

// 메인 함수
int main() {
    int choice, value;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 값 입력: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            value = dequeue();
            if (value != -1)
                printf("%d 삭제 완료\n", value);
            break;

        case 3:
            printQueue();
            break;

        case 4:
            printf("프로그램 종료\n");
            exit(0);

        default:
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}