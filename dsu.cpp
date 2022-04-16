ll p[N],n,szz[N],m,k;
void make(ll n)
{
    for(ll i=1;i<=n;i++)
    {p[i]=i;szz[i]=1;
    }
    return ;
}
ll find(ll x)
{
   if(p[x]==x)return x;
		return p[x]=find(p[x]);
}
ll merge(ll a,ll b)
{
    ll x=find(a);
    ll y=find(b);
    
      if(x!=y)
	    {
			if(szz[x]<szz[y])swap(x,y);
			p[y]=x;
			szz[x]+=szz[y];
          return 1; 
         }
     
        return 0; 
}
