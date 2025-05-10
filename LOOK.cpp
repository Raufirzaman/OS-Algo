#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a,b,sizeof(a));

int main()
{
    optimize();
      int n;
        cin>>n;
        vector<int >v(n);
        int head;
        cin>>head;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int lh;
        cin>>lh;
        int ans;
        if(lh==0){
            if(head==0)ans=v[n-1];
else if(head==199)ans=(199-v[0]);
else ans=(head-v[0])+(v[n-1]-v[0]);
}
else{
    if(head==0)ans=v[n-1];
    else if(head==199)ans=(199-v[0]);
    else ans=(v[n-1]-head)+(v[n-1]-v[0]);
}
        cout<<ans<<endl;
    return 0;
}