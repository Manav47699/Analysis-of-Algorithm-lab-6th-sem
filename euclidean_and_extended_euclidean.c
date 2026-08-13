// Write a program to implement euclidean and extended euclidean algorithm 
#include <stdio.h>

// Euclidean Algorithm to find GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Extended Euclidean Algorithm
int extendedGCD(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Euclidean Algorithm
    int result = gcd(a, b);
    printf("GCD using Euclidean Algorithm: %d\n", result);

    // Extended Euclidean Algorithm
    int gcd_ext = extendedGCD(a, b, &x, &y);
    printf("GCD using Extended Euclidean Algorithm: %d\n", gcd_ext);
    printf("Coefficients x and y: %d %d\n", x, y);
    printf("Verification: %d*(%d) + %d*(%d) = %d\n", a, x, b, y, a*x + b*y);

    return 0;
}


// output:

// Enter two numbers: 3
// 4
// GCD using Euclidean Algorithm: 1
// GCD using Extended Euclidean Algorithm: 1
// Coefficients x and y: -1 1
// Verification: 3*(-1) + 4*(1) = 1