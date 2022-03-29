#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
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

ll n,q;
ll a[N],aa[N],val[N];
ll tree[4*200000+5];
vector<ll>graph[N];
ll tin[N],tout[N],ft[2*N];
ll timer=1;
ll level[N];
void dfs(ll ind,ll p)
{
    tin[ind]=timer;
    ft[timer]=ind;
    timer++;

    for(auto it:graph[ind])
    {  if(it!=p)
        dfs(it,ind);
    }
    
    tout[ind]=timer-1;
    ft[timer]=ind;
   
}


ll combine(ll left,ll right)
{
    return __gcd(left,right);
}
void build(ll ind,ll st,ll en)
{
    if(st==en)
    {
        tree[ind]=a[st];
        return;
    }
    else
    {
        ll mid=(st+en)/2;
        build(2*ind,st,mid);
        build(2*ind+1,mid+1,en);
        tree[ind]=combine(tree[2*ind],tree[2*ind+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        tree[v] = combine(tree[v*2] , tree[v*2+1]);
    }
}
ll query(ll u, ll st, ll en, ll l, ll r) {
 
    if (r<st || l>en)  return 0; //out of range      
    else if (l<=st && en<=r)    {// complete in range
        return tree[u];
    }
    else {
        ll mid = (st+en)/2;
        return combine(query(2*u, st, mid, l, r), query(2*u+1, mid+1, en, l, r));
    }
}
void solve()
{
   cin>>n>>q;ll i;
   for(i=1;i<=n;i++)
   {
       cin>>aa[i];
   }
   for(i=1;i<=n-1;i++)
   {   ll x,y;
       cin>>x>>y;
       graph[x].pb(y);
       graph[y].pb(x);
   }
   ll lev=0;
   dfs(1,-1);
   for(i=1;i<=n;i++)
   {
       a[tin[i]]=aa[i];
   }
//   for(i=1;i<=n;i++)
//   {
//       cout<<tin[i]<<" ";
//   }
//   cout<<endl;
//   for(i=1;i<=n;i++)
//   {
//       cout<<ft[i]<<" ";
//   }
//   cout<<endl;
   build(1,1,n);
   ll type,x,val;
   for(i=1;i<=q;i++)
   {
       cin>>type;
       if(type==1)
       {
           cin>>x>>val;
           update(1,1,n,tin[x],val);
           
       }
       else
       {
           cin>>x;
         //  cout<<tin[x]<<" "<<tout[x]<<endl;
           ll ans=query(1,1,n,tin[x],tout[x]);
           cout<<ans<<endl;
       }
   }
} 
 
 
signed main()
{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   long long t=1;
//cin >> t;
   while(t--)
   {solve();
   }
}
 
