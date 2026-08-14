// Matrix chain Multiplication using Dynamic programming 
#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int arr[], int n) {
    int dp[n][n];
    int i, j, k, length, cost;
    
    // Cost is zero when multiplying one matrix
    for (i = 1; i < n; i++)
        dp[i][i] = 0;
    
    // length is chain length
    for (length = 2; length < n; length++) {
        for (i = 1; i < n - length + 1; i++) {
            j = i + length - 1;
            dp[i][j] = INT_MAX;
            
            for (k = i; k <= j - 1; k++) {
                cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    
    return dp[1][n - 1];
}

int main() {
    int arr[] = {3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Matrix dimensions: ");
    for (int i = 0; i < size - 1; i++) {
        printf("M%d(%dx%d) ", i + 1, arr[i], arr[i + 1]);
    }
    printf("<br>");
    
    int result = matrixChainMultiplication(arr, size);
    printf("Minimum number of scalar multiplications required: %d<br>", result);
    
    return 0;
}
// Output 
// Matrix dimensions: M1(3x4) M2(4x5) M3(5x6) 
// Minimum number of scalar multiplications required: 150