/*
 Ilya and Queries (CF 313B): Contar pares consecutivos iguales s[i] == s[i-1] en rangos [l, r].
 Sumas prefijas 1D directas:
 - pref[i] guarda la cantidad acumulada de parejas iguales hasta el índice i.
 - Para el rango 1-indexado [l, r] (convertido a 0-indexado l, r), la cantidad de pares s[i] == s[i-1] que caen estrictamente dentro del rango es pref[r] - pref[l].
 Complejidad: O(|s|) build, O(1) por query.
*/

void solve(){
  string s; cin>>s;
  vector<int> pref(sz(s),0);
  for(int i=1;i<sz(s);i++){
    if (s[i]==s[i-1]) pref[i] = pref[i-1]+1;
    else pref[i] = pref[i-1];
  }
  int q; cin>>q;
  while(q--){
    int l,r; cin>>l>>r; l--;r--;
    cout << pref[r]-pref[l] << '\n';
  }
}