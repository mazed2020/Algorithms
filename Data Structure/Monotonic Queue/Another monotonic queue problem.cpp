#include <bits/stdc++.h>
using namespace std;

/**
Problem: Given n*m matrix (1 <= n,m <= 3*10^3). You have to calculate the sum of minimum
numbers in all sub-matrices of size a*b.

Similar to: https://codeforces.com/contest/1195/problem/E
**/

int mat[3005][3005];
int temp[3005][3005];

deque<pair<int, int>>dq;

void add(int val, int idx)
{
    while(!dq.empty() && dq.back().first>=val)
    {
        dq.pop_back();
    }
    dq.push_back({val, idx});
}

void del(int idx)
{
    if(!dq.empty() && dq.front().second==idx)
        dq.pop_front();
}

void clearDq()
{
    while(!dq.empty())
    {
        dq.pop_front();
    }
    return;
}

void solve()
{
    long long ans = 0;
    int n,m,a,b;
    cin>>n>>m>>a>>b;

    for(int i=1 ; i <= n ; i++)
    {
        for(int j=1 ; j <= m ; j++)
            cin>>mat[i][j];
    }

    for(int i=1 ; i <= n ; i++)
    {
        clearDq();
        for(int j=1 ; j <= b ; j++)
        {
            add(mat[i][j], j);
        }

        int col = 1;
        temp[i][col++] = dq.front().first;
        for(int j=b+1 ; j<=m ; j++)
        {
            del(j-b);
            add(mat[i][j], j);
            temp[i][col++] = dq.front().first;
        }
    }

    clearDq();
    for(int j=1 ; j <= (m-b+1) ; j++)
    {
        clearDq();
        for(int i=1 ; i <= a ; i++)
        {
            add(temp[i][j], i);
        }

        ans += dq.front().first;

        for(int i=a+1 ; i <= n ; i++)
        {
            del(i-a);
            add(temp[i][j], i);
            ans+=dq.front().first;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    solve();
}

/**
Input:

2 4 2 2
1 3 2 6
5 4 8 1

Output: 4
**/
