#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
void fun(string s,int index)
{
    if(index>=s.size())
    {
        ans.push_back(s);
        return;
    }

    for(int j=index;j<s.size();j++)
    {
        swap(s[index],s[j]);
        fun(s,index+1);
        swap(s[index],s[j]);
    }
}
using namespace std;
int main()
{
    string s="cuet";
    fun(s,0);
    int i=1;
    for(auto &x:ans)
    {
        cout<<i<<" "<<x<<endl;
        i++;
    }
}