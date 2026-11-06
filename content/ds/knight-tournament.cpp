/*
 Knight Tournament (CF 356A): Quién derrota a cada caballero procesando peleas al revés.
 Como el último que derrota a un caballero es quien define su asesino definitivo:
 - Se invierten las queries y se hace rango assignment (set) con el ganador x en [l, x-1] y [x+1, r].
 - El que gana una pelea pisa a los anteriores; al final cada hoja i tiene su asesino (o 0 si nunca perdió).
 Complejidad: O((n + q) log n) con ST Lazy (o O(n + q * alpha) con DSU).
*/

int merge(int a, int b) {
  return a;
}

// lo que guardamos de forma lazy en el rango
void pushUpd(int &a, int &b, int pl, int pr, int cl, int cr) {
  b = a;
}

// aplicacion del upd a cada hijo
void applyUpd(int &a, int &b, int l, int r){
  b = a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int n,q; cin>>n>>q;
  vector<int> knights(n,0);
  segment_tree_lazy<int,int,merge,pushUpd,applyUpd> st(knights);
  vector<pii> queries(q);
  for (int i=0;i<q;i++)
    cin>>queries[i][0]>>queries[i][1]>>queries[i][2];
  reverse(queries.begin(),queries.end());
  for (auto [l,r,x]: queries){
    l--; r--; x--;
    st.update(l,x-1,x+1);
    st.update(x+1,r,x+1);
  }
  for (int i=0;i<n;i++){
    cout << st.query(i,i) << ' ';
  }
  cout << '\n';
	return 0;
  cout << "life update: we are so back\n";
}
