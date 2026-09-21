/*
 * 실습 과제명: 계산기 만들기
 * 지역대학: 서울지역대학
 * 학번: 202634-361184
 * 이름: 이상진
 */

/*
 * 연습 1: 계산기 만들기 => 두 수를 입력받아 사칙연산 결과를 출력
 * 학습 요소: 기본 자료형(double), scanf/printf, switch문
 * 핵심: 0으로 나누기 예외처리, 연산자 입력 시 공백 처리
 * 확장: 계산기에 제곱근, 제곱 기능 등 추가
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    double num1, num2, result;
    char op;

    printf("=== 계산기 ===\n");

    while (1) 
    {
        printf("\n수식 입력 (예: a + b, a ^ (제곱), a s (제곱근)), 종료하려면 q 입력: ");

        if (scanf(" %lf", &num1) != 1) 
        {
            char c;
            scanf(" %c", &c);
            if (c == 'q') break;
            printf("잘못된 입력입니다.\n");
            while (getchar() != '\n');
            continue;
        }

        scanf(" %c", &op);

        switch (op) {
            case '+':
                scanf(" %lf", &num2);
                result = num1 + num2;
                printf("결과: %.2f %c %.2f = %.2f\n", num1, op, num2, result);
                break;
            case '-':
                scanf(" %lf", &num2);
                result = num1 - num2;
                printf("결과: %.2f %c %.2f = %.2f\n", num1, op, num2, result);
                break;
            case '*':
                scanf(" %lf", &num2);
                result = num1 * num2;
                printf("결과: %.2f %c %.2f = %.2f\n", num1, op, num2, result);
                break;
            case '/':
                scanf(" %lf", &num2);
                if (num2 == 0) {
                    printf("오류: 0으로 나눌 수 없습니다.\n");
                    continue;
                }
                result = num1 / num2;
                printf("결과: %.2f %c %.2f = %.2f\n", num1, op, num2, result);
                break;
            case '^':
                result = num1 * num1;
                printf("결과: %.2f^2 = %.2f\n", num1, result);
                break;
            case 's':
            result = sqrt(num1);
                printf("결과: sqrt(%.2f) = %.2f\n", num1, result);
                break;
                if (num1 < 0) {
                    printf("오류: 음수는 제곱근을 계산할 수 없습니다.\n");
                    continue;
                }
            default:
                printf("지원하지 않는 연산자입니다. (+, -, *, /, ^(제곱), s(제곱근) 만 가능)\n");
                continue;
        }
    }

    printf("계산기를 종료합니다.\n");
    return 0;
}
