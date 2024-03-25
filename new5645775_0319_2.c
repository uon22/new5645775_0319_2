#include <stdio.h>
#include <time.h>

long long power_iter(int base, int exponent) { //power_iter함수(반복)를 사용하여 거듭제곱을 계산
    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

long long power_rec(int base, int exponent) { //power_rec함수(재귀)를 사용하여 거듭제곱을 계산
    if (exponent == 0) {
        return 1;
    }
    else {
        return base * power_rec(base, exponent - 1);
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    int base = 13; //밑의 값 저장
    int exponent = 21; //지수의 값을 저장

    // 반복문을 사용한 거듭제곱 계산과 시간 측정
    start = clock(); 
    double result_iter = (double)power_iter(base, exponent);
    end = clock(); 
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Result of %d raised to the power of %d (using iteration): %.0f\n", base, exponent, result_iter);
    printf("Time : %f seconds\n", cpu_time_used);

    // 재귀를 사용한 거듭제곱 계산과 시간 측정
    start = clock();
    double result_rec = (double)power_rec(base, exponent);
    end = clock(); 
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Result of %d raised to the power of %d (using recursion): %.0f\n", base, exponent, result_rec);
    printf("Time : %f seconds\n", cpu_time_used);

    return 0;
}