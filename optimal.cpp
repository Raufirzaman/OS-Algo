#include<bits/stdc++.h>
using namespace std;
int main()
{int n;
    cin >> n;  
    vector<int>v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int f;
    cin >> f;
    vector<int>ram(f, -1);
    map<int, int> futureUse;
    int miss = 0, hits = 0;
    for(int i = 0; i < n; i++) {
    if(find(ram.begin(), ram.end(), -1) != ram.end()) {
        if(find(ram.begin(), ram.end(), v[i]) != ram.end()) {
            hits++;
            cout << "Hit " ;
            for(auto page : ram) {
                cout << page << " ";
            }
            cout << endl;
        } else {
            auto it = find(ram.begin(), ram.end(), -1);
            *it = v[i];
            miss++;
            cout << "Miss " ;
            for(auto page : ram) {
                cout << page << " ";
            }
            cout << endl;
        }
    
 
    } else {
        if(find(ram.begin(),ram.end(),v[i])!=ram.end()){
        hits++;
        cout << "Hit " ;
        for(auto page : ram) {
            cout << page << " ";
        }
        cout << endl;
        }
        else {
            int vindex = -1, farthest = -1;
            for (int k = 0; k < ram.size(); k++) {
                int nextUse = INT_MAX;
                for (int j = i + 1; j < n; j++) {
                    if (ram[k] == v[j]) {
                        nextUse = j;
                        break;
                    }
                }
                if (nextUse > farthest) {
                    farthest = nextUse;
                    vindex = k;
                }
            }
            ram[vindex] = v[i];
            miss++;
            cout << "Miss " ;
            for(auto page : ram) {
                cout << page << " ";
            }
            cout << endl;
        }
    }
}
    cout << "Total Hits: " << hits << endl;
    cout << "Total Misses: " << miss << endl;
    cout << "Hit Ratio: " << (double)hits / n * 100 << "%" << endl;
    cout << "Miss Ratio: " << (double)miss / n * 100 << "%" << endl;
    return 0;
}