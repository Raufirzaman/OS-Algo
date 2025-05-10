#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n); 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int f;
    cin >> f;
    vector<int> ram(f, -1);
    int misses = 0, hits = 0;
    map<int, int> lastUsed; 

    for (int i = 0; i < n; i++) {
        
        if (find(ram.begin(), ram.end(), v[i]) == ram.end()) {
            if (count(ram.begin(), ram.end(), -1) > 0) {
               
                auto it = find(ram.begin(), ram.end(), -1);
                *it = v[i];
            } else {
            
                int lruPage = -1, lruIndex = INT_MAX;
                for (int page : ram) {
                    if (lastUsed[page] < lruIndex) {
                        lruIndex = lastUsed[page];
                        lruPage = page;
                    }
                }
               
                auto it = find(ram.begin(), ram.end(), lruPage);
                *it = v[i];
                lastUsed.erase(lruPage); 
            }
            misses++;
            for(auto page : ram) {
                cout << page << " ";
            }
            cout << "Miss" << endl;
        } else {
            hits++;
            for(auto page : ram) {
                cout << page << " ";
            }
            cout << "Hit " << endl;
        }
      
        lastUsed[v[i]] = i;
    }

    cout << "Total Hits: " << hits << endl;
    cout << "Total Misses: " << misses << endl;
    cout << "Hit Ratio: " << (double)hits / n * 100 << "%" << endl;
    cout << "Miss Ratio: " << (double)misses / n * 100 << "%" << endl;

    return 0;
}