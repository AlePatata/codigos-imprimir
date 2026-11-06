
void solve(int cont) {
  int n; cin>>n;
  // leer el \n del n anterior 
  string ignorar; getline(cin,ignorar);
  vector<vector<int>> frases(n);
  map<string,int> id;
  int aa = 0;
  for (int i=0;i<n;i++){
    string l; getline(cin,l);
    stringstream stream(l);
    // mapear¿¿¿
    string s;
    while(stream>>s){
      if (!id.count(s)) id[s] = aa++;
      frases[i].push_back(id[s]);
    }
  }
  // costo hacerla bilinweee
  Dinic d(n+2*aa);
  for(int i=0;i<aa;i++){
    int u = n+2*i, v = n+2*i+1;
    d.addEdge(u,v,1);
  }
  for (int i=0;i<n;i++){
    for (auto w: frases[i]){
      int u = n+2*w, v = n+2*w+1;
      d.addEdge(i,u,LIM);
      d.addEdge(v,i,LIM);
    }
  }
  int s = 0, t = 1;
  cout << "Case #" << cont << ": " << d.calc(s,t) << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  // descomentar en casos múltiples
  cin>>t;
  int cont = 1;
  while (t--) {
    solve(cont);
    cont++;
  }
	return 0;
  cout << "life update: we are so back" << '\n';
}
