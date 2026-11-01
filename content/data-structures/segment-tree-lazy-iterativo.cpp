/*
 *Descripción:* Segment tree con propagación lazy, pero iterativo. Construcción $O(n)$, consultas y updates $O(log n)$
*/
template<class T1,class T2,T1 merge(T1&,T1&),void applyUpd(T1&,T2&,int), void pushUpd(T2&,T2&,int)>
struct segment_tree_lazy {
  int n,h; vector<T1> st; vector<T2> lazy;
  segment_tree_lazy(vector<T1> & a){
    n = sz(a); h = sizeof(int)*8-__builtin_clz(n);
    st.resize(n<<1); lazy.resize(n);
    for (int i = 0; i < n; i++) st[n+i] = a[i];
    for (int i = n-1; i > 0; i--) st[i] = merge(st[i<<1],st[i<<1|1]);
  }
  void calc(int pos, int len){
    if (lazy[pos].upd()) applyUpd(st[pos],lazy[pos],len);
    else st[pos] = merge(st[pos<<1],st[pos<<1|1]);
  }
  void apply(int pos, T2 val, int len){
    applyUpd(st[pos],val,len);
    if (pos < n) pushUpd(val,lazy[pos],len);
  }
  void build(int l, int r){
    int len = 2;
    for (l += n, r += n-1; l > 1; len <<= 1){
      l >>= 1, r >>= 1;
      for (int i = r; i >= l; i--)
        calc(i,len);
    }
  }
  void push(int l, int r){
    int s = h, len = 1<<(h-1);
    for (l += n, r += n-1; s > 0; s--, len >>= 1)
      for (int i = l>>s; i <= r>>s; i++) if (lazy[i].upd()){
        apply(i<<1,lazy[i],len);
        apply(i<<1|1,lazy[i],len);
        lazy[i] = T2();
      }
  }
  void update(int l, int r, T2 val){
    push(l,l+1); push(r,r+1);
    bool cl = 0, cr = 0; int len = 1;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1, len <<= 1){
      if (cl) calc(l-1,len);
      if (cr) calc(r,len);
      if (l&1) apply(l++,val,len), cl = 1;
      if (r&1) apply(--r,val,len), cr = 1;
    }
    for (--l; r > 0; l >>= 1, r >>= 1, len <<= 1){
      if (cl) calc(l,len);
      if (cr && (!cl || l != r)) calc(r,len);
    }
  }
  T1 query(int l, int r){
    push(l,l+1); push(r,r+1);
    T1 ansL, ansR; bool hasL = 0,hasR = 0;
    for (l += n, r += n+1; l < r; l >>= 1, r >>= 1){
      if (l&1) ansL = (hasL?merge(ansL,st[l++]):st[l++]), hasL = 1;
      if (r&1) ansR = (hasR?merge(st[--r],ansR):st[--r]), hasR = 1;
    }
    if (!hasL) return ansR; if (!hasR) return ansL;
    return merge(ansL,ansR);
  }
};
/* ejemplo de uso */
struct lz {
  ll val;
  lz(){ val = 0; }
  bool upd(){ return (val != 0); }
};
ll merge(ll & a, ll & b){
  return a+b;
}
void applyUpd(ll & v, lz & u, int len){
  v += u.val*len;
}
void pushUpd(lz & u1, lz & u2, int len){
  u2.val += u1.val;
}
