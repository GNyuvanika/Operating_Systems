#include <stdio.h>
struct Process {
    int process_id;
    int burst_time;
    int priority;
};
void priority_scheduling(struct Process processes[], int n) {
    int waiting_time[n], turnaround_time[n];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    waiting_time[0] = 0;
    turnaround_time[0] = processes[0].burst_time;
    
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }
    double total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }
    double average_waiting_time = total_waiting_time / n;
    double average_turnaround_time = total_turnaround_time / n;
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time,
               processes[i].priority, waiting_time[i], turnaround_time[i]);
    }   
    printf("\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        
        processes[i].process_id = i + 1;
    }
    priority_scheduling(processes, n);    
    return 0;
}

