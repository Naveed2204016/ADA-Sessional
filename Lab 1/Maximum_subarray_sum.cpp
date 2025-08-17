#include<bits/stdc++.h>
using namespace std;
using ll=long long;


struct subarray
{
    ll sum;
    int l;
    int r;
};
subarray fun(vector<int> &v,int l,int m,int r)
{
    int leftsum=INT_MIN;
    int sum=0;
    int lf=m,rf=m+1;
    for(int i=m;i>=l;i--)
    {
        sum+=v[i];
        if(sum>leftsum)
        {
            leftsum=sum;
            lf=i;
        }
    }

    int rightsum=INT_MIN;
    sum=0;
    for(int i=m+1;i<=r;i++)
    {
        sum+=v[i];
        if(sum>rightsum)
        {
            rightsum=sum;
            rf=i;
        }
    }

    return {leftsum+rightsum,lf,rf};
}

subarray play(vector<int> &v,int l,int r)
{
    if(l==r)
    {
        return {v[l],l,r};
    }

    int mid=(l+r)/2;
    subarray lsum=play(v,l,mid);
    subarray rsum=play(v,mid+1,r);
    subarray crosssum=fun(v,l,mid,r);

    if(lsum.sum>=rsum.sum && lsum.sum>=crosssum.sum)
    return lsum;
    else if(rsum.sum>=lsum.sum && rsum.sum>=crosssum.sum)
    return rsum;
    else
    return crosssum;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &x:v)
    cin>>x;
    subarray mx=play(v,0,v.size()-1);
    cout<<"maximum subarray sum is: "<<mx.sum<<endl;
    cout<<"The subarray starting index: "<<mx.l<<" and ending index: "<<mx.r<<endl;
    cout<<"The elements of the subarray are: "<<endl;
    for(int i=mx.l;i<=mx.r;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
