/*
 *Descripción:* Rota una matriz $n times n$
 *Complejidad:* $O(n^2)$
*/

template <class T>
void rotate(vector<vector<T>> &a) {
  int n = sz(a);
  vector<vector<T>> mat(n, vector<T>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = a[n - 1 - j][i]; // horario
      //mat[i][j] = a[j][n - 1 - i]; // antihorario
    }
  }
  swap(a, mat);
}

