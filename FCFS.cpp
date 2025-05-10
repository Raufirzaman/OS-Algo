#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<pair<int, int>> at(n),oat(n);
    vector<int> bt(n), ct(n), wt(n), tat(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the arrival time and burst time of process " << i + 1 << ": ";
        cin >> at[i].first; at[i].second = i; cin >> bt[i];
    }
    oat = at;
    sort(at.begin(), at.end());
    int cts = 0,stat=0,swt=0;

    for (int i = 0; i < n; i++) {
        if (cts < at[i].first) cts = at[i].first;
        ct[at[i].second] = cts + bt[at[i].second];
        cts = ct[at[i].second];
        tat[at[i].second] = ct[at[i].second] - at[i].first;
        stat += tat[at[i].second];
        wt[at[i].second] = tat[at[i].second] - bt[at[i].second];
swt += wt[at[i].second];
    }
    cout<<endl;
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << oat[i].first << "\t\t" << bt[i] << "\t\t" << ct[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }
    cout << "Average Waiting Time: " << (double)swt / n << endl;
    cout << "Average Turnaround Time: " << (double)stat / n << endl;

}