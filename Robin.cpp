#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, timeQuantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<pair<int, int>> at(n), oat(n); 
    vector<int> bt(n), ct(n), wt(n), tat(n), remainingTime(n), responseTime(n, -1);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
        cin >> at[i].first;
        at[i].second = i;
        cin >> bt[i];
        remainingTime[i] = bt[i]; 
    }

    oat = at; 
    sort(at.begin(), at.end());

    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    queue<int> q;
    int time = 0, completed = 0, swt = 0, stat = 0, index = 0;
    vector<bool> inQueue(n, false);
    while (index < n && at[index].first <= time) {
        q.push(at[index].second);
        inQueue[at[index].second] = true;
        index++;
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        inQueue[i] = false;

        if (responseTime[i] == -1) {
            responseTime[i] = time - oat[i].first;
        }

        int executeTime = min(remainingTime[i], timeQuantum);
        time += executeTime;
        remainingTime[i] -= executeTime;
        while (index < n && at[index].first <= time) {
            q.push(at[index].second);
            inQueue[at[index].second] = true;
            index++;
        }

        if (remainingTime[i] > 0) {
            q.push(i);
            inQueue[i] = true;
        } else {
            ct[i] = time; 
            tat[i] = ct[i] - oat[i].first; 
            wt[i] = tat[i] - bt[i]; 
            stat += tat[i];
            swt += wt[i];
            completed++;
        }
    }
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\tResponse Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << oat[i].first << "\t\t" << bt[i] << "\t\t" << ct[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" << responseTime[i] << "\n";
    }

    cout << "Average Waiting Time: " << (double)swt / n << endl;
    cout << "Average Turnaround Time: " << (double)stat / n << endl;

    return 0;
}