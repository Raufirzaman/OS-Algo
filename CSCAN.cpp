#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define endl "\n"

#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a,b,sizeof(a));

int main()
{
 
      int n;
        cin>>n;
        vector<int>v(n);
        int head;
        cin>>head;

        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int index=0;
        for(int i=0;i<n;i++){
            if(v[i]>head){
                index=i;
                break;
            }
        }
        int lh;
        cin>>lh;
        int ans=199;
        if(lh==0){
            if(head==0)ans=v[n-1];
else if(head==199)ans=(199-v[0]);
else ans=(head)+(199-v[index])+ans;}
else{
    if(head==0)ans=v[n-1];
    else if(head==199)ans=(199-v[0]);
    else ans=(199-head)+v[index-1]+ans;}
        cout<<ans<<endl;

    return 0;
}