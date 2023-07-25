// #include <iostream>

// using namespace std;

// int main() {
//     int NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0;
//     float avg_wt, avg_tat;

//     cout << "Total number of processes in the system: ";
//     cin >> NOP;
//     y = NOP;

//     int at[NOP], bt[NOP], temp[NOP], ct[NOP];
//     int i; 
//     for ( i = 0; i < NOP; i++) {
//         cout << "\nEnter the Arrival and Burst time of Process[" << i + 1 << "]:\n";
//         cout << "Arrival time: ";
//         cin >> at[i];
//        cout << "Burst time: ";
//         cin >> bt[i];
//         temp[i] = bt[i];
//     }

//     cout << "Enter the Time Quantum for the process: ";
//     cin >> quant;

//     cout << "\nProcess  \t\t Burst Time \t\t\t TAT \t\t\t Waiting Time\n";
//     for (sum = 0, i = 0; y != 0 ;) {
//         if (temp[i] <= quant && temp[i] > 0) {
//             sum = sum + temp[i];
//             temp[i] = 0;
//             count = 1;
//         } else if (temp[i] > 0) {
//             temp[i] = temp[i] - quant;
//             sum = sum + quant;
//         }
//         if (temp[i] == 0 && count == 1) {
//             y--;
//             // cout << "Process " << i + 1 << "\t\t" << bt[i] << "\t\t\t\t" <<
//             //  sum - at[i] << "\t\t\t" << sum - at[i] - bt[i] << "\n";
            
//             wt = wt + sum - at[i] - bt[i];
//             tat = tat + sum - at[i];
//             count = 0;
//         }
//         if (i == NOP - 1) {
//             i = 0;
//         } else if (at[i + 1] <= sum) {
//             i++;
//         } else {
//             i = 0;
//         }
//     }
//     for (int j = 0; j < NOP; j++){
//         ct[j] = tat[j] + at[j];
//     }
//         std::cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
//     for (int i = 0; i < NOP; ++i) {
//         std::cout << "P" << i + 1 << "\t" <<at[i] << "\t\t" << bt[i]
//                   << "\t\t" << ct[i] << "\t\t" << wt[i] << "\t\t"<< tat[i] << "\n";
//     }


//     avg_wt = static_cast<float>(wt) / NOP;
//     avg_tat = static_cast<float>(tat) / NOP;

//     cout << "\nAverage Turn Around Time: " << avg_wt << "\n";
//     cout << "Average Waiting Time: " << avg_tat << "\n";

//   return 0;
// }