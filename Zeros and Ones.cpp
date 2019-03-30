
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector< pair<long long,long long> > vpll;
typedef vector< pair<int,int> > vpii;
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))
#define max4(a,b,c,d)   max3(a,b,max(c,d))
#define fr(i,n)         for (i = 0; i < n;i++)
#define fr1(i,n)        for (i = 1; i <=n;i++)
#define sf(x)           scanf("%lld",&x)
#define pf(x)           printf("%lld",x)
#define tle(x)          ios_base::sync_with_stdio(x),cin.tie(NULL),cout.tie(NULL)
#define add(x,y)        accumulate(x, y, 0);  //v.begin(),v.end()
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

int tree[4000005];

void build(int node,int start,int end)
{
    if(start==end)
        tree[node]=1;
    else
    {
        int mid=(start+end)/2;

        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}

void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
        tree[node]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(idx>=start&&idx<=mid)
            update(2*node,start,mid,idx,val);
        else
            update(2*node+1,mid+1,end,idx,val);

        tree[node]=tree[2*node]+tree[2*node+1];
    }
}


int query(int node,int start,int end,int k,int n)
{
    if(start<1  ||  end>n || tree[node]<k)  //NO OVERLAP
        return -1;

    if(start==end && k==1)
        return start;

    int mid=(start+end)/2;
    int left=tree[2*node];
    if(k>left)
    return query(2*node+1,mid+1,end,k-left,n);
    else
    return query(2*node,start,mid,k,n);

}
int main()
{
    int n,q;
    cin>>n>>q;

    build(1,1,n);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(x==1)
        {
            int c=query(1,1,n,y,n);
            cout<<c<<endl;
        }
        else
            update(1,1,n,y,0);
    }
    return 0;
}
