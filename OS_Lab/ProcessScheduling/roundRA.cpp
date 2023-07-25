// round robin with no or can be said constant arrival time


#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int pid;
    int BT;
    int remTime;
    int CT,TAT,WT;
};

void roundRobinScheduling(queue<Process>& readyQueue, int TQ) {
    int currTime = 0;

    while (!readyQueue.empty()) {
        Process currP = readyQueue.front();
        readyQueue.pop();

        if (currP.remTime <= TQ) {
            // Process execution completes within the time quantum
            // cout << "Process " << currP.pid << " executes for " << currP.remTime << " units." << endl;
            currTime += currP.remTime;
            currP.remTime = 0;
            currP.CT = currTime;
            currP.TAT = currTime;
            currP.WT = currTime - currP.BT;
            // cout << "Process " << currP.pid << " completes at time " << currTime << "." << endl;
        } else {
            // Process execution is preempted, and it needs to go back to the ready queue
            // cout << "Process " << currP.pid << " executes for " << TQ << " units." << endl;
            currTime += TQ;
            currP.remTime -= TQ;
            // cout << "Process " << currP.pid << " is preempted and added back to the queue at time " << currTime << "." << endl;
            // readyQueue.push(currP);
        }
    }
}
void displayTable(const queue<Process>& work) {
    queue<Process> tempQueue = work; // Make a copy of the original queue

    cout << "ID\tBT\tCT\tWT\tTAT\n";
    cout << "--\t--\t--\t--\t--\t--\t---\n";
    while (!tempQueue.empty()) {
        Process p = tempQueue.front();
        tempQueue.pop();

        cout << "P" << p.pid << "\t"
            << p.BT  << "\t"<< "\t" << p.CT << "\t"
            << p.WT << "\t" << p.TAT << endl;
    }
}

int main() {
    int n;
    int TQ;

    cout << "Enter the number of processes: ";
    cin >> n;

    queue<Process> readyQueue;

    for (int i = 1; i <= n; i++) {
        Process process;
        process.pid = i;
        cout << "Enter burst time for process " << i << ": ";
        cin >> process.BT;
        process.remTime = process.BT;
        readyQueue.push(process);
    }

    cout << "Enter time quantum: ";
    cin >> TQ;

    cout << "\nRound Robin Scheduling Execution Order:\n";
    roundRobinScheduling(readyQueue, TQ);
    displayTable(readyQueue);

    return 0;
}
