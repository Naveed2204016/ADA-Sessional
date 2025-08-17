#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int power(int x,int n)
{
    if(n==0)
    return 1;
    int res=power(x,n/2);
    if(n%2==0)
    {
        return res*res;
    }
    else
    {
        return x*res*res;
    }
}
int main()
{
    int x,n;
    cin>>x>>n;
    cout<<power(x,n)<<endl;
}
