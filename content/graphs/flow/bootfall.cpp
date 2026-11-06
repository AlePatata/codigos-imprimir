/**
 * Just Bootfall: Asignar a cada jugador una posición [0, m-1] para maximizar la habilidad total menos penalizaciones por desacuerdo entre amigos.
 * Problema clásico de Project Selection / Image Segmentation modelado como Min-Cut:
 * - Se transforma a minimización invirtiendo la ganancia: costo = LIM - pos[i][j].
 * - Cada jugador i se modela como una cadena de m-1 nodos entre S y T:
 *   S -> id[i][0] -> id[i][1] -> ... -> id[i][m-2] -> T.
 *   Cortar la j-ésima arista de la cadena equivale a elegir la posición j para el jugador i.
 * - Amigos (u, v): aristas bidireccionales de capacidad c entre id[u][j] e id[v][j] para penalizar
 *   si quedan en lados opuestos del corte (posiciones distintas).
 * - Respuesta final: n * LIM - MinCut(S, T).
 * Complejidad: O(Dinic(V, E)) con V ≈ n * m, E ≈ n * m + k * m.
 */

// dinic
void solve() {
  int n,m,k,c; cin>>n>>m>>k>>c;
  if (m==1) {
    ll ans = 0;
    for (int i=0;i<n;i++){
      ll x; cin>>x;
      ans+=x;
    }
    cout << ans << '\n';
    return;
  }
  vector<vector<int>> pos(n,vector<int> (m)),
    id(n,vector<int> (m));
  int cnt = 1;
  // s = 0
  // posiciones: cada arista es una posicion
  // y hay n por m posiciones
  // => n*(m-1)
  // t = n*(m-1) + 1
  int t = n*(m-1) + 1;
  Dinic d(t+1);
  // construir los nodos de cada jugador
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++) {
      cin>>pos[i][j];
      if (j==0){id[i][j] = cnt++; d.addEdge(0,id[i][j],LIM-pos[i][j]);}
      else if (j==m-1) d.addEdge(id[i][j-1],t,LIM-pos[i][j]);
      else {
        id[i][j] = cnt++;
        d.addEdge(id[i][j-1], id[i][j], LIM-pos[i][j]);
      }
    }
  }
  // besties
  for (int i=0;i<k;i++){
    int u,v; cin>>u>>v; u--; v--;
    for (int j=0;j<m-1;j++){
      d.addEdge(id[u][j], id[v][j], c, c);
    }
  }
  cout << (ll)n*LIM - d.calc(0,t) << '\n';
}