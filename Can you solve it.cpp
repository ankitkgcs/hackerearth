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

int main()
{
    tle(0);
    ll n,i,t,q,x;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        ll a[n+4],bk[n+4],fr[n+4];

        set<ll> s;set<ll>::iterator it;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
        }

        s.insert(a[1]);
        fr[1]=0;bk[n]=0;
        for(i=2;i<=n;i++)
        {
            it=s.find(a[i]);
            if(it!=s.end())
            {
                fr[i]=*it;
                continue;
            }
            s.insert(a[i]);
            it=s.find(a[i]);
            if(it!=s.begin())
            {
                it--;
                fr[i]=*it;
            }
            else
            fr[i]=0;
        }
        s.clear();
        s.insert(a[n]);
        for(i=n-1;i>0;i--)
        {
            it=s.find(a[i]);
            if(it!=s.end())
            {
                bk[i]=*it;
                continue;
            }
            s.insert(a[i]);
            it=s.find(a[i]);
            if(it!=s.begin())
            {
                it--;
                bk[i]=*it;
            }
            else
            bk[i]=0;
        }
        // for(i=1;i<=n;i++)
        //     cout<<fr[i]<<"  "<<a[i]<<"  "<<bk[i]<<"\n";
        while(q--)
        {
            cin>>x;
            if(x==1 || x==n)
                cout<<"0\n";
            else
            {
                cout<<a[x]*bk[x]*fr[x]<<"\n";
            }
        }
    }
    return 0;
}
