#include<bits/stdc++.h>
using namespace std;

/**
Monotonic queue is a DS where the numbers in it are strictly increasing or decreasing.
Monotonic queue should support add and delete operations, from both sides left and right.
The best way to implement it in C++ is by using dequeue.
**/

/**
Sample problem: Given an array of n numbers (1 <= n <= 10^5). You have to calculate the
sum of the minimum numbers in all sub-arrays of length k starting at index i over all
1 <= i <= n-k+1.
**/

/** We will maintain a monotonic queue for this problem which will be strictly increasing **/

#define sz 100009
int ara[sz];
deque<pair<int, int>> dq; ///value ; index of that value

void add(int val, int idx)
{
    while(!dq.empty() && dq.back().first >= val)
    {
        dq.pop_back();
    }
    dq.push_back({val, idx});
}

void del(int idx)
{
    if(!dq.empty() && dq.front().second == idx)
        dq.pop_front();
}

void Solve()
{
    int n,k,sum=0;
    cin>>n>>k;

    for(int i=1 ; i<=n ; i++) {
        cin>>ara[i];
    }

    for(int i=1 ; i<=k ; i++)
        add(ara[i], i);

    sum += dq.front().first;

    for(int i=k+1 ; i<=n ; i++) {
        del(i-k);
        add(ara[i], i);
        sum += dq.front().first;
    }

    cout<<sum<<endl;
}

int main()
{
    Solve();
    return 0;
}
