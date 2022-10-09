 #include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=3e5+4;
// #define mod 998244353
#define  PI 3.14159265            
#define int long long
        
#define ll long long
#define int long long
#define ld  double
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define pb   push_back
#define sz(x) (ll)x.size()
#define mp   make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define pi pair<ll,ll>
const int64_t INF = 100000000000000018LL;
ll a[N],n,k;
ll check(ll mid)
{
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
     sum+= min(a[i],mid);
    }
return sum>=mid*k;
}
void solve()
{
    
   
    cin>>n>>k;
    ll i;
    for(i=1;i<=n;i++)cin>>a[i];
    ll l=0,r=1e12,ans=0,mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
        r=mid-1;
    }
    cout<<ans;
}


 
 
signed main()
{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   long long t=1;
//cin >> t;
   while(t--)
   {solve();
   }
}
 
