/**
 * Minimum Odd Cycle Removal / Max Bipartite Subgraph (Fuerza Bruta Bitmask):
 * Cantidad mínima de aristas que se deben eliminar para hacer el grafo bipartito.
 * Equivale a encontrar una partición de nodos en dos conjuntos A y B que minimice las aristas monocromáticas:
 * - Se itera sobre todas las 2^n asignaciones de color usando una máscara de bits j in [0, 2^n - 1].
 * - Para cada arista (u, v), si ambos extremos comparten el mismo color (((j >> u) & 1) == ((j >> v) & 1)),
 *   la arista es inválida en el grafo bipartito y debe removerse (cont++).
 * - La respuesta es el mínimo de aristas conflictivas sobre todas las particiones posibles.
 * Complejidad: O(m * 2^n), viable para n <= 20.
 */
 
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  //vector<vector<int>> gr(n);
  //vector<int> c(n,0);
  int cont;
  int ans = m+1;
  vector<vector<int>> gr(m, vector<int>(2));
  for(int i = 0; i < m; i++){
    int v, u;
    cin >> v >> u;
    gr[i][0] = v--; gr[i][1] = u--;
  }
  for(int j = 0; j < (1<<n); j++){
   cont = 0;
   for(int i = 0; i < m; i++){
      int u = gr[i][0];
      int v = gr[i][1];
      //gr[u].push_back(v);
      //gr[v].push_back(u);
       if(((j >> u) & 1) == ((j >> v) & 1)){
        cont++;
      }
    }
    ans = min(cont, ans);
  }
  cout << ans << '\n';
}