#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct P {
    int pid;
    int at;
    int bt;
    int st;
    int ct;
    int wt;
    int tat;
    
};
bool compare(const P& p1, const P& p2) {
    return p1.at < p2.at;
}

void calculateTimes(std::vector<P>& jobs , int n) {
    sort(jobs.begin(), jobs.end(), compare);
    jobs[0].st = 0;
    jobs[0].wt = 0;
    for (int i = 1; i < n; i++){
        jobs[i].st = jobs[i - 1].st + jobs[i-1].bt; //ST of previous process - BT of previous process
    }
    for (int i = 0; i < n; i++){
        jobs[i].ct =jobs[i].st + jobs[i].bt; // CT = ST + BT
        jobs[i].tat = jobs[i].ct - jobs[i].at; // TAT = CT - AT
        // jobs[i].wt = jobs[i].tat - jobs[i].bt; // WT = TAT - BT
    }
    for (int i = 1; i < n; i++){
        jobs[i].wt = jobs[i].tat - jobs[i].bt; //TAT of previous process - BT of previous process
    }
    
}
void displayResults(const std::vector<P>& jobs , int n) {
    std::cout << "Process\tArrival Time\tBurst Time\tStart Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; ++i) {
        std::cout <<jobs[i].pid << "\t" << jobs[i].at << "\t\t" << jobs[i].bt
                  << "\t\t" << jobs[i].st << "\t\t"
                  << jobs[i].ct << "\t\t" << jobs[i].wt << "\t\t"
                  << jobs[i].tat << "\n";
    }
}

int main(){
    int n;
    cin>>n;
    vector<P> jobs(n);
    for(int i =0; i<n; i++){
        jobs[i].pid = i+1;
        cout<<"enter AT , BT of process "<<i+1<<": ";
        cin>>jobs[i].at>>jobs[i].bt;
    }
    calculateTimes(jobs, n);
    displayResults(jobs, n);
}