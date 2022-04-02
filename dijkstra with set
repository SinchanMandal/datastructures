#include <bits/stdc++.h>
using namespace std;
const int m=1e9+7;
const int N=2e5+69;
#define mod 998244353
#define PI 3.14159265            
   //     https://atcoder.jp/contests/abc246/tasks/abc246_e
#define ll long long
#define ld long double
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
#define mems(x,v)       memset(x,v,sizeof(x))                      

///////////////////////////////// 
#define Toggle(n,i) (n^((ll)1<<i))
#define Check(n,i) (n&((ll)1<<i))
#define Set(n,i) (n|((ll)1<<i))
#define Reset(n,i) (n&(~((ll)1<<i)))
////////////////////////////////

//stack top hota h,queue front hota h
char a[1505][1505];
vector<vector<int>>dirs={{1,1},{1,-1},{-1,1},{-1,-1}};
ll visited[1505][1505][4],n;
ll inline check(ll i,ll j)
{
    if(i<1 or j<1 or i>n or j>n)
    return 0;
    if(a[i][j]=='#')
    return 0;
    return 1;
}
void solve()
{
 // priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>>pq;
 set<vector<ll>>pq;
  ll i,j;
  cin>>n;
  ll x1,y1,x2,y2;
  cin>>x1>>y1;
  cin>>x2>>y2;
  for(i=1;i<=n;i++)
  {
      for(j=1;j<=n;j++)
      {
          cin>>a[i][j];
      }
  }
  for(i=0;i<4;i++)
  {
      
      
          ll ind1=x1+dirs[i][0];
          ll ind2=y1+dirs[i][1];
          if(check(ind1,ind2))
          pq.insert({1,ind1,ind2,i});
      
  }
  
  while(!pq.empty())
  {
      vector<ll>v=*pq.begin();
      pq.erase(pq.begin());
      ll x=v[1];
      ll y=v[2];
      ll f=v[3];
     // cout<<x<<" "<<y<<endl;
      if(x==x2 and y==y2)
      { cout <<v[0];
      return;
      }
      if(visited[x][y][f]==1)continue;
      visited[x][y][f]=1;
      for(i=0;i<4;i++)
      {
          ll ind1=x+dirs[i][0];
          ll ind2=y+dirs[i][1];
          if(check(ind1,ind2))
          {
              if(i==f)
              pq.insert({v[0],ind1,ind2,i});
              else
              {
                    pq.insert({1+v[0],ind1,ind2,i});
              }
          }
      }
  }
  cout<<-1;
}
int main()
{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   long long t=1;
//cin >> t;
   while(t--)
   {solve();
   }
}
