#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of process: ";
    cin >> n;
    pair<int,string> process[n];
    map<string, int> burst;
    for (int i = 0; i < n; i++){
        // string name = to_string(i);
        string p = "P"+ to_string(i+1);
        cout << "\nenter the arrival time of process " << p << " : ";
        int aT;
        cin >> aT;
        process[i].first = aT;
        process[i].second = p;
        cout << "\nenter the burst time of process " <<p << " : ";
        int bT;
        cin >> bT;
        burst[p] = bT;
    }
    sort(process, process + n);
    int staTime[n];

    if(process[0].first != 0){
        staTime[0] = process[0].first;
    }
    else{
        staTime[0] = 0;
    }
    for (int i = 1; i < n; i++){
        staTime[i] = staTime[i - 1] + burst[process[i-1].second]; //ST of previous process - BT of previous process
    }
    int waitTime[n];
    waitTime[0] = 0;
    for (int i = 1; i < n; i++){
        waitTime[i] =(staTime[i] - process[i].first); // ST - AT
    }
    int comTime[n];
    for (int i = 0; i < n; i++){
        comTime[i] =staTime[i] + burst[process[i].second]; //ST - BT
    }
    

    int taTime[n];
    for (int i = 0; i < n; i++){
        taTime[i] = comTime[i] - process[i].first;  // CT - AT
    }

    cout << "pId   ArrTim   BusTim taTime waitTim comTime" << endl;
    for (int i = 0; i < n; i++){
        cout << process[i].second<<"\t"<<process[i].first<< "\t"<<burst[process[i].second]<<"\t" <<taTime[i]<<"\t"<< waitTime[i] <<"\t"<<comTime[i]<<endl;
    }
    double avrgTAT = 0;
    double avrgWT = 0;
    for (int i = 0; i < n; i++){
        avrgTAT += taTime[i];
        avrgWT += waitTime[i];
    }
    cout << "Average waiting Time: " << (double)avrgWT/n << endl;
    cout << "Average Turnaround Time: " << (double)avrgTAT/n << endl;
   
        // cout << "\nprocess will execute in the manner: ";
        // for(auto p : process){
        //     cout << p.second << " ";
        // }
        // pair<int, string> process[n];
        // for(int i =0; i<n; i++){
        //     printf("enter the name of the process %d: ", i+1);
        //     string name ;
        //     cin>>name;
        //     printf("enter arival time of %d requeste want to travel: ", i+1);
        //     int arrivalTime;
        //     cin>>arrivalTime;
        //     process[i].first = arrivalTime;
        //     process[i].second = name;
        // }
        return 0;
}