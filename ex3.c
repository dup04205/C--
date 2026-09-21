/*
 * 실습 과제명: 성적 등급 판정
 * 지역대학: 서울지역대학
 * 학번: 202634-361184
 * 이름: 이상진
 */

/*
 * 연습 3: 성적 등급 찬정 => 점수를 입력 받아 A, B, C, D, F 등급 출력 
 * 학습 요소: 다중 if-else문, 논리적 조건 처리 
 * 핵심: 점수 범위 검증, 합격/불합격 판정 
 * 확장: 성적 판정에 +, - 세부 등급 추가
 */

#include <stdio.h>

int main(void)
{
    int score;
    char grade;         /* 등급 문자 A, B, C, D, F */
    char modifier;      /* 세부 등급 '+', '-', 없으면 공백 */
    int ones;           /* 점수의 일의 자리 */

    printf("=== 성적 등급 판정 ===\n");
    printf("점수를 입력하세요 (0~100): ");

    if (scanf("%d", &score) != 1) {
        printf("점수를 숫자로 입력해야 합니다.\n");
        return 1;
    }

    /* 점수 범위 검증 */
    if (score < 0 || score > 100) {
        printf("오류: 점수는 0에서 100 사이여야 합니다.\n");
        return 1;
    }

    /* 다중 if-else문으로 등급 판정 */
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }

    /* 세부 등급(+, -) 결정 */
    ones = score % 10;

    if (grade == 'F' || score == 100) {
        modifier = ' ';             /* F와 100점은 세부 등급 없음 */
    } else if (ones >= 7) {
        modifier = '+';
    } else if (ones <= 2) {
        modifier = '-';
    } else {
        modifier = ' ';
    }

    printf("\n점수: %d점\n", score);
    printf("등급: %c", grade);
    if (modifier != ' ') {          /* 세부 등급이 있을 때만 이어서 출력 */
        printf("%c", modifier);
    }
    printf("\n");

    /* 합격/불합격 판정: 60점 이상이면 합격 */
    if (score >= 60) {
        printf("결과: 합격\n");
    } else {
        printf("결과: 불합격\n");
    }

    return 0;
}
