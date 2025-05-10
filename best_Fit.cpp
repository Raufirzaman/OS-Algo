#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,p;
    cin>>m>>p;
    vector<pair<int ,bool>>process,block;
    cout<<"Enter Memory Block:";
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        block.push_back({x,false});
    }
    cout<<"Enter Processes:";
    for(int i=0;i<p;i++){
        int x;
        cin>>x;
        process.push_back({x,false});
    }
    
    for(int i=0;i<p;i++){
        int mindif=INT_MAX;
        int index=-1;
        for(int j=0;j<m;j++){
            if(process[i].first<=block[j].first && block[j].second==false){
                int dif=block[j].first-process[i].first;
                if(dif<mindif){
                    mindif=dif;
                    index=j;
                }
            }
        }
        if(index!=-1){
            block[index].first-=process[i].first;
            block[index].second=true;
            process[i].second=true;
        }
    }
    int intfrag=0;
    int extfrag=0;
    for(int i=0;i<m;i++){
        if(block[i].second==false){
            extfrag+=block[i].first;
        }
        else{
            intfrag+=block[i].first;
        }
    }
    cout<<"Internal Fragmentation: "<<intfrag<<endl;
    bool ext=false;
    for(int i=0;i<p;i++){
        if(process[i].second==false){
            ext=true;
            break;
        }        
    }
    if(ext)cout<<"External Fragmentation: "<<extfrag<<"\nTotal Fragmentation: "<<intfrag+extfrag<<endl;
    else{cout<<"No External Fragmentation"<<"\nTotal Fragmentation: "<<intfrag<<endl;}
}