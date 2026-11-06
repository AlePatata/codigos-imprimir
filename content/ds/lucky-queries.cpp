/*
 STL
 Lucky Queries (CF 145E): LIS no decreciente sobre string de 4 y 7 con switch en rangos.
 Cada nodo guarda [cnt4, cnt7, lis47, lds74]:
 - lis47 = max(cnt4_izq + lis47_der, lis47_izq + cnt7_der) (patrón 4..47..7).
 - El update en rango invierte los caracteres (4 a 7 y viceversa) usando XOR en el lazy:
 se swappean cnt4 con cnt7 y lis47 con lds74. La respuesta es la raiz en lis47.
*/

// [c4, c7, c47, c74]
pii merge(pii a, pii b) {
  pii ans;
  ans[0] = a[0] + b[0];
  ans[1] = a[1] + b[1];
  ans[2] = max(a[0]+b[2], a[2]+b[1]);
  ans[3] = max(a[1]+b[3], a[3]+b[0]);
  return ans;
}

// lo que guardamos de forma lazy en el rango
void pushUpd(int &a, int &b, int pl, int pr, int cl, int cr) {
  b ^= a;
}

// aplicacion del upd a cada hijo
void applyUpd(int &a, pii &b, int l, int r){
  if (a) {
    swap(b[0],b[1]);
    swap(b[2],b[3]);
  }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int n,q; cin>>n>>q;
  string s; cin>>s;
  vector<pii> a(n);
  for (int i=0;i<n;i++){
    if (s[i] == '4') {
      a[i] = {1,0,1,1};
    } else {
      a[i] = {0,1,1,1};
    }
  }
  segment_tree_lazy<pii,int,merge,pushUpd,applyUpd> st(a);
  while(q--){
    string t; cin>>t;
    if (t[0] == 'c') {
      cout << st.query(0,n-1)[2] << '\n';
    } else {
      int l,r; cin>>l>>r; l--; r--;
      st.update(l,r,1);
    }
  }
	return 0;
  cout << "life update: we are so back\n";
}