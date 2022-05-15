const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
const long long INF = 2e18;
 
struct Data {
    long long el = 0;
 
    Data() {};
    Data(long long val) {
        el = val;
    }
    
    void merge(const Data &left, const Data &right) {
        el = left.el + right.el;
    }
};
 
struct update {
    int v = 0; 
    
    update(){};
    update(int val) : v(val) {};
    
    void combine(update &other, const int &tl, const int &tr) {
        v = other.v;         
    }
    
    void apply(Data &x, const int &tl, const int &tr) {
        x.el = 1LL * (tr - tl + 1) * v;
        v=0;
    }
};
 
 
struct segTree {
    int len;
    vector<Data> st;
    vector<update> u;
    vector<bool> lazy;
    Data id_el;
    update id_tr;
 
    segTree(int l) {
        len = l;
        st.resize(4 * len);
        u.resize(4 * len);
        lazy.resize(4 * len);
        id_el = Data();
        id_tr = update();
    }
    
    void propagate(int node, int tl, int tr) {
        if(!lazy[node]) {
            return;
        }
        int tm = tl + (tr - tl) / 2;
        apply(2 * node, tl, tm, u[node]);
        apply(2 * node + 1, tm + 1, tr, u[node]);
        u[node] = id_tr;
        lazy[node] = 0;
    }
    
    void apply(int node, int tl, int tr, update upd) {
        if(tl != tr) {
            lazy[node] = 1;
            u[node].combine(upd, tl, tr);
        }
        upd.apply(st[node], tl, tr);
    }
    
    void build(const vector<int> &arr, int node, int tl, int tr) {
        if(tl == tr) {
            st[node] = Data(arr[tl]);
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(arr, 2 * node, tl, tm);
        build(arr, 2 * node + 1, tm+1, tr);
        st[node].merge(st[2 * node], st[2 * node + 1]);
    }
    
    Data query(int node, int tl, int tr, int l, int r) {
        if(l > tr || r < tl) {
            return id_el;
        }
        if(tl >= l && tr <= r) {
            return st[node];
        }
        propagate(node, tl, tr);
        int tm = tl + (tr - tl) / 2;
        Data a = query(2 * node, tl, tm, l, r), b = query(2 * node + 1, tm+1, tr, l, r), ans;
        ans.merge(a, b);
        return ans;
    }
    
    void rupd(int node, int tl, int tr, int l, int r, update &upd) {
        if(l > tr || r < tl) {
            return;
        }
        if(l <= tl && tr <= r) {
            apply(node, tl, tr, upd);
            return;
        }
        propagate(node, tl, tr);
        int tm = tl + (tr - tl) / 2;
        rupd(2 * node, tl, tm, l, r, upd);
        rupd(2 * node + 1, tm+1, tr, l, r, upd);
        st[node].merge(st[2 * node], st[2 * node + 1]);
    }
    
    void build(const vector<int> &arr) {
        build(arr, 1, 0, len-1);
    }
    Data query(int l,  int r) {
        return query(1, 0, len-1, l, r);
    }
    void rupd(int l, int r, update &upd) {
        rupd(1, 0, len-1, l, r, upd);
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    segTree sgt(n);
    sgt.build(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            update upd(x);
            sgt.rupd(i, i, upd);
        }
        else {
            int x;
            cin >> x;
            update upd(x);
            sgt.rupd(0, n - 1, upd);
        }
        cout << sgt.query(0, n - 1).el << "\n";
    }
}
