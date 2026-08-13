// Chinese Remainder theorem
#include <stdio.h>

// Function to find modular inverse using brute force
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 1;
}

int main() {
    int n, i;
    
    printf("Enter number of equations: ");
    scanf("%d", &n);

    int num[n], rem[n];
    int prod = 1;
    int result = 0;

    printf("Enter moduli (n1 n2 ... nn):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        prod *= num[i];
    }

    printf("Enter remainders (r1 r2 ... rn):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &rem[i]);
    }

    for (i = 0; i < n; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    printf("The solution is x = %d\n", result % prod);

    return 0;
}

// Input:
// Enter number of equations: 3
// Enter moduli: 3 4 5
// Enter remainders: 2 3 1
// Output
// The solution is x= 11