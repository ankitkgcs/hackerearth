#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector< pair<long long,long long> > vpll;
typedef vector< pair<int,int> > vpii;
#define fr(i,n)         for (i = 0; i < n;i++)
#define fr1(i,n)        for (i = 1; i <=n;i++)
#define sf(x)           scanf("%lld",&x)
#define pf(x)           printf("%lld",x)
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
    ll n,i,x,y,q;
    cin>>n;
    double a[n];
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        a[i]=sqrt(x*x+y*y);
    }
    sort(a,a+n);
    cin>>q;
    while(q--)
    {
        cin>>x;
        cout<<upper_bound(a,a+n,x)-a<<"\n";
    }
    return 0;
}
