#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>> v;
    int mex=0;
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        mex=max(mex,b);
        v.push_back({c,{a,b}});
    }
    vector<int> d(mex+1,-1);
    sort(v.begin(),v.end(),greater<pair<int,pair<int,int>>>());
    for(int i=0;i<v.size();i++)
    {
        int x=v[i].second.second;
        for(int j=x;j>=1;j--)
        {
            if(d[j]==-1)
            {
                d[j]=v[i].second.first;
                break;
            }
        }
    }

    for(int i=1;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
}