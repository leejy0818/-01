#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateAverage(int scores[], int size);
int getStudentScore(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);
void deleteStudent(int* scores, int* size, int studentNumber);

int main() {
    int* scores;
    int size = 30;
    int capacity = 30;
    int choice, studentNumber;

    scores = (int*)malloc(capacity * sizeof(int));
    if (!scores) {
        printf("메모리 할당 오류\n");
        return 1;
    }

    srand(time(0));
    for (int i = 0; i < size; i++) {
        scores[i] = rand() % 100 + 1;
    }
    printf("점수(난수) 입력 완료.\n");

    while (1) {
        printf("\n---학생 성적 관리 프로그램---\n");
        printf("1. 학생정보 추가\n");
        printf("2. 학생정보 삭제\n");
        printf("3. 학생정보 검색\n");
        printf("4. 학생정보 출력\n");
        printf("5. 종료\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: { // 추가
            if (capacity == size) {
                capacity += 10;
                int* temp = realloc(scores, capacity * sizeof(int));
                if (!temp) {
                    printf("메모리 재할당 오류\n");
                    free(scores);
                    return 1;
                }
                scores = temp;
            }

            int newScore = rand() % 100 + 1;
            scores[size] = newScore;
            size++;

            printf("새로운 학생 추가: 번호 - %d, 점수 - %d\n", size, newScore);
            break;
        }

        case 2: // 삭제
            printf("삭제할 학생 번호 입력(1 ~ %d): ", size);
            scanf("%d", &studentNumber);
            deleteStudent(scores, &size, studentNumber);
            break;

        case 3: { // 검색
            printf("검색할 학생 번호 입력(1 ~ %d): ", size);
            scanf("%d", &studentNumber);

            int score = getStudentScore(scores, size, studentNumber);
            if (score != -1) {
                printf("%d번 학생 점수: %d\n", studentNumber, score);
            }
            else {
                printf("해당 번호 학생은 없습니다.\n");
            }
            break;
        }

        case 4: { // 출력
            int option;
            printf("출력 옵션 (0: 전체, 1: 평균 이상, 2: 평균 미만): ");
            scanf("%d", &option);

            double average = calculateAverage(scores, size);
            printScore(scores, size, average, option);
            break;
        }

        case 5: // 종료
            free(scores);
            printf("프로그램 종료\n");
            return 0;

        default:
            printf("잘못된 입력입니다.\n");
        }
    }
}

// 평균 계산
double calculateAverage(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return (double)sum / size;
}

// 학생 점수 검색
int getStudentScore(int scores[], int size, int studentNumber) {
    if (studentNumber < 1 || studentNumber > size) {
        return -1;
    }
    return scores[studentNumber - 1];
}

// 학생 삭제
void deleteStudent(int* scores, int* size, int studentNumber) {
    if (studentNumber < 1 || studentNumber > *size) {
        printf("잘못된 번호입니다.\n");
        return;
    }

    for (int i = studentNumber - 1; i < *size - 1; i++) {
        scores[i] = scores[i + 1];
    }

    (*size)--;
    printf("%d번 학생 삭제 완료\n", studentNumber);
}

// 출력
void printScore(int scores[], int size, double average, int option) {
    printf("평균 점수: %.2f\n", average);

    if (option == 0) { // 전체 출력
        for (int i = 0; i < size; i++) {
            printf("학생 번호: %d, 점수: %d\n", i + 1, scores[i]);
        }
    }
    else if (option == 1) { // 평균 이상
        for (int i = 0; i < size; i++) {
            if (scores[i] >= average) {
                printf("학생 번호: %d, 점수: %d\n", i + 1, scores[i]);
            }
        }
    }
    else if (option == 2) { // 평균 미만
        for (int i = 0; i < size; i++) {
            if (scores[i] < average) {
                printf("학생 번호: %d, 점수: %d\n", i + 1, scores[i]);
            }
        }
    }
    else {
        printf("잘못된 옵션입니다.\n");
    }
}