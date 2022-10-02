class Solution {
public:
    const int mod=1e9+7;
const int N=3e5+4;
// #define mod 998244353
#define  PI 3.14159265            
//#define int long long
        
#define ll long long
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
    
    
    
    
    struct StringHash {
  string S;
  int N;

  const long long p = 31;
  const long long M = 1e9 + 9;
  //hash[i] stores hashv alue for substring 0.....i;
  vector<long long> hash, compute_pow, inv_pow;

  StringHash(string str) {
    //take argument string
    S = str;
    N = str.size();
    hash.resize(N);
    compute_pow.assign(N + 10, 1);
    inv_pow.assign(N, 1);

    run_hash();

  }

  //TODO: define int long long or use long long separately
  void run_hash() {
    hash[0] = (S[0] - 'a' + 1) % M;
    compute_pow[1] = p;
      
    for(int i = 1; i < N; i++) {
      compute_pow[i] = (compute_pow[i - 1] * p) % M;
      inv_pow[i] = my_pow(compute_pow[i], M - 2);
      hash[i] = (hash[i - 1] + (S[i] - 'a' + 1) * compute_pow[i]) % M;
    }
  }

  long long my_pow(int a, int b) {
    if(b == 0)
      return 1;
    long long r = my_pow(a, b / 2);
    r = (r * r) % M;
    if(b % 2)
      r = (r * a) % M;
    return r;
  }

  //return hash value of string between indices i and j
  long long get_hash(int i, int j) {
    long long res = (hash[j] - (i > 0 ? hash[i - 1] : 0) + M) % M;
    long long Q = inv_pow[i];
    return (res * Q) % M;
  }
};
    ll dp[40005];
    ll n;
    ll rec(ll ind,string &s,StringHash &sh)
    {
        if(ind>=n)return 0;
        ll &ans=dp[ind];
        if(ans!=-1)return ans;
        ll cnt=0;
        string st;
        ans=1;
        for(ll i=ind;i<n;i++)
        {
            cnt++;
           if((ind+cnt+cnt-1<n) and sh.get_hash(ind,ind+cnt-1)==sh.get_hash(ind+cnt,ind+cnt+cnt-1))
           {
               //cout<<" jjxn "<<ind<<"  "<<ind+cnt<<endl;
               ans=max(ans,1+rec(ind+cnt,s,sh));
            
            
           }
            
        }
        return ans;
        
    }
    int deleteString(string s) {
        n=s.size();
        memset(dp,-1,sizeof(dp));
        StringHash sh(s);
        return rec(0,s,sh);
    }
};
