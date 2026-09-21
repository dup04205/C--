/*
 * 실습 과제명: 계산기 만들기
 * 지역대학: 서울지역대학
 * 학번: 202634-361184
 * 이름: 이상진
 */

/*
 * 연습 1: 계산기 만들기 => 두 수를 입력받아 사칙연산 결과를 출력 
 * 학습 요소: 
 * 핵심: 
 * 확장: 
 */
#include <stdio.h>

int main(void) {
    double num1, num2, result;
    char op;

    printf("=== 간단한 계산기 ===\n");

    while (1) {
        printf("\n수식을 입력하세요 (예: 3 + 5), 종료하려면 q 입력: ");

        if (scanf(" %lf", &num1) != 1) {
            char c;
            scanf(" %c", &c);
            if (c == 'q') break;
            printf("잘못된 입력입니다.\n");
            while (getchar() != '\n');
            continue;
        }

        scanf(" %c %lf", &op, &num2);

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    printf("오류: 0으로 나눌 수 없습니다.\n");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                printf("지원하지 않는 연산자입니다. (+, -, *, / 만 가능)\n");
                continue;
        }

        printf("결과: %.2f %c %.2f = %.2f\n", num1, op, num2, result);
    }

    printf("계산기를 종료합니다.\n");
    return 0;
}
