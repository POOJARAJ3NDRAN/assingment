#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return (fibonacci(n-1) + fibonacci(n-2)) % 10;
    }
}

int main() {
    int n;
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    int unit_digit = fibonacci(n);
    printf("Unit digit of the %dth Fibonacci number: %d\n", n, unit_digit);

    return 0;
}


