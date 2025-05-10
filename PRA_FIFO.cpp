#include<bits/stdc++.h>
using namespace std;

void printQueue(std::queue<int> q) {
queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() <<"\t\t";
        temp.pop();
    }

}
int main()
{

      int f,ins,m=0,h=0;
        queue<int>q;
        cout<<"Enter the number of frames: ";
        cin>>f;
        cout<<"Enter the number of instances: ";
        cin>>ins;
        vector<int>arr(ins);
        map<int ,bool>pt;
        cout<<"Enter the instances: ";
        for(int i=0;i<ins;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<ins;i++)
        {
            if(q.size()<f)
            {
                if (!pt[arr[i]]) {
                    q.push(arr[i]);
                    pt[arr[i]] = true;
                    m++; 
                    cout<<"M\t\t";
                } 
                else {
                    h++;
                    cout<<"H\t\t";
                }
            }
            else
            {
                if(pt[arr[i]]==false)
                {int x=q.front();
                    q.pop();
                    pt[x]=false;
                    pt[arr[i]]=true;
                    m++;
                    q.push(arr[i]);
                    cout<<"M\t\t";
                }
                else
                {
                   h++;
                    cout<<"H\t\t";

                }
            }
            cout<<arr[i]<<"\t\t";
            printQueue(q);

            cout<<endl;

        }
        cout<<endl;
        cout<<"Page Faults: "<<m<<endl;
        cout<<"Page Hits: "<<h<<endl;
        cout<<"Page Fault Rate: "<<(float)m/ins*100<<"%"<<endl;
        cout<<"Page Hit Rate: "<<(float)h/ins*100<<"%"<<endl;
        

    }