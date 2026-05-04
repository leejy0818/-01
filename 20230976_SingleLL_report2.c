#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체
typedef struct Node {
    char name[50];
    char phone[20];
    struct Node* next;
} Node;

// ===================== 연락처 추가 =====================
Node* addContact(Node* head, char* name, char* phone) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    Node* current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
    return head;
}

// ===================== 연락처 검색 =====================
void searchContact(Node* head, char* name) {
    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("이름: %s, 전화번호: %s\n", current->name, current->phone);
            return;
        }
        current = current->next;
    }

    printf("'%s'을(를) 찾을 수 없습니다.\n", name);
}

// ===================== 연락처 삭제 =====================
Node* deleteContact(Node* head, char* name) {
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {

            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("'%s' 삭제 완료\n", name);
            return head;
        }

        prev = current;
        current = current->next;
    }

    printf("'%s'을(를) 찾을 수 없습니다.\n", name);
    return head;
}

// ===================== 전체 출력 =====================
void printContacts(Node* head) {
    Node* current = head;

    if (current == NULL) {
        printf("전화번호부가 비어 있습니다.\n");
        return;
    }

    printf("📞 전화번호부 목록:\n");

    while (current != NULL) {
        printf("이름: %s | 전화번호: %s\n", current->name, current->phone);
        current = current->next;
    }
}

// ===================== 메모리 해제 =====================
void freeList(Node* head) {
    Node* current = head;
    Node* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

// ===================== main =====================
int main() {
    Node* head = NULL;

    // 1. 연락처 추가
    head = addContact(head, "홍길동", "010-1234-5678");
    head = addContact(head, "김철수", "010-2222-3333");
    head = addContact(head, "이영희", "010-9999-8888");

    // 4. 전체 출력
    printContacts(head);

    printf("\n");

    // 2. 검색
    searchContact(head, "김철수");

    printf("\n");

    // 3. 삭제
    head = deleteContact(head, "김철수");

    printf("\n");

    // 다시 출력
    printContacts(head);

    // 메모리 해제
    freeList(head);

    return 0;
}