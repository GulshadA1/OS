#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Process {
    int id;
    int AT;
    int tempBT;
    int BT;
    int priority;
    int ST;
    int CT;
    int WT;
    int TAT;
    bool executed;
    Process(int id, int at, int bt, int priority)
        : id(id), AT(at), BT(bt),
          tempBT(BT), priority(priority), ST(0),
          CT(0), WT(0), TAT(0),
          executed(false)
    {}
};

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Process> jobs;

    cout << "Enter Arrival, Burst, Priority: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "For process " << (i + 1) << ":" << endl;

        int AT, BT, priority;
        cin >> AT >> BT >> priority;

        Process process(i + 1, AT, BT, priority);
        jobs.push_back(process);
    }

    // Sort jobs based on arrival time
    sort(jobs.begin(), jobs.end(),
         [](const Process& p1, const Process& p2) {
             return p1.AT < p2.AT;
         });

    int currTime = 0;
    int completedjobs = 0;
    vector<Process> executedjobs;

    while (completedjobs < n) {
        int highestPriority = INT_MAX;
        int selectedProcessIndex = -1;

        for (int i = 0; i < n; i++) {
            Process& process = jobs[i];

            if (!process.executed && process.AT <= currTime && process.priority < highestPriority) {
                highestPriority = process.priority;
                selectedProcessIndex = i;
            }
        }

        if (selectedProcessIndex == -1) {
            currTime++;
            continue;
        }

        Process& selectedProcess = jobs[selectedProcessIndex];
        selectedProcess.executed = true;

        if (completedjobs == 0) {
            selectedProcess.ST = 0;
        } else {
            selectedProcess.ST = max(currTime, selectedProcess.AT);
        }

        selectedProcess.CT = selectedProcess.ST + selectedProcess.BT;
        selectedProcess.TAT = selectedProcess.CT - selectedProcess.AT;
        selectedProcess.WT = selectedProcess.TAT - selectedProcess.BT;

        executedjobs.push_back(selectedProcess);

        currTime = selectedProcess.CT;
        completedjobs++;
    }

    float AverageWT = 0.0, AverageTAT = 0.0;
    for (const Process& p : executedjobs) {
        AverageTAT += p.TAT;
        AverageWT += p.WT;
    }

    float throughput = static_cast<float>(n) / currTime;

    cout << "\nProcess\t\tArrival\t\tBurst\t\tStart\t\tCompletion\t\tWaiting\t\tTurnaround" << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    for (const Process& process : executedjobs) {
        cout << process.id << "\t\t" << process.AT << "\t\t" << process.tempBT << "\t\t" <<
            process.ST << "\t\t" << process.CT << "\t\t\t" << process.WT <<
            "\t\t\t" << process.TAT << endl;
    }

    cout << "Average Waiting time: " << AverageWT / n << endl;
    cout << "Average Turnaround Time: " << AverageTAT / n << endl;
    cout << "Throughput: " << throughput << " jobs per unit of time" << endl;

    return 0;
}