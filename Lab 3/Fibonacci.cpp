#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> dp1(N,-1);

int fib(int n)
{
    if(n==0)
    return 0;
    else if(n==1)
    return 1;
    else if(dp1[n]!=-1)
    return dp1[n];

    int ans=fib(n-1)+fib(n-2);
    return dp1[n]=ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    cout<<fib(n)<<endl;
}
