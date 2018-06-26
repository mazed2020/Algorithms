/**
Bismillahir Rahmanir Rahim
MD. Iqbal Hossain Bappy
Dept. of CSE, CoU
**/

#include<bits/stdc++.h>
#include<queue>
#define perfect                 int main()
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scln(x)                 sc("%lld",&(x))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define pb(a)                   push_back(a)
#define mp                      make_pair
#define db                      double
#define EPS                     10E-10
#define ff                      first
#define ss                      second
#define sqr(x)                  (x)*(x)
#define vi                      vector<int>
#define vl                      vector<ll>
#define vii                     vector<vector<int> >
#define vll                     vector<vector<ll> >
#define DBG                     pf("HI\n")
#define MOD                     1000000007
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                2147483647;
#define longlimit               9223372036854775808
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

///------------------Graph Moves-------------------
/// const int fx[] = {+1,-1,+0,+0};
/// const int fy[] = {+0,+0,+1,-1};
const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
/// const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
/// const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

int vis[10050];
int row,col,i,j,k;
string s[110];
bool valid(int nx,int ny)
{
    if(nx>=1 && nx<=row && ny>=1 && ny<=col)
    {
        if(s[i][j]=='@' && s[nx][ny]=='@')
            return true;
        else
            return false;
    }
    return false;
}
vector<int>graph[10050];
void DFS(int start,int x)
{
    if(vis[start]==0 || vis[start]!=x)
    {
        vis[start]=x;
        for(int i=0;i<graph[start].size();i++)
        {
            int temp=graph[start][i];
            DFS(temp,x);
        }
    }
}
perfect
{
    int co,x;
    string temp;
    s[0] = "..";
    while(1)
    {
        x=1;
        sc("%d %d",&row,&col);
        int val[row+1][col+1];
        if(row == 0)
            break;
        s[row+1]="...";
        for(i=1;i<=row;i++)
        {
            cin>>temp;
            s[i]=" "+temp+" ";
        }
        for(i=1;i<=row;i++)
        {
            for(j=1;j<=col;j++)
            {
                val[i][j]=x;
                x++;
            }
        }
        for(i=1;i<=row;i++)
        {
            for(j=1;j<=col;j++)
            {
                for(k=0;k<8;k++)
                {
                    int nx=i+fx[k];
                    int ny=j+fy[k];
                    if(valid(nx,ny))
                    {
                        graph[val[i][j]].pb(val[nx][ny]);
                    }
                }
            }
        }
        x=1;
        for(i=1;i<=row;i++)
        {
            for(j=1;j<=col;j++)
            {
                if(vis[val[i][j]]==0 && s[i][j]=='@')
                {
                    DFS(val[i][j],x);
                    x++;
                }
            }
        }
        set<int>st;
        for(i=1;i<=row*col;i++)
        {
            if(vis[i] != 0)
                st.insert(vis[i]);
        }
        pf("%d\n",st.size());
        for(i=0;i<=10000;i++)
            graph[i].clear();
        ms(vis,0);
    }
    return 0;
}

