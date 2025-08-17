#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,w;
    cin>>n>>w;
    int t1=w;
    vector<pair<int,int>> a(n);
    vector<pair<int,int>> b(n);

    vector<pair<int,pair<int,int>>> ret(n);
    for(int i=0;i<n;i++)
    {
        int w1,p1;
        cin>>w1>>p1;
        a[i].first=w1;
        a[i].second=p1;
        b[i].first=p1;
        b[i].second=w1;
        ret[i].first=(p1/w1);
        ret[i].second.first=w1;
        ret[i].second.second=p1;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    sort(ret.begin(),ret.end());
    int ans1=0,ans2=0,ans3=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].first<=w)
        {
            w-=a[i].first;
            ans1+=a[i].second;
        }
        else
        {
            ans1+=(w/a[i].first)*a[i].second;
            break;
        }
    }
    w=t1;
    for(int i=0;i<n;i++)
    {
        if(b[i].second<=w)
        {
            w-=b[i].second;
            ans2+=b[i].first;
        }
        else
        {
            ans2+=(w/b[i].second)*b[i].first;
            break;
        }
    }
    w=t1;
    for(int i=0;i<n;i++)
    {
        if(ret[i].second.first<=w)
        {
            w-=ret[i].second.first;
            ans3+=ret[i].second.second;
        }
        else
        {
            ans3+=(w/ret[i].second.first)*ret[i].second.second;
            break;
        }
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;


}
