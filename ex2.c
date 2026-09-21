/*
 * 실습 과제명: 계산기 만들기
 * 지역대학: 서울지역대학
 * 학번: 202634-361184
 * 이름: 이상진
 */

/*
 * 연습 2: 온도 변화기 => 섭씨를 화씨로, 화씨를 섭씨로 변환 
 * 학습 요소: 조건문(if-else), 수학 공식 적용 
 * 핵심: 섭씨-화씨 변환 공식, 사용자 선택 처리 
 * 확장: 온도 변환기에 캘빈 온도 추가 
 */


#include <stdio.h>

#define ABSOLUTE_ZERO -273.15   /* 절대영도(섭씨) */

int main(void)
{
    int choice;
    double input, celsius, fahrenheit, kelvin;

    printf("=== 온도 변환기 ===\n");
    printf("1. 섭씨 -> 화씨\n");
    printf("2. 화씨 -> 섭씨\n");
    printf("3. 섭씨 -> 켈빈\n");
    printf("4. 켈빈 -> 섭씨\n");
    printf("번호를 선택하세요: ");

    if (scanf("%d", &choice) != 1) {
        printf("번호를 숫자로 입력해야 합니다.\n");
        return 1;
    }

    /* 선택이 올바른 범위인지 먼저 확인한다. */
    if (choice < 1 || choice > 4) {
        printf("오류: 1~4 사이의 번호를 선택해야 합니다.\n");
        return 1;
    }

    printf("온도를 입력하세요: ");
    if (scanf("%lf", &input) != 1) {
        printf("숫자를 입력해야 합니다.\n");
        return 1;
    }

    if (choice == 1) {                  /* 섭씨 -> 화씨 */
        celsius = input;
        if (celsius < ABSOLUTE_ZERO) {
            printf("오류: 섭씨 %.2f도는 절대영도보다 낮습니다.\n", celsius);
            return 1;
        }
        fahrenheit = celsius * 9.0 / 5.0 + 32.0;
        printf("섭씨 %.2f도 = 화씨 %.2f도\n", celsius, fahrenheit);

    } else if (choice == 2) {           /* 화씨 -> 섭씨 */
        fahrenheit = input;
        celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
        if (celsius < ABSOLUTE_ZERO) {
            printf("오류: 화씨 %.2f도는 절대영도보다 낮습니다.\n", fahrenheit);
            return 1;
        }
        printf("화씨 %.2f도 = 섭씨 %.2f도\n", fahrenheit, celsius);

    } else if (choice == 3) {           /* 섭씨 -> 켈빈 */
        celsius = input;
        if (celsius < ABSOLUTE_ZERO) {
            printf("오류: 섭씨 %.2f도는 절대영도보다 낮습니다.\n", celsius);
            return 1;
        }
        kelvin = celsius + 273.15;
        printf("섭씨 %.2f도 = %.2fK\n", celsius, kelvin);

    } else {                            /* 켈빈 -> 섭씨 */
        kelvin = input;
        if (kelvin < 0) {
            printf("오류: 켈빈 온도는 음수가 될 수 없습니다.\n");
            return 1;
        }
        celsius = kelvin - 273.15;
        printf("%.2fK = 섭씨 %.2f도\n", kelvin, celsius);
    }

    return 0;
}
