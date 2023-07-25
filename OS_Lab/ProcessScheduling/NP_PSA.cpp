// #include<iostream>
// using namespace std;
// int main()
// {
// int n ;
// cout<<"Enter Process Size-:";
// cin>>n;
// int at[n],bt[n],priority[n] ;
// for(int i=0;i<n;i++){
// cout<<"Enter AT , BT , Priority";
// cin>>at[i]>>bt[i]>>priority[i];
// }
// int CPU = 0,allTime = 0, ATt[n] ,NoP = n,PPt[n],wt[n] ,tat[n],i = 0;
// for (i = 0; i < n; i++)
// {
// PPt[i] = priority[i];
// ATt[i] = at[i];
// }
// int LAT = 0;
// for (i = 0; i < n; i++)
// if (at[i] > LAT)
// LAT = at[i];
// int MAX_P = 0;
// for (i = 0; i < n; i++)
// if (PPt[i] > MAX_P)
// MAX_P = PPt[i];
// int ATi = 0;
// int P1 = PPt[0];
// int P2 = PPt[0];
// int j = -1;
// while (NoP > 0 && CPU <= 1000)
// {
// for (i = 0; i < n; i++)
// {
// if ((ATt[i] <= CPU) && (ATt[i] != (LAT + 10)))
// {
// if (PPt[i] != (MAX_P + 1))
// {
// P2 = PPt[i];
// j = 1;
// if (P2 < P1)
// {
// j = 1;
// ATi = i;
// P1 = PPt[i];
// P2 = PPt[i];}
// }
// }}
// if (j == -1)
// {
// CPU = CPU + 1;
// continue;}
// else
// {
// wt[ATi] = CPU - ATt[ATi];
// CPU = CPU + bt[ATi];
// tat[ATi] = CPU - ATt[ATi];
// ATt[ATi] = LAT + 10;
// j = -1;
// PPt[ATi] = MAX_P + 1;
// ATi = 0;
// P1 = MAX_P + 1;
// P2 = MAX_P + 1;
// NoP = NoP - 1;
// }
// }
// cout <<"\nProcess_Number\tBurst_Time\tPriority\tArrival_Time\tWaiting_Time\tTurnaround_Time\n\n";
// for (i = 0; i < n; i++)
// {
// cout << "P" << i + 1 << "\t\t" << bt[i] << "\t\t" << priority[i] << "\t\t" << at[i] << "\t\t"<< wt[i] <<"\t\t" << tat[i] << endl;
// }
// float AvgWT = 0;
// float AVGTaT = 0;
// for (i = 0; i < n; i++)
// {
// AvgWT = wt[i] + AvgWT;
// AVGTaT = tat[i] + AVGTaT;
// }
// cout << "Average waiting time = " << AvgWT / n << endl;
// cout << "Average turnaround time = " << AVGTaT / n << endl;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id,AT,BT,PR,ST,CT,WT,TAT;
};

bool comparePR(const Process& p1, const Process& p2) {
    if (p1.AT == 0 && p2.AT != 0) {
        return true;
    } else if (p1.AT != 0 && p2.AT == 0) {
        return false;
    } else {
        return p1.PR < p2.PR;
    }
}


void calculateTimes(std::vector<Process>& jobs) {
    std::sort(jobs.begin(), jobs.end(), comparePR);

    int currentTime = 0;
    if (jobs[0].AT > 0) {
        currentTime = jobs[0].AT;
    }
    for (int i = 0; i < jobs.size(); ++i) {
        if (currentTime < jobs[i].AT) {
            currentTime = jobs[i].AT;
        }
        jobs[i].ST = currentTime;
        jobs[i].CT = currentTime + jobs[i].BT;
        jobs[i].TAT = jobs[i].CT - jobs[i].AT;
        jobs[i].WT = jobs[i].TAT - jobs[i].BT;
        currentTime = jobs[i].CT;
    }
}

void displayTable(const vector<Process>& jobs) {
    cout << "ID\tAT\tBT\tPR\tST\tCT\tWT\tTAT\n";
    cout << "--\t--\t--\t--\t--\t--\t--\t---\n";
    for (const auto& p : jobs) {
        cout<<"P" << p.id << "\t" << p.AT << "\t"
            << p.BT<<"\t"<<p.PR<<"\t"<< p.ST << "\t"
            << p.CT << "\t" << p.WT << "\t"
            << p.TAT << endl;
    }
}


// void displayTable(const std::vector<Process>& jobs) {
//     std::cout << "Process\tArrival Time\tBurst Time\tPR\tStart Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
//     for (int i = 0; i < jobs.size(); ++i) {
//         std::cout << "P" << i + 1 << "\t" << jobs[i].AT << "\t\t" << jobs[i].BT
//                   << "\t\t" << jobs[i].PR << "\t\t" << jobs[i].ST << "\t\t"
//                   << jobs[i].CT << "\t\t" << jobs[i].WT << "\t\t"
//                   << jobs[i].WT << "\n";
//     }
// }
double calAverageTAT(const vector<Process>& jobs,int n) {
    double sumTAT = 0.0;

    for (const auto& process : jobs) {
        sumTAT += process.TAT;
    }

    return sumTAT / n;
}
double calAverageWT(const vector<Process>& jobs,int n) {
    double sumWT = 0.0;

    for (const auto& process : jobs) {
        sumWT += process.WT;
    }

    return sumWT / n;
}

double calThroughput(const vector<Process>& jobs, int totalTime) {
    int n = jobs.size();
    double throughput = static_cast<double>(n) / totalTime;

    return throughput;
}


int main() {
    int n;
    std::cout << "Enter the number of jobs: ";
    std::cin >> n;

    std::vector<Process> jobs(n);

    for (int i = 0; i < n; ++i) {
        jobs[i].id = i+1;
        std::cout << "P" << jobs[i].id   ;
        std::cout << " Arrival Time: ";
        std::cin >> jobs[i].AT;
        std::cout << "Burst Time: ";
        std::cin >> jobs[i].BT;
        std::cout << "PR: ";
        std::cin >> jobs[i].PR;
    }

    calculateTimes(jobs);
    displayTable(jobs);
    
    double avgTAT = calAverageTAT(jobs,n);
    cout << "Average Turnaround Time: " << avgTAT << endl;
    double avgWT = calAverageWT(jobs,n);
    cout << "Average Waiting Time: " << avgWT << endl;
    int totalTime = jobs[n - 1].CT - jobs[0].AT;
    double throughput = calThroughput(jobs, totalTime);
    cout << "Throughput: " << throughput << endl;

    return 0;
}

