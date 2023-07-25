#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

void roundRobinScheduling(queue<Process>& readyQueue, int timeQuantum) {
    int currentTime = 0;
    int n = readyQueue.size();
    vector<bool> completed(n, false);

    while (!readyQueue.empty()) {
        Process currentProcess = readyQueue.front();
        readyQueue.pop();

        if (currentProcess.remainingTime <= timeQuantum) {
            // Process execution completes within the time quantum
            cout << "Process " << currentProcess.pid << " executes for " << currentProcess.remainingTime << " units." << endl;
            currentTime += currentProcess.remainingTime;
            currentProcess.remainingTime = 0;
            cout << "Process " << currentProcess.pid << " completes at time " << currentTime << "." << endl;
        } else {
            // Process execution is preempted, and it needs to go back to the ready queue
            cout << "Process " << currentProcess.pid << " executes for " << timeQuantum << " units." << endl;
            currentTime += timeQuantum;
            currentProcess.remainingTime -= timeQuantum;
            cout << "Process " << currentProcess.pid << " is preempted and added back to the queue at time " << currentTime << "." << endl;
            readyQueue.push(currentProcess);
        }

        if (currentProcess.remainingTime > 0) {
            // The process is not finished, so re-enqueue it in the ready queue
            readyQueue.push(currentProcess);
        } else {
            // Calculate waiting time and turnaround time for completed process
            currentProcess.turnaroundTime = currentTime - currentProcess.arrivalTime;
            currentProcess.waitingTime = currentProcess.turnaroundTime - currentProcess.burstTime;
            completed[currentProcess.pid - 1] = true; // Mark the process as completed
        }
    }
}

int main() {
    int n;
    int timeQuantum;

    cout << "Enter the number of processes: ";
    cin >> n;

    queue<Process> readyQueue;

    for (int i = 1; i <= n; i++) {
        Process process;
        process.pid = i;
        cout << "Enter arrival time for process " << i << ": ";
        cin >> process.arrivalTime;
        cout << "Enter burst time for process " << i << ": ";
        cin >> process.burstTime;
        process.remainingTime = process.burstTime;
        readyQueue.push(process);
    }

    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    cout << "\nRound Robin Scheduling Execution Order:\n";
    roundRobinScheduling(readyQueue, timeQuantum);

    return 0;
}
