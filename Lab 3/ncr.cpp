#include<bits/stdc++.h>
using namespace std;

const int N=1e3;
const int k=1e3;
vector<vector<int>> dp1(N,vector<int>(k+1,-1));

int ncr(int n,int k)
{
    if(k==0 || n==k)
    return 1;
    else if(dp1[n][k]!=-1)
    return dp1[n][k];

    int ans=ncr(n-1,k-1)+ncr(n-1,k);
    return dp1[n][k]=ans;
}
int main() 
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    dp[0][0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=min(i,k);j++)
        {
            if(j==0 || i==j)
            {
                dp[i][j]=1;
            }
            else
            {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k]<<endl;
    cout<<ncr(n,k)<<endl;
}


