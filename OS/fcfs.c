#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Function to sort processes based on arrival time (not needed for FCFS)
void sortProcesses(struct Process processes[], int n) {
    // FCFS does not require sorting
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process processes[], int n) {
    // Calculate completion time for each process
    processes[0].completionTime = processes[0].burstTime;
    for (int i = 1; i < n; i++) {
        processes[i].completionTime = processes[i - 1].completionTime + processes[i].burstTime;
    }

    // Calculate turnaround time and waiting time for each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }
}

// Function to display the results
void displayResults(struct Process processes[], int n) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n",
               processes[i].processId, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].completionTime,
               processes[i].turnaroundTime, processes[i].waitingTime);
    }
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

    // Calculate waiting time and turnaround time
    calculateTimes(processes, n);

    // Display the results
    displayResults(processes, n);

    // Calculate average waiting time and average turnaround time
    float avgWaitingTime = 0.0, avgTurnaroundTime = 0.0;
    for (int i = 0; i < n; i++) {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\nAverage Waiting Time = %d\n", avgWaitingTime);
    printf("Average Turnaround Time = %d\n", avgTurnaroundTime);

    return 0;
}
