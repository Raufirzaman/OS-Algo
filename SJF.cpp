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
   vector<bool>complete(n,false);
    for (int i = 0; i < n; i++) {
        int current=-1;
        int minbt=INT_MAX;
        for (int j = 0; j < n; j++) {if(complete[j]!=true&&at[j].first<=cts&&minbt>bt[at[j].second]){
                current=j;
                minbt=bt[at[j].second];}}
        if(current==-1){cts++;i--;continue;}
        if (cts < at[current].first) cts = at[current].first;
        ct[at[current].second] = cts + bt[at[current].second];
        cts = ct[at[current].second];
        tat[at[current].second] = ct[at[current].second] - at[current].first;
        stat += tat[at[current].second];
        wt[at[current].second] = tat[at[current].second] - bt[at[current].second];
swt += wt[at[current].second];
        complete[current]=true; 
    }
    cout<<endl;
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t" << oat[i].first << "\t\t" << bt[i] << "\t\t" << ct[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }
    cout << "Average Waiting Time: " << (double)swt / n << endl;
    cout << "Average Turnaround Time: " << (double)stat / n << endl;

}