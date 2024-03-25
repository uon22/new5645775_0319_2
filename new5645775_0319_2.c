#include <stdio.h>
#include <time.h>

long long power_iter(int base, int exponent) { //power_iter�Լ�(�ݺ�)�� ����Ͽ� �ŵ������� ���
    long long result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

long long power_rec(int base, int exponent) { //power_rec�Լ�(���)�� ����Ͽ� �ŵ������� ���
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

    int base = 13; //���� �� ����
    int exponent = 21; //������ ���� ����

    // �ݺ����� ����� �ŵ����� ���� �ð� ����
    start = clock(); 
    double result_iter = (double)power_iter(base, exponent);
    end = clock(); 
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Result of %d raised to the power of %d (using iteration): %.0f\n", base, exponent, result_iter);
    printf("Time : %f seconds\n", cpu_time_used);

    // ��͸� ����� �ŵ����� ���� �ð� ����
    start = clock();
    double result_rec = (double)power_rec(base, exponent);
    end = clock(); 
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Result of %d raised to the power of %d (using recursion): %.0f\n", base, exponent, result_rec);
    printf("Time : %f seconds\n", cpu_time_used);

    return 0;
}