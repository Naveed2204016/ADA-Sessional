#include<bits/stdc++.h> 
using namespace std; 
const int N=1005; 
const int x=1e5+5; 
vector<vector<int>> dp1(N,vector<int>(x,-1)); 
int fun(int i,int j,vector<int> &wt,vector<int> &val) 
{ 
    if(i<0 || j==0) 
    return 0; 
    if(dp1[i][j]!=-1) 
    return dp1[i][j]; 
    int ans=fun(i-1,j,wt,val); 
    if(j>=wt[i]) 
    ans=max(ans,val[i]+fun(i-1,j-wt[i],wt,val)); 
    return dp1[i][j]=ans; 
} 
int main() 
{ 
    int n,w; 
    cin>>n>>w; vector<int> wt; 
     
    vector<int> val; 
    vector<vector<int>> dp(n+1,vector<int>(w+1,0)); 
    for(int i=0;i<n;i++) 
    { 
        int p; 
        cin>>p; 
        wt.push_back(p); 
    } 
    for(int i=0;i<n;i++) 
    { 
        int q; 
        cin>>q; 
        val.push_back(q); 
    } 
    for(int i=1;i<=n;i++) 
    { 
        for(int j=0;j<=w;j++) 
        { 
            int value=val[i-1]; 
            int weight=wt[i-1]; 
            int pick,skip; 
            if(j>=weight) 
            { 
                pick=value+dp[i-1][j-weight]; 
            } 
            else 
            { 
 
                pick=0; 
            } 
            skip=dp[i-1][j]; 
            dp[i][j]=max(pick,skip); 
        } 
    } 
    cout<<dp[n][w]<<endl; 
    cout<<fun(n-1,w,wt,val)<<endl;  
}
