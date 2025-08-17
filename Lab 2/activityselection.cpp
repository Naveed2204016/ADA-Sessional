#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> w(n);
    for(int i=0;i<n;i++)
    {
        int s,f;
        cin>>s>>f;
        w[i].first.first=f;
        w[i].first.second=s;
        w[i].second=i+1;
    }
    sort(w.begin(),w.end());
    int ls=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(w[i].first.second>=ls)
        {
            cout<<"Activity "<<w[i].second<<endl;
            ls=w[i].first.first;
        }
    }
}