/*
 CSES Counting Rooms: Contar componentes conexas en una grilla 2D.
 Cada habitación es una componente de casillas libres ('.'):
 - Itera sobre el mapa y, al encontrar un '.', dispara BFS para inundar la sala.
 - Marca las casillas visitadas mutándolas a '#' (pared) in-place para ahorrar memoria.
 Complejidad: O(n * m) tiempo y memoria.
*/

void bfs(int ii, int jj, vector<vector<char>> &room) {
  queue<vector<int>> bfs;
  room[ii][jj]='#'; //visited
  bfs.push({ii,jj});
  while(!bfs.empty()){
    vector<int> nodo = bfs.front();
    bfs.pop();
    int i = nodo[0], j = nodo[1];
    if (i>0 and room[i-1][j]!='#'){
      bfs.push({i-1,j});
      room[i-1][j]='#';
    }
    if (i<n-1 and room[i+1][j]!='#'){
      bfs.push({i+1,j});
      room[i+1][j]='#';
    }
    if (j>0 and room[i][j-1]!='#'){
      bfs.push({i,j-1});
      room[i][j-1]='#';
    }
    if (j<m-1 and room[i][j+1]!='#'){
      bfs.push({i,j+1});
      room[i][j+1]='#';
    }
  }
}

signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  vector<vector<char>> room(n,vector<char>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      cin>>room[i][j];
    }
  }
  int count = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      if (room[i][j] == '.') {
        bfs(i,j,room);
        count++;
      }
    }
  }
  cout << count << '\n';
	return 0;
  cout << "haiii slayy ^^" << '\n'; 
}