#include <stdio.h>
#include <limits.h> // For INT_MAX

// Structure to represent a process
struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime; // New field for completion time
};

// Function to sort processes based on arrival time
void sortProcesses(struct Process processes[], int n) {
    // Implement your sorting logic here (e.g., using bubble sort or any other sorting algorithm)
    // Sort processes based on arrival time
    // ...
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process processes[], int n) {
    // Initialize waiting time and turnaround time arrays
    int waitingTime[n], turnaroundTime[n];

    // Calculate completion time for each process
    processes[0].completionTime = processes[0].burstTime + processes[0].arrivalTime;
    for (int i = 1; i < n; i++) {
        processes[i].completionTime = processes[i - 1].completionTime + processes[i].burstTime;
    }

    // Calculate waiting time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = processes[i].completionTime - processes[i].arrivalTime;
        waitingTime[i] = turnaroundTime[i] - processes[i].burstTime;
    }

    // Print results in tabular form
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n",
               processes[i].processId, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].completionTime,
               turnaroundTime[i], waitingTime[i]);
    }

    // Calculate average waiting time and average turnaround time
    float avgWaitingTime = 0.0, avgTurnaroundTime = 0.0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += waitingTime[i];
        avgTurnaroundTime += turnaroundTime[i];
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\nAverage Waiting Time = %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time = %.2f\n", avgTurnaroundTime);
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].processId = i + 1;
    }

    // Sort processes based on arrival time
    sortProcesses(processes, n);

    // Calculate waiting time and turnaround time
    calculateTimes(processes, n);

    return 0;
}
