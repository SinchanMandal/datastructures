
class Solution {
public:
    const int N=2e5;
#define mod 998244353
#define PI 3.14159265            
        
#define ll int
//#define int long long
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
vector<ll>graph[100005];
ll cnt=0;
vector<pi>ans;
ll tin[100005],low[100005],visited[100005];
    vector<vector<ll>>yo;
void dfs(ll ind,ll par,ll &timer)
{   visited[ind]=1;
    tin[ind]=low[ind]=timer++;
    for(auto it:graph[ind])
    {
        if(it==par)continue;
        if(!visited[it])
        {
            dfs(it,ind,timer);
            if(low[it]>tin[ind])
            {
               yo.pb({it,ind});
            }
           
            low[ind]=min(low[ind],low[it]);
        }
        else
        {
            low[ind]=min(low[ind],low[it]);
           
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        ll i,nn=sz(connections);
        for(i=0;i<nn;i++)
        {
            graph[connections[i][0]].pb(connections[i][1]);
            graph[connections[i][1]].pb(connections[i][0]);
        }
        int timer=0;
        dfs(1,-1,timer);
        return yo;
    }
};
