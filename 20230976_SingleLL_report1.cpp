#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ===================== 삽입 함수 =====================

// 맨 앞 삽입
Node* insertFirst(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// 맨 뒤 삽입
Node* insertLast(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
    return head;
}

// 특정 값 뒤에 삽입
void insertAfterValue(Node* head, int targetValue, int newData) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == targetValue) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }

    printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
}

// ===================== 출력 함수 (과제 1-4) =====================

void printList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// ===================== 탐색 함수 (과제 1-5) =====================

// 위치 반환
int searchValue1(Node* head, int val) {
    int position = 1;
    Node* current = head;

    while (current != NULL) {
        if (current->data == val)
            return position;

        current = current->next;
        position++;
    }

    return -1;
}

// 앞/뒤 노드 출력
void searchValue2(Node* head, int val) {
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == val) {

            if (prev != NULL)
                printf("이전 노드 값: %d\n", prev->data);
            else
                printf("이전 노드 없음 (첫 번째 노드)\n");

            if (current->next != NULL)
                printf("다음 노드 값: %d\n", current->next->data);
            else
                printf("다음 노드 없음 (마지막 노드)\n");

            return;
        }

        prev = current;
        current = current->next;
    }

    printf("값 %d를 찾을 수 없습니다.\n", val);
}

// ===================== 메모리 해제 함수 =====================

void freeList(Node* head) {
    Node* current = head;
    Node* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    printf("리스트 메모리 해제 완료\n");
}

// ===================== main =====================

int main() {
    Node* head = NULL;

    // 노드 삽입
    head = insertFirst(head, 30);
    head = insertFirst(head, 20);
    head = insertFirst(head, 10);

    head = insertLast(head, 70);
    head = insertLast(head, 80);
    head = insertLast(head, 90);

    insertAfterValue(head, 30, 40);
    insertAfterValue(head, 40, 50);
    insertAfterValue(head, 50, 60);

    // 리스트 출력
    printf("현재 리스트: ");
    printList(head);

    // 탐색 테스트
    int val = 30;
    int pos = searchValue1(head, val);
    printf("%d의 위치는 %d번째\n", val, pos);

    searchValue2(head, val);

    // 메모리 해제
    freeList(head);

    return 0;
}