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
vector<pair<ll,ll> > a[m5];
ll dist[m5];

void shortestPath(ll src,ll dist[])
{
    priority_queue< pair<ll,ll>, vector <pair<ll,ll> > , greater<pair<ll,ll> > > pq;

    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();

        vector< pair<ll, ll> >::iterator i;
        for (i = a[u].begin(); i != a[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }


}

int main()
{
    tle(0);
    ll n,i,m,k,q,x,u,v,w;
    cin>>n>>m>>k>>q;
    for(i=0;i<m5;i++)
        dist[i]=mod;
    while(m--)
    {
        cin>>u>>v>>w;
        a[u].pb(mp(v,w));
        a[v].pb(mp(u,w));
    }
    while(k--)
    {
        cin>>x;
        shortestPath(x,dist);
    }
    while(q--)
    {
        cin>>x;
        cout<<dist[x]<<"\n";
    }
    return 0;
}
