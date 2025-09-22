#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> board(4,vector<int>(4,0));

bool issafe(vector<vector<int>> &board,int row,int col,int n,int m)
{
    for(int j=col-1;j>=0;j--)
    {
        if(board[row][j]==1)
        return false;
    }

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1)
        return false;
    }

    for(int i=row+1,j=col-1;i<n && j>=0;i++,j--)
    {
        if(board[i][j]==1)
        return false;
    }
    return true;
}


bool nqueen(vector<vector<int>> &board,int col,int n,int m)
{
    if(col==m)
    return true;

    for(int i=0;i<n;i++)
    {
        if(issafe(board,i,col,n,m))
        {
            board[i][col]=1;
            if(nqueen(board,col+1,n,m))
            {
                return true;
            }

            board[i][col]=0;
        }
    }
    return false;
}
int main()
{
    if(nqueen(board,0,4,4))
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }

}
