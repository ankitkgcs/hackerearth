
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define fr(i,l,n) for(int i=l;i<=n;++i)
#define fre(i,l,n) for(int i=l;i<n;++i)
#define rko(t) int t; cin>>t; while(t--)
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
template<typename T>
inline T max( T a, T b, T c ) { return max( max(a,b), c ) ; }
template<typename T>
inline T max( T a, T b, T c, T d ) { return max( max(a,b), max(c,d) ) ; }
template<typename T>
inline T min( T a, T b, T c ) { return min( min(a,b), c ) ; }
template<typename T>
inline T min( T a, T b, T c, T d ) { return min( min(a,b), min(c,d) ) ; }
ll power(ll a,ll n,ll m){a=a%m;ll r=1;
while(n>0){
if(n%2==1)
r=r*a%m;
a=a*a%m;n=n/2;
}return r;}
template <typename T> void scan(T &x) {
	T c = getchar_unlocked(); while(((c < 48) || (c > 57)) && (c!='-')) c = getchar_unlocked();
	bool neg = false; if(c == '-') neg = true; x = 0; for(;c < 48 || c > 57;c=getchar_unlocked());
	for(;c > 47 && c < 58;c=getchar_unlocked())	x = (x*10) + (c - 48); if(neg)	x = -x;
}
/*****************************************************************************************************************************************************
********************      code goes here   **********************************************************************************************
*****************************************************************************************************************************************************/
ll a[1000005];ll ans,temp;
stack <int> s;
int main() { //std::ios::sync_with_stdio(false);                // don't use scanf & printf
int t;scan(t);
while(t--){
    ans=0;
    int n;scan(n);
    fre(i,0,n)scan(a[i]);
    n++;
    a[n-1]=0;
    s.push(0);
    fre(i,1,n)
    {
        while(!s.empty() && a[s.top()]>a[i])
        {
            int top=s.top();
            s.pop();
                if(s.empty()){
                    temp=a[top]*i;

                }
                else{
                    temp=a[top]*(i-s.top()-1);

                }
                ans=max(ans,temp);
        }
        s.push(i);
    }
    printf("%lld\n",ans);
    while(!s.empty())
        s.pop();

}


   return 0;
}
