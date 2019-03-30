
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
#define m6              (int)1e6+1
ll a[1010][1010],ct=0,f[m6+5];
ll n,i,m,qq,t,x,y;
queue<pair<ll,ll> > q;

void ff()
{
    f[0]=f[1]=1;
    for(i=2;i<m6;i++)
    f[i]=(f[i-1]*i)%mod;
}
int chk(ll x, ll y)
{
    if(x>=0 && y>=0 && x<n && y<m && a[x][y]==1)
    return 1;
    else
    return 0;
}
void ans(ll x,ll y,ll &count)
{
    if(chk(x-2,y-1))
    {
        q.push(mp(x-2,y-1));
        a[x-2][y-1]=-1;
        ct++;
    }
    if(chk(x-2,y+1))
    {
        q.push(mp(x-2,y+1));
        a[x-2][y+1]=-1;
        ct++;
    }
    if(chk(x-1,y-2))
    {
        q.push(mp(x-1,y-2));
        a[x-1][y-2]=-1;
        ct++;
    }
    if(chk(x-1,y+2))
    {
        q.push(mp(x-1,y+2));
        a[x-1][y+2]=-1;
        ct++;
    }
    if(chk(x+1,y-2))
    {
        q.push(mp(x+1,y-2));
        a[x+1][y-2]=-1;
        ct++;
    }
    if(chk(x+1,y+2))
    {
        q.push(mp(x+1,y+2));
        a[x+1][y+2]=-1;
        ct++;
    }
    if(chk(x+2,y-1))
    {
        q.push(mp(x+2,y-1));
        a[x+2][y-1]=-1;
        ct++;
    }
    if(chk(x+2,y+1))
    {
        q.push(mp(x+2,y+1));
        a[x+2][y+1]=-1;
        ct++;
    }
}
int main()
{
    tle(0);

    ff();
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        ll ans1=1,j;
        cin>>n>>m>>qq;
        while(qq--)
        {
            cin>>x>>y;
            a[x-1][y-1]=1;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                ct=0;
                if(a[i][j]==1)
                {
                    q.push(mp(i,j));
                    ct++;
                    a[i][j]=-1;
                }
                pair<ll,ll> p;
                while(!q.empty())
                {
                    p=q.front();
                    q.pop();
                    x=p.fi;
                    y=p.se;
                    ans(x,y,ct);
                }
                ans1=(ans1%mod*f[ct])%mod;
            }
        }
        cout<<ans1<<"\n";
    }
    return 0;
}
