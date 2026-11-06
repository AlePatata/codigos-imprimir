/*
 Sumas prefijas 2D con principio de inclusión-exclusión:
 - Build: pref[i][j] = (a[i-1][j-1] == '*') + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1].
 - Query (x1, y1) a (x2, y2): pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1].
 Complejidad: O(n^2) build, O(1) por query.
*/ 

void solve(){
  int n,q; cin>>n>>q;
  vector<string> a(n);
  for (auto &x:a) cin>>x;
  vector<vector<int>> pref(n+1, vector<int> (n+1));
  for (int i=1;i<n+1;i++){
    for (int j=1;j<n+1;j++){
      pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
      if (a[i-1][j-1] == '*') pref[i][j]++;
    }
  }
  while(q--){
    int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
    cout << pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1] << '\n';
  }
}