/*
 STL
 1. Increase each value in range [a,b] by x.
 2. Set each value in range [a,b] to x.
 3. Calculate the sum of values in range [a,b]. 
*/

ll merge(ll a, ll b) {
  return a+b;
}

// lo que guardamos de forma lazy en el rango
void pushUpd(pii &a, pii &b, int pl, int pr, int cl, int cr) {
  if (a[1]) {
    b[1] = a[1];
    b[0] = a[0];
  } else {
    if (b[1]) b[1]+=a[0];
    else b[0]+=a[0];
  }
}

// aplicacion del upd a cada hijo
void applyUpd(pii &a, ll &b, int l, int r){
  if (a[1]) {
    b=(a[0]+a[1])*(r-l+1);
  } else {
    b+=a[0]*(r-l+1);
  }
}

void solve() {
  int n,q; cin>>n>>q;
  vector<ll> a(n);
  for (auto &x:a) cin>>x;
  segment_tree_lazy<ll,pii,merge,pushUpd,applyUpd> st(a);
  while(q--){
    int t; cin>>t;
    if (t==1){
      int a,b,x; cin>>a>>b>>x; a--;b--;
      st.update(a,b,{x,0});
    } else if (t==2) {
      int a,b,x; cin>>a>>b>>x; a--;b--;
      st.update(a,b,{0,x});
    } else {
      int a,b; cin>>a>>b; a--;b--;
      cout << st.query(a,b) << '\n';
    }
  }
}