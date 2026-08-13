// Job Sequencing Problem using Greedy Method (With Output)

#include <stdio.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

int main() {
    int n, i, j;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    struct Job job[50];

    printf("Enter Job ID, Deadline, Profit for each job:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &job[i].id, &job[i].deadline, &job[i].profit);
    }

    // Sort jobs by profit (descending)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (job[i].profit < job[j].profit) {
                struct Job temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    // Find maximum deadline
    int maxDeadline = 0;
    for (i = 0; i < n; i++) {
        if (job[i].deadline > maxDeadline)
            maxDeadline = job[i].deadline;
    }

    int slot[50], filled[50];

    for (i = 1; i <= maxDeadline; i++) {
        filled[i] = 0;
        slot[i] = -1;
    }

    int totalProfit = 0;

    // Job scheduling
    for (i = 0; i < n; i++) {
        for (j = job[i].deadline; j >= 1; j--) {
            if (filled[j] == 0) {
                filled[j] = 1;
                slot[j] = job[i].id;
                totalProfit += job[i].profit;
                break;
            }
        }
    }

    printf("\nSelected Job Sequence: ");
    for (i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            printf("J%d ", slot[i]);
    }

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}


// Input:
// Enter number of jobs: 5
// Enter Job ID, Deadline, Profit for each job:
// 1 2 100
// 2 1 19
// 3 2 27
// 4 1 25
// 5 3 15

// Output

// Selected Job Sequence: J3 J1 J5
// Total Profit = 142