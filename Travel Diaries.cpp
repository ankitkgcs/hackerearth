#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector< pair<long long,long long> > vpll;
typedef vector< pair<int,int> > vpii;
#define fr(i,n)         for (i = 0; i < n;i++)
#define fr1(i,n)        for (i = 1; i <=n;i++)
#define tle(x)          ios_base::sync_with_stdio(x),cin.tie(NULL),cout.tie(NULL)
#define gcd(a,b)        __gcd(a,b)
#define stacki          stack<int>
#define stackll         stack<long long>
#define queuei          queue<int >
#define queuell         queue<long long >
#define pr_qi           priority_queue<int >
#define pr_qll          priority_queue<long long >
#define mapi            map<int,int>
#define mapll           map<long long,long long>
#define fi              first
#define se              second
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define m5              (int)1e5+5
ll t[1010][1010];
ll a[1010][1010];
ll n,i,m,j,s=0;
queue<pair<ll,ll>> q;
int chk(ll x, ll y)
{
    if(x>=0 && y>=0 && x<n && y<m && a[x][y]==1 )
    return 1;
    else
    return 0;
}
void ans(ll x,ll y)
{
    if(chk(x-1,y))
    {
        q.push(mp(x-1,y));
        a[x-1][y]=2;
        t[x-1][y]=t[x][y]+1;
    }
    if(chk(x+1,y))
    {
        q.push(mp(x+1,y));
        a[x+1][y]=2;
        t[x+1][y]=t[x][y]+1;
    }
    if(chk(x,y-1))
    {
        q.push(mp(x,y-1));
        a[x][y-1]=2;
        t[x][y-1]=t[x][y]+1;
    }
    if(chk(x,y+1))
    {
        q.push(mp(x,y+1));
        a[x][y+1]=2;
        t[x][y+1]=t[x][y]+1;
    }
}
int main()
{
    tle(0);
    ll x,y;
    cin>>n>>m;
    memset(t,0,sizeof(t));

    for(i=0;i<n;i++) // 2-D array
    {
        for(j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++) // if 2 check neighbours
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==2)
            {
                q.push(mp(i,j));
            }
        }
    }
    pair<ll,ll> p;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        x=p.fi;y=p.se;
        ans(x,y);
    }

    for(i=0;i<n;i++) // finding max time
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                s=-1;
                break;
            }
            s=max(s,t[i][j]);
        }
        if(s==-1)
        break;
    }
    cout<<s<<"\n";
    return 0;
}
