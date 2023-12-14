#include <stdio.h>
#include <stdlib.h>

void sortProcesses(int arr[], int n, int order[]) {
    int pos, temp;
    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[pos])
                pos = j;
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
        temp = order[i];
        order[i] = order[pos];
        order[pos] = temp;
    }
}

int main(void) {
    int n = 0;

    printf("Enter the number of processes: ");
    scanf_s("%d", &n);
    printf("\n");
    if (n <= 0) {
        printf("Invalid number of processes. Exiting.\n");
        return 1;
    }

    // Declare arrays with dynamic memory allocation
    int* bt = malloc(n * sizeof(int));
    int* bt1 = malloc(n * sizeof(int));
    int* p = malloc(n * sizeof(int));
    int* wt = malloc(n * sizeof(int));
    int* pr = malloc(n * sizeof(int));
    int* at = malloc(n * sizeof(int));

    if (bt == NULL || bt1 == NULL || p == NULL || wt == NULL || pr == NULL || at == NULL) {
        printf("Memory allocation failed. Exiting.\n");

        // Release allocated memory before exiting
        free(bt);
        free(bt1);
        free(p);
        free(wt);
        free(pr);
        free(at);

        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter CPU Time for P%d: ", i + 1);
        scanf_s("%d", &bt[i]);
        p[i] = i + 1;
        bt1[i] = bt[i];
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("Enter Priority for P%d: ", p[i]);
        scanf_s("%d", &pr[i]);
    }

    printf("\n-------------------------------------");
    printf("\nWaiting Time of Processes for FCFS:\n");

    int ft = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        ft += bt[i];
        wt[i] = ft - bt[i];
        sum += wt[i];
        printf("P%d = %d\n", p[i], wt[i]);
    }

    double r1 = (double)sum / n;
    printf("The Average Waiting Time = %.1f ms\n", r1);
    printf("-------------------------------------\n");
    printf("Waiting Time of Processes for SJF:\n");

    sortProcesses(bt, n, p);

    ft = 0;
    sum = 0;

    for (int i = 0; i < n; i++) {
        ft += bt[i];
        wt[i] = ft - bt[i];
        sum += wt[i];
    }

    sortProcesses(p, n, wt);

    for (int i = 0; i < n; i++) {
        printf("P%d = %d\n", p[i], wt[i]);
    }

    double r2 = (double)sum / n;
    printf("The Average Waiting Time = %.1f ms\n", r2);
    printf("-------------------------------------\n");
    printf("Waiting Time of Processes for Priority:\n");

    ft = 0;
    sum = 0;

    sortProcesses(pr, n, p);

    for (int i = 0; i < n; i++) {
        ft += bt1[i];
        wt[i] = ft - bt1[i];
        sum += wt[i];
    }

    sortProcesses(p, n, wt);

    for (int i = 0; i < n; i++) {
        printf("P%d = %d\n", p[i], wt[i]);
    }

    double r3 = (double)sum / n;
    printf("The Average Waiting Time = %.1f ms\n", r3);
    printf("-------------------------------------\n\n");
    printf("Conclusion: ");
    if (r1 < r2 && r1 < r3)
        printf("First Come First Serve is the most efficient algorithm\n\n");
    else if (r2 < r1 && r2 < r3)
        printf("Shortest Job First is the most efficient algorithm\n\n");
    else
        printf("Priority is the most efficient algorithm\n\n");

    // Release dynamically allocated memory before exiting
    free(bt);
    free(bt1);
    free(p);
    free(wt);
    free(pr);
    free(at);

    return 0;
}
