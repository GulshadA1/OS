#include <bits/stdc++.h>
using namespace std;

int FCFS_disk_scheduling(const vector<int>& requests, int initial_position) {
    int head_movement = 0;
    int current_position = initial_position;

    for (int i = 0; i < requests.size(); i++) {
        // Calculate the absolute difference between current position and the next request
        int movement = abs(requests[i] - current_position);
        head_movement += movement;

        current_position = requests[i];
    }

    return head_movement;
}

int main() {
    vector<int> requests;
    int total_requests, initial_position;

    cout << "Enter the total number of disk requests: ";
    cin >> total_requests;

    cout << "Enter the initial head position: ";
    cin >> initial_position;

    cout << "Enter the disk requests: ";
    for (int i = 0; i < total_requests; i++) {
        int request;
        cin >> request;
        requests.push_back(request);
    }

    int total_head_movement = FCFS_disk_scheduling(requests, initial_position);

    cout << "Total head movement: " << total_head_movement << endl;
    cout<<"\n throughput = "<<(float)total_requests/total_head_movement;

    return 0;
} 
