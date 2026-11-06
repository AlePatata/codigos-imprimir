/*
 STL
 (ICPC 2025)
 Emergency Rations: Tienes cajas con fecha de vencimiento que puedes botar o comer.
 Cada query agrega o quita una caja y te pide el mínimo de días para sobrevivir.
 Se resuelve con ST Lazy: inicializas el arreglo con f(i) = i (días base) y cada caja 
 hace un update de +1 o -1 en un prefijo [0, a-1]. La respuesta es el min global.
*/

// busco el mínimo de días
// asi q toca un stlazy de minimos i guess
ll merge(ll a, ll b) {
  return min(a,b);
}

// lo que guardamos de forma lazy en el rango
void pushUpd(ll &a, ll &b, int pl, int pr, int cl, int cr) {
  b+=a;
}

// aplicacion del upd a cada hijo
void applyUpd(ll &a, ll &b, int l, int r){
  b+=a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  ll n; cin>>n;
  // días mínimos q tardo
  vector<ll> dias(n+1);
  for(int i=0;i<=n;i++){
    // días base q me demoro en botar cajas
    dias[i] = i;
  }
  segment_tree_lazy<ll,ll,merge,pushUpd,applyUpd> st(dias);
  for (int i=0;i<n;i++) {
    ll a; cin>>a;
    // no puedo demorarme más de n días, q sería simplemente
    // kitar la fakin caja
    a = min(a,n);
    if (a>0) {
      st.update(0,a-1,1);
    } else {
      st.update(0,abs(a)-1,-1);
    }
    cout << st.query(0,n) << ' ';
  }
  cout << '\n';
	return 0;
  cout << "life update: we are so back\n";
}
