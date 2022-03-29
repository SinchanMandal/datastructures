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
        tree[v] = tree[v*2] + tree[v*2+1];
    }
}
ll query(ll u, ll st, ll en, ll l, ll r) {
 
    if (r<st || l>en)  return INF; //out of range      
    else if (l<=st && en<=r)    {// complete in range
        return tree[u];
    }
    else {
        ll mid = (st+en)/2;
        return combine(query(2*u, st, mid, l, r), query(2*u+1, mid+1, en, l, r));
    }
}
